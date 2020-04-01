# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES esp_peripherals)
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "touchperiph.c .")
set(COMPONENT_ADD_INCLUDEDIRS "include .")

register_component()