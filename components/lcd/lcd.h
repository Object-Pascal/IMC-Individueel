#ifndef LCD_H
#define LCD_H

#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "driver/gpio.h"
#include "driver/i2c.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "rom/uart.h"

#include "smbus.h"
#include "i2c-lcd1602.h"

void i2c_master_init();
i2c_lcd1602_info_t* init_lcd_info();

void display_on_lcd(const char* text,  const i2c_lcd1602_info_t* lcd_info);
void display_channel_name(const char* channel_name,  const i2c_lcd1602_info_t* lcd_info);

#endif //LCD_H