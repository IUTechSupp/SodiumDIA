#include "io.h"

uint8_t current_column = 0;

const char KEY_SYMBOLS[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '*', '#', '^', 'v', '<', 'U', 'S', 'I', 'C'};

uint16_t paused = 0;

#define DELAY_MS 10

uint8_t ask_keyboard()
{
    current_column = 0;
    HAL_GPIO_WritePin(KEYBOARD_PORT, KEYBOARD_COLUMN_1, GPIO_PIN_SET); // Set the pin high to ask for keyboard input
    keyboard_wait();
    HAL_GPIO_WritePin(KEYBOARD_PORT, KEYBOARD_COLUMN_1, GPIO_PIN_RESET); // Set the pin high to ask for keyboard input

    current_column = 1;
    HAL_GPIO_WritePin(KEYBOARD_PORT, KEYBOARD_COLUMN_2, GPIO_PIN_SET); // Set the pin high to ask for keyboard input
    keyboard_wait();
    HAL_GPIO_WritePin(KEYBOARD_PORT, KEYBOARD_COLUMN_2, GPIO_PIN_RESET); // Set the pin high to ask for keyboard input

    current_column = 2;
    HAL_GPIO_WritePin(KEYBOARD_PORT, KEYBOARD_COLUMN_3, GPIO_PIN_SET); // Set the pin high to ask for keyboard input
    keyboard_wait();
    HAL_GPIO_WritePin(KEYBOARD_PORT, KEYBOARD_COLUMN_3, GPIO_PIN_RESET); // Set the pin high to ask for keyboard input

    return 0;
}

uint8_t get_event(uint16_t pin)
{
    switch (pin)
    {
    case KEYBOARD_ROW_1:
        keyboard_pause(pin);       // Pause the keyboard scanning until the button is released
        return current_column + 1; // Return the index of the button pressed in the first row
    case KEYBOARD_ROW_2:
        keyboard_pause(pin);       // Pause the keyboard scanning until the button is released
        return current_column + 4; // Return the index of the button pressed in the second row
    case KEYBOARD_ROW_3:
        keyboard_pause(pin);       // Pause the keyboard scanning until the button is released
        return current_column + 7; // Return the index of the button pressed in the third row
    case KEYBOARD_ROW_4:
        keyboard_pause(pin); // Pause the keyboard scanning until the button is released
        if (current_column == 0)
            return EVENT_BUTTON_OK;
        if (current_column == 1)
            return 0;
        if (current_column == 2)
            return EVENT_BUTTON_CANCEL;
    case BUTTON_UART:
        return EVENT_BUTTON_UART;
    case BUTTON_SPI:
        return EVENT_BUTTON_SPI;
    case BUTTON_I2C:
        return EVENT_BUTTON_I2C;
    case BUTTON_CAN:
        return EVENT_BUTTON_CAN;
    case BUTTON_UP:
        return EVENT_BUTTON_UP;
    case BUTTON_DOWN:
        return EVENT_BUTTON_DOWN;
    case BUTTON_HORIZONTAL:
        return EVENT_BUTTON_HORIZONTAL;
    default:
        return 255; // Invalid pin
    }
}

uint8_t keyboard_pause(uint16_t pin)
{
    paused = pin;
    return 0;
}

uint8_t keyboard_resume()
{
    paused = 0;
    return 0;
}

uint8_t keyboard_wait()
{
    HAL_Delay(DELAY_MS); // Add a small delay to avoid bouncing issues
    while (paused)
    {
        if (!HAL_GPIO_ReadPin(KEYBOARD_PORT, paused))
            keyboard_resume();
    }
}