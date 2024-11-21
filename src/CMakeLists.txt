set(SOURCES
        ../arch/base.cpp
        base.cpp
        button.cpp
        rotary-encoder.cpp)


add_library(ArduinoComponents SHARED ${SOURCES})