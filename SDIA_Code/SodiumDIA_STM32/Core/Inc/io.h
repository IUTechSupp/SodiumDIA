#pragma once

#include <stdint.h>
#include "stm32f1xx_hal.h"

extern uint8_t current_column;
extern const char KEY_SYMBOLS[];

#define EVENT_BUTTON_0 0
#define EVENT_BUTTON_1 1
#define EVENT_BUTTON_2 2
#define EVENT_BUTTON_3 3
#define EVENT_BUTTON_4 4
#define EVENT_BUTTON_5 5
#define EVENT_BUTTON_6 6
#define EVENT_BUTTON_7 7
#define EVENT_BUTTON_8 8
#define EVENT_BUTTON_9 9
#define EVENT_BUTTON_OK 10
#define EVENT_BUTTON_CANCEL 11
#define EVENT_BUTTON_UP 12
#define EVENT_BUTTON_DOWN 13
#define EVENT_BUTTON_HORIZONTAL 14
#define EVENT_BUTTON_UART 15
#define EVENT_BUTTON_SPI 16
#define EVENT_BUTTON_I2C 17
#define EVENT_BUTTON_CAN 18

#define KEYBOARD_PORT GPIOB
#define KEYBOARD_ROW_1 GPIO_PIN_8
#define KEYBOARD_ROW_2 GPIO_PIN_3
#define KEYBOARD_ROW_3 GPIO_PIN_4
#define KEYBOARD_ROW_4 GPIO_PIN_6
#define KEYBOARD_COLUMN_1 GPIO_PIN_7
#define KEYBOARD_COLUMN_2 GPIO_PIN_9
#define KEYBOARD_COLUMN_3 GPIO_PIN_5

#define BUTTON_UP GPIO_PIN_9
#define BUTTON_DOWN GPIO_PIN_10
#define BUTTON_HORIZONTAL GPIO_PIN_11

#define BUTTON_UART GPIO_PIN_12
#define BUTTON_SPI GPIO_PIN_13
#define BUTTON_I2C GPIO_PIN_14
#define BUTTON_CAN GPIO_PIN_15

uint8_t ask_keyboard();
uint8_t get_event(uint16_t pin);
uint8_t keyboard_pause(uint16_t pin);
uint8_t keyboard_resume();

uint8_t keyboard_wait();