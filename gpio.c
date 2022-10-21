/* Definitioner av funktioner i gpio.c */
/* inkludering av headerfil för mer strukturerad kod */
#include "gpio.h"



/* setup definierar DDR = data direction register och PORT-register */
void setup(void)
{
	DDRD =  ((1 << LED1) | (1 << LED2));
	DDRB =  (1 << LED3);
	PORTD = ((1 << BUTTON1) | (1 << BUTTON2));
	PORTB = (1 << LED3);
	return;
}

/* delay_ms fördefinierad fördröjning ifrån delay bibliotek */
void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; i++)
	{
		_delay_ms(1);
	}
	 return;
}

/* leds_on förenklar anrop i main */
void leds_on(void)
{
	PORTD |= ((1 << LED1) | (1 << LED2)); 
	PORTB |= (1 << LED3);
	return;
}

/* leds_off förenklar anrop i main */
void leds_off(void)
{
	PORTD &= ~((1 << LED1) | (1 << LED2)); 
	PORTB &= ~(1 << LED3);
	return;
}

/* blink sekvens */
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

/* blink sekvens baklänges */
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
