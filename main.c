#include "gpio.h"


int main(void)
{
	setup();
	
	/* en kontinuerlig while loop */
    while(1)
	{
		
		if(BUTTON1_IS_PRESSED && !BUTTON2_IS_PRESSED) // om bara BUTTON1 är nedtryckt så körs leds_blink_sequence
		{
			leds_blink_sequence(1);
		}
		else if (BUTTON2_IS_PRESSED && !BUTTON1_IS_PRESSED) // om bara BUTTON2 är nedtryckt så körs leds_blink_sequence_reverse
		{
			leds_blink_sequence_reverse(1);
		}
		else if (BUTTON1_IS_PRESSED && BUTTON2_IS_PRESSED) // om både BUTTON1 och BUTTON2 är nedtryckt så körs leds_on
		{
			leds_on();
		}
		else // annars körs leds_off
		{
			leds_off();
		}
	
	}
	
	return 0;
}



