#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "board_pins_config.h"

#include "touchperiph.h"
#include "internet_radio.h"
#include "lcd.h"

i2c_lcd1602_info_t* lcd_info;
esp_err_t on_touch(audio_event_iface_msg_t* event, void* context);

// Switches to prevent spamming of the onboard buttons
bool play_clicked = false;
bool set_clicked = false;
bool vol_up_clicked = false;
bool vol_down_clicked = false;

// Startup entry
void app_main(void)
{
    f_setup_touch_periph();
    f_add_callback(&on_touch);

    while (1) { }

    f_destroy_touch_periph();
}

// Onboard buttons Play, Set, Vol- and Vol+ on_touch event
esp_err_t on_touch(audio_event_iface_msg_t* event, void* context)
{
    switch ((int)event->source_type) {
        case PERIPH_ID_TOUCH:
        {
            ESP_LOGI("TOUCH_BUTTON_TEST", "TOUCH[%d], event->event_id=%d", (int)event->data, event->cmd);

            if (event->data == get_input_play_id())
            {
                if (!play_clicked)
                {
                    // Initializes the radio

                    play_clicked = true;
                    init_internet_radio();
                }
                else
                    play_clicked = false;
            }
            else if (event->data == get_input_set_id())
            {    
                if (!set_clicked)
                {
                    // Displays the current channel radio name on the LCD
                    // This would work if the i2c driver would install correctly, which is not the case at the moment

                    //lcd_info = init_lcd_info();
                    //char* str_radio = "";
                    //get_current_channel_name(str_radio);
                    //display_channel_name(str_radio, lcd_info); 
                }
                else
                    set_clicked = false;       
            }
            else if (event->data == get_input_volup_id())
            {
                if (!vol_up_clicked)
                {
                    // Switches the radio channel forward by 1

                    vol_up_clicked = true;
                    switch_radio_next();
                }
                else
                    vol_up_clicked = false;
                
            }
            else if (event->data == get_input_voldown_id())
            {
                if (!vol_down_clicked)
                {
                    // Switches the radio channel backwards by 1

                    vol_down_clicked = true;
                    switch_radio_previous();
                }
                else
                    vol_down_clicked = false;
            }
        }
        break;
    }
    return ESP_OK;
}