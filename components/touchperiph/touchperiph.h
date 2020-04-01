#ifndef TOUCH_PERIPH_H
#define TOUCH_PERIPH_H

#include "esp_log.h"
#include "esp_peripherals.h"
#include "periph_touch.h"

typedef esp_err_t(*PERIPH_EVENT_HANDLE)(audio_event_iface_msg_t* event, void* context);

void f_setup_touch_periph();
void f_add_callback(PERIPH_EVENT_HANDLE callback);
void f_destroy_touch_periph();

#endif // TOUCH_PERIPH_H