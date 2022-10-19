#include "gpio.h"


int main(void)
{
	setup();
	
    while(1)
	{
		if(BUTTON1_IS_PRESSED && !BUTTON2_IS_PRESSED)
		{
			leds_blink_sequence(100);
		}
		else if (BUTTON2_IS_PRESSED && !BUTTON1_IS_PRESSED)
		{
			leds_blink_sequence_reverse(100);
		}
		else if (BUTTON1_IS_PRESSED && BUTTON2_IS_PRESSED)
		{
			leds_on();
		}
		else 
		{
			leds_off();
		}
	
	}
	
	return 0;
}



