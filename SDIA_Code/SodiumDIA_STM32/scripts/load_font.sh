export FONT_H_PATH="Core/Src/font/font.c"
export FONT_PNG_PATH="../res/Font1.png"

source ../.venv/Scripts/activate

python ../image_parser/font_to_bitmap.py "$FONT_PNG_PATH" "$FONT_H_PATH"

deactivate