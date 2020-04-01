#include "esp_log.h"
#include "esp_peripherals.h"
#include "periph_touch.h"

static esp_periph_set_handle_t touch_periph_set;

// Declare the event handle for the callbacks
typedef esp_err_t(*PERIPH_EVENT_HANDLE)(audio_event_iface_msg_t* event, void* context);

// Setup/Init touch peripherals
void f_setup_touch_periph()
{
    esp_periph_config_t periph_cfg = DEFAULT_ESP_PERIPH_SET_CONFIG();
    touch_periph_set = esp_periph_set_init(&periph_cfg);

    periph_touch_cfg_t touch_cfg = {
        .touch_mask = TOUCH_PAD_SEL4 | TOUCH_PAD_SEL7 | TOUCH_PAD_SEL8 | TOUCH_PAD_SEL9,
        .tap_threshold_percent = 70,
    };
    esp_periph_handle_t touch_handle = periph_touch_init(&touch_cfg);

    esp_periph_start(touch_periph_set, touch_handle);
}

// Adds ability to add callbacks to the touch buttons 
void f_add_callback(PERIPH_EVENT_HANDLE callback)
{
    esp_periph_set_register_callback(touch_periph_set, callback, NULL);
}

// Destroy esp touch peripheral controls
void f_destroy_touch_periph()
{
    esp_periph_set_destroy(touch_periph_set);
}