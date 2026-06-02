from hmac import new

from PIL import Image
from bitarray import bitarray
import numpy as np
import argparse

verbose = False

def font_parse(source_path : str, target_path : str, force : bool, font_size : tuple[int, int]):
    
    source_img = Image.open(source_path)
    
    source_array = np.array(source_img)

    offset_x = 0
    offset_y = 0

    array_out = bitarray()

    shape = source_array.shape
    height = shape[0]
    length = shape[1]

    row_len = int(length / font_size[1])
    col_len = int(height / font_size[0])

    for i in range(col_len):
        for j in range(row_len):
            offset_x = j * font_size[1]
            offset_y = i * font_size[0]

            for rel_y in range (font_size[0]):
                array_row = bitarray()
                for rel_x in range (font_size[1]):
                    pixel = source_array[offset_y + rel_y, offset_x + rel_x]
                    # print(pixel)
                    array_row.append((pixel == [255, 255, 255, 255]).all())
                print(array_row)
                array_out += array_row

    with open(target_path, 'wb') as f:
        array_out.tofile(f)
    
    pass

def font_parse_to_h(source_path : str, target_path : str, force : bool, font_size : tuple[int, int]):
    
    source_img = Image.open(source_path)
    
    source_array = np.array(source_img)

    offset_x = 0
    offset_y = 0

    array_out = bitarray()

    shape = source_array.shape
    height = shape[0]
    length = shape[1]

    row_len = int(length / font_size[1])
    col_len = int(height / font_size[0])

    for i in range(col_len):
        for j in range(row_len):
            offset_x = j * font_size[1]
            offset_y = i * font_size[0]

            for rel_y in range (font_size[0]):
                array_row = bitarray()
                for rel_x in range (font_size[1]):
                    pixel = source_array[offset_y + rel_y, offset_x + rel_x]
                    # print(pixel)
                    array_row.append((pixel == [255, 255, 255, 255]).all())
                array_out += array_row


    define_fontsize_line = f"#define FONT_SIZE {int(len(array_out) / 8 + 1)}"
    # define_fontsize_line = f"#define FONT_SIZE {len(array_out)}"
    newline = "const uint8_t FONT[FONT_SIZE] __attribute__((section(\".text\"), aligned(16))) = {"    

    # for i in range(0, 9*9*8, 8):
    for i in range(0, len(array_out), 8):
        byte = array_out[i:i+8]

        byte_value = 0
        for bit in byte:
            byte_value = (byte_value << 1) | bit

        literal = f"0x{byte_value:02X}"

        newline += literal

        if i + 8 < len(array_out):
            newline += ", "

    newline += "};"

    replace_marker_block(target_path, [define_fontsize_line, newline])

    pass

def replace_marker_block(file_path, new_lines):
    # Read the original file contents
    with open(file_path, 'r', encoding='utf-8') as file:
        lines = file.readlines()

    output_lines = []
    inside_block = False
    marker_found = False

    for line in lines:
        # Strip whitespace to catch markers even if they are indented
        stripped_line = line.strip()

        print(f"Processing line: \"{stripped_line}\"")  # Debugging output

        if stripped_line == "// FONT BEGIN":
            inside_block = True
            marker_found = True
            output_lines.append(line)  # Keep the start marker line
            
            # Add the new custom lines right after the start marker
            for new_line in new_lines:
                # Add a newline character if it isn't already there
                if not new_line.endswith('\n'):
                    new_line += '\n'
                output_lines.append(new_line)
            continue

        if stripped_line == "// FONT END":
            inside_block = False
            output_lines.append(line)  # Keep the end marker line
            continue

        # If we are not inside the block, preserve the existing file code
        if not inside_block:
            output_lines.append(line)

    if not marker_found:
        print("Warning: '// FONT START' marker was not found in the file.")
        return

    # Write the modified content back to the file
    with open(file_path, 'w', encoding='utf-8') as file:
        file.writelines(output_lines)
    print("File updated successfully!")

def main():
    # 1. Create the parser
    parser = argparse.ArgumentParser(description="Парсер .png -> bin")

    # Positional arguments (required)
    parser.add_argument("source", help="Исходное изображение")
    parser.add_argument("target", help="Имя изображения на выходе")

    # Boolean flags
    parser.add_argument("-f", "--force", action="store_true", help="Перезаписывать существующие файлы")

    parser.add_argument("-v", "--verbose", action="store_true", help="Подробный вывод")

    # 3. Parse the arguments
    args = parser.parse_args()

    # 4. Use the arguments
    if args.verbose:
        global verbose
        verbose = True

    if args.source and args.target:
        font_parse_to_h(args.source, args.target, args.force, (9,9))

if __name__ == "__main__":
    main()
