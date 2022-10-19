#ifndef HEADER_H_
#define HEADER_H_

#define F_CPU 16000000UL // Klockferkvensen p� processorn

// Inkluderingsdirektiv:
#include <avr/io.h>
#include <util/delay.h>

#define LED1 6 // Pin 6 - PORTD6
#define LED2 7 // Pin 7 - PORTD7
#define LED3 0 // Pin 0 - PORTB0

#define BUTTON1 4 // Pin 12 - PINB4
#define BUTTON2 5 // Pin 13 - PINB5

#define LED1_ON PORTD |= (1 << LED1) // Aktiverar LED1
#define LED2_ON PORTD |= (1 << LED2) // Aktiverar LED2
#define LED3_ON PORTB |= (1 << LED3) // Aktiverar LED3

#define LED1_OFF PORTD &= ~(1 << LED1) // Inaktiverar LED1
#define LED2_OFF PORTD &= ~(1 << LED2) // Inaktiverar LED2
#define LED3_OFF PORTB &= ~(1 << LED3) // Inaktiverar LED3

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) // Kollar om BUTTON1 �r nedtryckt
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2)) // Kollar om BUTTON2 �r nedtryckt

typedef enum { true = 1, false = 0 } bool; // Definerar true och false att vara 1 och 2

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar.
********************************************************************************/
void setup(void);

/********************************************************************************
* delay_ms: l�gger in f�rdr�jning mellan blinkningarna.
********************************************************************************/
void delay_ms(uint16_t blink_speed_ms);

/********************************************************************************
* leds_on: T�nder alla lampor.
********************************************************************************/
void leds_on(int led1, int led2, int led3);

/********************************************************************************
* leds_on: Sl�cker alla lampor.
********************************************************************************/
void leds_off(int led1, int led2, int led3);

/********************************************************************************
* blink_forwards: Alla lampor blinkar i sekvens fr�n LED1 till LED3.
********************************************************************************/
void blink_forwards(uint16_t blink_speed_ms);

/********************************************************************************
* blink_backwards: Alla lampor blinkar i sekvens fr�n LED3 till LED1.
********************************************************************************/
void blink_backwards(uint16_t blink_speed_ms);

#endif