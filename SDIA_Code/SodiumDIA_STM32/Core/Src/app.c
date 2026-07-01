#include "app.h"

struct AppData appData;

const char *MODE_ALIASES[] = {"UART", "SPI ", "I2C ", "CAN "};

uint8_t set_mode(uint8_t new_mode)
{
    if (new_mode > MODE_CAN)
    {
        return 1; // Invalid mode
    }
    appData.currentMode = new_mode;

    Rows[1].content[0].text = MODE_ALIASES[new_mode]; // Update the label text based on the new mode
    draw_row_by_index(1);                             // Redraw the row to reflect the change

    return 0; // Success
}

uint8_t handle_event(uint8_t event)
{
    static char buffer[2];
    buffer[0] = KEY_SYMBOLS[event];
    buffer[1] = '\0';
    Rows[7].content[0].text = buffer; // Update the label text based on the button pressed
    draw_row_by_index(7);             // Redraw the row to reflect the change

    if (event == EVENT_BUTTON_UP)
    {
        select_previous();
    }
    else if (event == EVENT_BUTTON_DOWN)
    {
        select_next();
    }

    return 0; // Event handled successfully
}