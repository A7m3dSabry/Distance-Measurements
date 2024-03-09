
/*************************** Section: Includes *********************************/


#include "avr/io.h"
#include "HAL/LCD/lcd.h"
#include "HAL/ULTRASONIC/ultrasonic.h"

/*************************** Section: Local Variables Declarations *************/
/*************************** Section: Helper Methods Prototypes  ***************/
/*************************** Section: Methods Implementations ******************/

int main(void)
{
    /* Enable the global interrupt */
	SREG |= (1<<7);

    /* Init the LCD device */
    HAL_LCD_init();
    HAL_LCD_displayStringRowColumn(1, 0, "Distance=");
    HAL_LCD_displayStringRowColumn(1, 13, "cm");

    /* Init Ultrasonic Configurations*/
    HAL_ULTRASONIC_init();

	while(1)
	{
		uint16_t distance = 0 ;
        /* Read Distance From the Sensor */
        HAL_ULTRASONIC_readDistance(&distance);

        HAL_LCD_moveCursor(1, 10);
        HAL_LCD_intToString(distance);

		if(distance < 100)
		{
            HAL_LCD_displayCharacter(' ');
		}
	}
}

/*************************** Section: Interrupt Methods Implementations ********/
/*************************** Section: Helper Methods Implementations  **********/
