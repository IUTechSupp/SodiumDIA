#pragma once

#include <stdint.h>
#include "gui.h"
#include "io.h"

struct AppData
{
    uint8_t currentMode;
};

#define MODE_UART 0
#define MODE_SPI 1
#define MODE_I2C 2
#define MODE_CAN 3

extern const char *MODE_ALIASES[];

uint8_t set_mode(uint8_t new_mode);
uint8_t handle_event(uint8_t event);