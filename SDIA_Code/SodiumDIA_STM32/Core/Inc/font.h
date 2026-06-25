#ifndef FONT_H
#define FONT_H
#endif

#define FONT_HEIGHT 9
#define FONT_WIDTH 9
#define CHAR_BITLENGTH (FONT_HEIGHT * FONT_WIDTH)
#define BORDER_X 1
#define BORDER_Y 3
#define ROW_LENGTH 14

#include <stdint.h>
#include "st7735.h"

extern uint8_t character[FONT_HEIGHT][FONT_WIDTH];
extern const uint8_t FONT[];

uint8_t load_character(uint8_t character_code);
uint8_t draw_loaded_character(uint16_t cStart, uint16_t rStart, uint16_t color, uint16_t bg_color);
uint8_t draw_character(uint16_t cStart, uint16_t rStart, uint8_t character_code, uint16_t color, uint16_t bg_color);
uint8_t draw_character_in_grid(uint16_t x, uint16_t y, uint8_t character_code, uint16_t color, uint16_t bg_color);
uint8_t draw_string_in_grid(uint16_t x, uint16_t y, char *string, uint16_t color, uint16_t bg_color);