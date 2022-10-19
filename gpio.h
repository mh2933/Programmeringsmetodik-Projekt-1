/************************************************************
  gpio.h: detta är huvudfilen med definitioner, deklarationer 
          och inkluderingsdirektiv.
 ************************************************************/

#ifndef GPIO_H_ /* #ifndef, #define, #endif förhindrar dubbel inkludering av headerfiler */
#define GPIO_H_  

#define F_CPU 16000000UL /* 16 MHz klockfrekvens long unsigned int*/

#include <avr/io.h> /* bibliotek - I/O register */
#include <util/delay.h>  /* bibliotek - fördröjning */

/* Makrodefinitioner */
#define LED1 6 /* lysdiod 1 ansluten till pin 6 / PORTD6 */
#define LED2 7 /* lysdiod 2 ansluten till pin 7 / PORTD7 */
#define LED3 0 /* lysdiod 3 ansluten till pin 8 / PORTB0 */

#define BUTTON1 3 /* pushbutton 1 ansluten till pin 12 / PORTB3 */
#define BUTTON2 4 /* pushbutton 2 ansluten till pin 13 / PORTB4 */

#define LED1_ON PORTD |= (1 << LED1)
#define LED2_ON PORTD |= (1 << LED2)
#define LED3_ON PORTB |= (1 << LED3)

#define LED1_OFF PORTD &= ~(1 << LED1)
#define LED2_OFF PORTD &= ~(1 << LED2)
#define LED3_OFF PORTB &= ~(1 << LED3)

#define LEDS_ON PORTD |= ((1 << LED1) | (1 << LED2)); PORTB |= (1 << LED3)
#define LEDS_OFF PORTD &= ~((1 << LED1) | (1 << LED2)); PORTB &= ~(1 << LED3) 

#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1))
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2))

void setup(void);
void delay_ms(const uint16_t delay_time_ms);

void leds_on(void);
void leds_off(void);

void button1_pressed(void);

void leds_blink_collectively(const uint16_t blink_speed_ms);
void leds_blink_sequence(const uint16_t blink_speed_ms);
void leds_blink_sequence_reverse(const uint16_t blink_speed_ms);

#endif
