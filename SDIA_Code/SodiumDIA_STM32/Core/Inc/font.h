#ifndef FONT_H
#define FONT_H
#endif

#define FONT_HEIGHT 9
#define FONT_WIDTH 9
#define CHAR_BITLENGTH (FONT_HEIGHT * FONT_WIDTH)

#include <stdint.h>
#include "st7735.h"

extern uint8_t character[FONT_HEIGHT][FONT_WIDTH];
extern const uint8_t FONT[];

uint8_t load_character(uint8_t character_code);
uint8_t draw_loaded_character(uint16_t cStart, uint16_t rStart, uint16_t color);
