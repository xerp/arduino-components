#ifndef ARCH_H
#define ARCH_H

#ifdef Arduino_h
#define ARDUINO
#else
#define UNIX
#endif


#ifdef ARDUINO
#include <Arduino.h>
#endif

#ifdef UNIX

#define HIGH 0x1
#define LOW  0x0

#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2

typedef bool boolean;
typedef uint8_t byte;

// Functions
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);
int digitalRead(uint8_t pin);
int analogRead(uint8_t pin);
void analogReference(uint8_t mode);
void analogWrite(uint8_t pin, int val);

unsigned long millis();
unsigned long micros();
void delay(unsigned long ms);

#endif

#endif //ARCH_H
