#include "gpio.h"

void setup(void)
{
	DDRD =  ((1 << LED1) | (1 << LED2));
	DDRB =  (1 << LED3);
	PORTD = ((1 << BUTTON1) | (1 << BUTTON2));
	PORTB = (1 << LED3);
	return;
}

void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; i++)
	{
		_delay_ms(1);
	}
	 return;
}

void leds_on(void)
{
	PORTD |= ((1 << LED1) | (1 << LED2)); 
	PORTB |= (1 << LED3);
	return;
}

void leds_off(void)
{
	PORTD &= ~((1 << LED1) | (1 << LED2)); 
	PORTB &= ~(1 << LED3);
	return;
}

/*
void button1_pressed(void)
{
	if (BUTTON1_IS_PRESSED)
	{
		leds_blink_sequence();
	}
	else
	{
		leds_off();
	}
	
	return;
}
*/

void leds_blink_collectively(const uint16_t blink_speed_ms)
{
	
    LEDS_ON;
	delay_ms(blink_speed_ms);
	LEDS_OFF;
	delay_ms(blink_speed_ms);
	return;
}

void leds_blink_sequence(const uint16_t blink_speed_ms)
{
	
	delay_ms(blink_speed_ms);
	LED1_OFF;
	delay_ms(blink_speed_ms);
	LED2_OFF;
	delay_ms(blink_speed_ms);
	LED3_OFF;
	delay_ms(blink_speed_ms);
	LED1_ON;
	delay_ms(blink_speed_ms);
	LED2_ON;
	delay_ms(blink_speed_ms);
	LED3_ON;
	
	return;
}

void leds_blink_sequence_reverse(const uint16_t blink_speed_ms)
{
	delay_ms(blink_speed_ms);
	LED3_OFF;
	delay_ms(blink_speed_ms);
	LED2_OFF;
	delay_ms(blink_speed_ms);
	LED1_OFF;
	delay_ms(blink_speed_ms);
	LED3_ON;
	delay_ms(blink_speed_ms);
	LED2_ON;
	delay_ms(blink_speed_ms);
	LED1_ON;
	
	return;
}