#include <stdio.h>

#define MAX_CHANNELS 5
#define MAX_CHANNEL_SIZE 255

int selected_station_index;
char channel_list[MAX_CHANNELS][MAX_CHANNEL_SIZE] =
{ 
    "https://icecast.omroep.nl/3fm-serioustalent-mp3",
    "https://icecast-qmusicnl-cdp.triple-it.nl/Qmusic_nl_live_96.mp3",
    "http://playerservices.streamtheworld.com/api/livestream-redirect/RADIO10.mp3",
    "http://playerservices.streamtheworld.com/api/livestream-redirect/RADIO538.mp3",
    "https://stream.slam.nl/slam_mp3"
};

char channel_name_list[MAX_CHANNELS][MAX_CHANNEL_SIZE] =
{ 
    "NPO 3FM",
    "Qmusic",
    "Radio 10",
    "Radio 538",
    "SLAM! LIVE"
};

void init_channel_provider() 
{
    selected_station_index = 0;
}

void switch_channel_next()
{
    if (selected_station_index < (MAX_CHANNELS - 1))
        selected_station_index = selected_station_index + 1;
    else
        selected_station_index = 0;
}

void switch_channel_previous()
{
    if (selected_station_index == 0)
        selected_station_index = (MAX_CHANNELS - 1);
    else
        selected_station_index = selected_station_index - 1;
}

void provide_channel_url(char* channel_url[])
{
    *channel_url = channel_list[selected_station_index];
}

void provide_channel_name(char* channel_name[])
{
    *channel_name = channel_name_list[selected_station_index];
}