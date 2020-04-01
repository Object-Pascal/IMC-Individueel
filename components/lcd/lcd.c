#include "lcd.h"
#include "smbus.h"
#include "i2c-lcd1602.h"

#define TAG "LCD"
#undef USE_STDIN

#define I2C_MASTER_NUM                  I2C_NUM_0
#define I2C_MASTER_TX_BUF_DISABLE       0
#define I2C_MASTER_RX_BUF_DISABLE       0
#define I2C_MASTER_FREQ_HZ              100000
#define I2C_MASTER_SDA_IO               CONFIG_I2C_MASTER_SDA
#define I2C_MASTER_SCL_IO               CONFIG_I2C_MASTER_SCL
#define LCD_NUM_ROWS			        4
#define LCD_NUM_COLUMNS			        40
#define LCD_NUM_VIS_COLUMNS		        20

// Start the master i2c driver
void i2c_master_init()
{
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = I2C_MASTER_SDA_IO;
    conf.sda_pullup_en = GPIO_PULLUP_DISABLE;
    conf.scl_io_num = I2C_MASTER_SCL_IO;
    conf.scl_pullup_en = GPIO_PULLUP_DISABLE;
    conf.master.clk_speed = I2C_MASTER_FREQ_HZ;

    i2c_param_config(I2C_MASTER_NUM, &conf);
    i2c_driver_install(I2C_MASTER_NUM, conf.mode, I2C_MASTER_RX_BUF_DISABLE, I2C_MASTER_TX_BUF_DISABLE, 0);
}

// Initializes info for the LCD i2c device
i2c_lcd1602_info_t* init_lcd_info() 
{
    // Set up I2C
    i2c_master_init();
    i2c_port_t i2c_num = I2C_MASTER_NUM;
    uint8_t address = CONFIG_LCD1602_I2C_ADDRESS;

    // Set up the SMBus
    smbus_info_t* smbus_info = smbus_malloc();
    smbus_init(smbus_info, i2c_num, address);
    smbus_set_timeout(smbus_info, 1000 / portTICK_RATE_MS);

    // Set up the LCD1602 device with backlight off
    i2c_lcd1602_info_t* lcd_info = i2c_lcd1602_malloc();
    i2c_lcd1602_init(lcd_info, smbus_info, true, LCD_NUM_ROWS, LCD_NUM_COLUMNS, LCD_NUM_VIS_COLUMNS);
    return lcd_info;
}

// Displays the given radio channel name onto the LCD
void display_channel_name(const char* channel_name,  const i2c_lcd1602_info_t* lcd_info) 
{
    i2c_lcd1602_clear(lcd_info);
    i2c_lcd1602_move_cursor(lcd_info, 0, 1);
    i2c_lcd1602_write_string(lcd_info, "--- Channel: ---");
    i2c_lcd1602_move_cursor(lcd_info, 0, 2);
    i2c_lcd1602_write_string(lcd_info, channel_name);
}

// Clears the LCD screen
void clear_lcd_screen(const i2c_lcd1602_info_t* lcd_info) 
{
    i2c_lcd1602_clear(lcd_info);
}