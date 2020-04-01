# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "lcd.c i2c-lcd1602.c smbus.c .")
set(COMPONENT_ADD_INCLUDEDIRS "include .")

register_component()