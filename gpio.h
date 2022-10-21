/************************************************************
  gpio.h: detta är huvudfilen med deklarationer 
          och inkluderingsdirektiv.
 ************************************************************/

#ifndef GPIO_H_ /* #ifndef, #define, #endif förhindrar dubbel inkludering av headerfiler */
#define GPIO_H_  

#define F_CPU 16000000UL /* 16 MHz klockfrekvens long unsigned int*/

#include <avr/io.h> /* bibliotek - I/O register */
#include <util/delay.h>  /* bibliotek - fördröjning */

/* Makrodeklarationer  */
#define LED1 6 /* lysdiod 1 ansluten till pin 6 / PORTD6 */
#define LED2 7 /* lysdiod 2 ansluten till pin 7 / PORTD7 */
#define LED3 0 /* lysdiod 3 ansluten till pin 0 / PORTB0 */

#define BUTTON1 3 /* pushbutton 1 ansluten till pin 12 / PORTB3 */
#define BUTTON2 4 /* pushbutton 2 ansluten till pin 13 / PORTB4 */

#define LED1_ON PORTD |= (1 << LED1) /* PORTD LED1 ettställs vid anrop */
#define LED2_ON PORTD |= (1 << LED2) /* PORTD LED2 ettställs vid anrop */
#define LED3_ON PORTB |= (1 << LED3) /* PORTB LED3 ettställs vid anrop */

#define LED1_OFF PORTD &= ~(1 << LED1) /* PORTD LED1 nollställs vid anrop */
#define LED2_OFF PORTD &= ~(1 << LED2) /* PORTD LED2 nollställs vid anrop */
#define LED3_OFF PORTB &= ~(1 << LED3) /* PORTB LED3 nollställs vid anrop */
 
#define LEDS_ON PORTD |= ((1 << LED1) | (1 << LED2));PORTB |= (1 << LED3)    /* PORTD och PORTB ettställs vid anrop */               				                      
#define LEDS_OFF PORTD &= ~((1 << LED1) | (1 << LED2));PORTB &= ~(1 << LED3) /* PORTD och PORTB ettställs vid anrop */
 
#define BUTTON1_IS_PRESSED (PINB & (1 << BUTTON1)) /* Läser av PINB vid nedtryck av tryckknapp BUTTON1 */
#define BUTTON2_IS_PRESSED (PINB & (1 << BUTTON2)) /* Läser av PINB vid nedtryck av tryckknapp BUTTON2 */

/* Prototyper/deklarering av funktioner */
void setup(void); 
void delay_ms(const uint16_t delay_time_ms);

void leds_on(void);
void leds_off(void);

void leds_blink_sequence(const uint16_t blink_speed_ms);
void leds_blink_sequence_reverse(const uint16_t blink_speed_ms);

/* avslutar header guard */
#endif

