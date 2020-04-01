#ifndef INTERNET_RADIO_H
#define INTERNET_RADIO_H

#include "http_stream.h"

void init_internet_radio();

void switch_radio_next();
void switch_radio_previous();
void exec_channel(char* channel_url[]);

void start_channel_url(char* channel_url);
void reset_channel_url(char* channel_url);

void get_current_channel_name(char* channel_name[]);

int _http_stream_event_handle(http_stream_event_msg_t *msg);

#endif //INTERNET_RADIO_H