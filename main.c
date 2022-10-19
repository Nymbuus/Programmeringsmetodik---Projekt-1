#include "header.h"

int main(void)
{
	setup();
    
    while (true) 
    {
		if (BUTTON1_IS_PRESSED && !BUTTON2_IS_PRESSED)
		{
			blink_forwards(100);
		}
		else if (!BUTTON1_IS_PRESSED && BUTTON2_IS_PRESSED)
		{
		    blink_backwards(100);	
		}
		else if (BUTTON1_IS_PRESSED && BUTTON2_IS_PRESSED)
		{
		    leds_on(LED1, LED2 ,LED3);
		}
		else
		{
			leds_off(LED1, LED2 ,LED3);
		}
    }
	
	return 0;
}

