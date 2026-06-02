from PIL import Image
from bitarray import bitarray
import numpy as np
import argparse

verbose = False

def png_parse(source_path : str, target_path : str, force : bool):
    
    source_img = Image.open(source_path)
    
    source_array = np.array(source_img)

    array_out = bitarray()

    shape = source_array.shape

    for i in range(shape[0]):
        array_row = bitarray()
        for j in range(shape[1]):
            pixel = source_array[i, j]
            array_row.append((pixel == [255, 255, 255, 255]).all())
        print(array_row)
        array_out += array_row
            

    with open(target_path, 'wb') as f:
        array_out.tofile(f)
    
    pass

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
        png_parse(args.source, args.target, args.force)

if __name__ == "__main__":
    main()
