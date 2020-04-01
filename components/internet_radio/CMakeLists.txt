# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES channel_provider nvs_flash audio_board audio_hal audio_pipeline audio_sal audio_stream esp_peripherals)
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "internet_radio.c .")
set(COMPONENT_ADD_INCLUDEDIRS "include .")

register_component()