#pragma once

#include <stdint.h>
#include "st7735.h"

// Цвета по умолчанию для текста и фона
#define DEFAULT_BG ST7735_COLOR_BLACK
#define DEFAULT_COLOR ST7735_COLOR_WHITE
#define DEFAULT_SELECTED_BG ST7735_COLOR_BLUE
#define DEFAULT_SELECTED_COLOR ST7735_COLOR_WHITE
#define DEFAULT_INTERACTIVE_COLOR ST7735_COLOR_BLUE

// Типы строк
#define UNSELECTABLE 0
#define SELECTABLE 1
#define HORIZONTAL 2

// Разметка страницы
#define HEADER_ROWS 2

struct Label
{
    uint8_t x;
    uint16_t bg_color;
    uint16_t text_color;
    const char *text;
};

struct Row
{
    uint8_t labels;
    struct Label *content;
    uint8_t type;
};

struct Parameter
{
    struct Label *label;
    char hint[16];
};

extern struct Row Rows[];
extern uint8_t selected_row_index;
extern struct Parameter Parameters[];

struct Label make_label(uint8_t x, uint16_t bg_color, uint16_t text_color, const char *text, char *hint);
struct Row make_row(uint8_t type);
uint8_t add_label(struct Row *row, struct Label label);

uint8_t draw_row(uint8_t index, struct Row *row, uint8_t selected);
uint8_t draw_row_by_index(uint8_t index);
uint8_t select_next();
uint8_t select_previous();
uint8_t set_parameter(char *hint, char *value);

uint8_t compile_gui();
uint8_t draw_gui();
