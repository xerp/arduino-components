#ifndef ARCH_MACROS_H
#define ARCH_MACROS_H

#ifdef Arduino_h
#define ARDUINO
#else
#define UNIX
#endif

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

#define None ((void*) 0)
#define NoValue (-1)

#endif //ARCH_MACROS_H
