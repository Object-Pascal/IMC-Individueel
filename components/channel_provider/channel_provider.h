#ifndef CHANNEL_PROVIDER_H
#define CHANNEL_PROVIDER_H

void init_channel_provider();
void switch_channel_next();
void switch_channel_previous();
void provide_channel_url(char* channel_url[]);
void provide_channel_name(char* channel_name[]);

#endif //CHANNEL_PROVIDER_H