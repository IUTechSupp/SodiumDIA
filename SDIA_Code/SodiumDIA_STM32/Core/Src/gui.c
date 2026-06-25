#include "gui.h"
#include "font.h"
#include <stdlib.h>

struct Row Rows[17];
uint8_t selected_row_index;
struct Parameter Parameters[64];

struct Label make_label(uint8_t x, uint16_t bg_color, uint16_t text_color, const char *text, char *hint)
{
    struct Label label;
    label.bg_color = bg_color;
    label.text_color = text_color;
    label.x = x;
    label.text = text;
    return label;
}
struct Row make_row(uint8_t type)
{
    struct Row row;
    row.labels = 0;
    row.content = NULL;
    row.type = type;
    return row;
}
uint8_t add_label(struct Row *row, struct Label label)
{

    if (row->labels == 0)
    {
        row->content = malloc(sizeof(struct Label));
    }
    else
    {
        row->content = realloc(row->content, (row->labels + 1) * sizeof(struct Label));
    }

    if (row->content == NULL)
    {
        return 1; // Ошибка выделения памяти
    }

    row->content[row->labels] = label;
    row->labels++;
    return 0; // Успешно
}

uint8_t draw_row(uint8_t index, struct Row *row, uint8_t selected)
{
    if (selected)
    {
        draw_string_in_grid(0, index, "              ", DEFAULT_SELECTED_BG, DEFAULT_SELECTED_BG);
    }
    for (int i = 0; i < row->labels; i++)
    {
        struct Label *label = &row->content[i];
        uint16_t bg_color = selected ? DEFAULT_SELECTED_BG : label->bg_color;
        uint16_t text_color = selected ? DEFAULT_SELECTED_COLOR : label->text_color;
        draw_string_in_grid(label->x, index, label->text, text_color, bg_color);
    }
    return 0;
}

uint8_t select_next()
{
    selected_row_index++;
    if (selected_row_index >= 17)
    {
        selected_row_index = 0;
    }
    if (Rows[selected_row_index].type == UNSELECTABLE)
    {
        return select_next();
    }
    draw_gui();
    return 0;
}
uint8_t select_previous()
{
    selected_row_index--;
    if (selected_row_index >= 17)
    {
        selected_row_index = 16;
    }
    if (Rows[selected_row_index].type == UNSELECTABLE)
    {
        return select_previous();
    }
    draw_gui();
    return 0;
}

uint8_t compile_gui()
{
    struct Label label1_usb = make_label(0, ST7735_COLOR_BLACK, ST7735_COLOR_WHITE, "USB", "int");
    struct Label label2_usb = make_label(13, ST7735_COLOR_BLACK, ST7735_COLOR_RED, "X", "USB_OK");
    struct Row row_usb = make_row(UNSELECTABLE);
    add_label(&row_usb, label1_usb);
    add_label(&row_usb, label2_usb);
    Rows[0] = row_usb;

    struct Label label1 = make_label(0, ST7735_COLOR_BLACK, ST7735_COLOR_WHITE, "UART", "int");
    struct Label label2 = make_label(13, ST7735_COLOR_BLACK, ST7735_COLOR_GREEN, "V", "OK");
    struct Row row_status = make_row(UNSELECTABLE);
    add_label(&row_status, label1);
    add_label(&row_status, label2);
    Rows[1] = row_status;

    struct Label label1_par = make_label(0, ST7735_COLOR_BLACK, DEFAULT_INTERACTIVE_COLOR, "[Параметры]", "int");
    struct Row row_par = make_row(SELECTABLE);
    add_label(&row_par, label1_par);
    Rows[2] = row_par;

    struct Row row_pages = make_row(SELECTABLE);
    add_label(&row_pages, make_label(0, ST7735_COLOR_BLACK, DEFAULT_INTERACTIVE_COLOR, "[<]", NULL));
    add_label(&row_pages, make_label(3, ST7735_COLOR_BLACK, ST7735_COLOR_WHITE, " 1-12/96", NULL));
    add_label(&row_pages, make_label(11, ST7735_COLOR_BLACK, DEFAULT_INTERACTIVE_COLOR, "[>]", NULL));
    Rows[3] = row_pages;

    struct Row row_frame = make_row(SELECTABLE);
    add_label(&row_frame, make_label(0, ST7735_COLOR_BLACK, DEFAULT_COLOR, "1: HelloWorld", NULL));
    Rows[4] = row_frame;

    row_frame = make_row(SELECTABLE);
    add_label(&row_frame, make_label(0, ST7735_COLOR_BLACK, DEFAULT_COLOR, "2: Студ ИУ", NULL));
    Rows[5] = row_frame;

    row_frame = make_row(SELECTABLE);
    add_label(&row_frame, make_label(0, ST7735_COLOR_BLACK, DEFAULT_COLOR, "3: ИО ТО_ИУ", NULL));
    Rows[6] = row_frame;

    selected_row_index = 2;
}
uint8_t draw_gui()
{
    ST7735_DrawRect(0, 0, ST7735_X_SIZE, ST7735_Y_SIZE, ST7735_COLOR_BLACK);
    for (int i = 0; i < 17; i++)
    {
        if (&Rows[i] == NULL)
            continue;
        draw_row(i, &Rows[i], (i == selected_row_index));
    }
    return 0;
}