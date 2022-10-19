#include "header.h"

/********************************************************************************
* setup: Initierar mikrodatorns I/O-portar.
********************************************************************************/
void setup(void)
{
	DDRD = ((1 << LED1) | (1 << LED2));
	DDRB = (1 << LED3);
	
	PINB = ((1 << BUTTON1) | (1 << BUTTON2));	
	return;
}

/********************************************************************************
* delay_ms: lägger in fördröjning mellan blinkningarna.
********************************************************************************/
void delay_ms(uint16_t blink_speed_ms)
{
	for (int i = 0; i < blink_speed_ms; i++)
	{
		_delay_ms(1);
	}

    return;
}

/********************************************************************************
* leds_on: Tänder alla lampor.
********************************************************************************/
void leds_on(int led1, int led2, int led3)
{
	PORTD |= ((1 << led1) | (1 << led2));
	PORTB |= (1 << led3);
	
	return;
}

/********************************************************************************
* leds_on: Släcker alla lampor.
********************************************************************************/
void leds_off(int led1, int led2, int led3)
{
	PORTD &= ~((1 << led1) | (1 << led2));
	PORTB &= ~(1 << led3);
	
	return;
}

/********************************************************************************
* blink_forwards: Alla lampor blinkar i sekvens från LED1 till LED3.
********************************************************************************/
void blink_forwards(uint16_t blink_speed_ms)
{
	LED1_ON;
	delay_ms(blink_speed_ms);
	LED1_OFF;
	LED2_ON;
	delay_ms(blink_speed_ms);
	LED2_OFF;
	LED3_ON;
	delay_ms(blink_speed_ms);
	LED3_OFF;
	
	return;
}

/********************************************************************************
* blink_backwards: Alla lampor blinkar i sekvens från LED3 till LED1.
********************************************************************************/
void blink_backwards(uint16_t blink_speed_ms)
{
	LED3_ON;
	delay_ms(blink_speed_ms);
	LED3_OFF;
	LED2_ON;
	delay_ms(blink_speed_ms);
	LED2_OFF;
	LED1_ON;
	delay_ms(blink_speed_ms);
	LED1_OFF;
	
	return;
}