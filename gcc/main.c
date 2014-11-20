#include "CU_TM4C123.h"

int main(void){

    //volatile to prevent GCC from optimizing out variable.
    volatile uint32_t ui32Loop;

    // Enable GPIOF
	SYSCTL->RCGCGPIO |= (1UL << 5);

    // dummy read	
    ui32Loop = SYSCTL->RCGCGPIO;
	
    // Enable the GPIO pin as output
	GPIOF->DIR |= 0x08;     

    // enable digital output
    GPIOF->DEN |= 0x08;       

	while(1)
    {
        // Turn on the LED.
        GPIOF->DATA |= 0x08;

        // busy wait
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++);

        // Turn off the LED.
        GPIOF->DATA &= ~(0x08);

        // Busy wait.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++);
    }
}