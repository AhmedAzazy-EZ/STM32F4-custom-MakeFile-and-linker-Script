
#include <stdint.h>
#include "main.h"

int main(void)
{
	
	RCC->AHB1ENR|=(1<<0);
	GPIOA->MODER|=(1<<10);
	GPIOA->ODR|=(1<<5);
	
	
	while(1)
	{
		
		for(uint32_t i = 0 ; i < 800000 ; i++)
		{
		}
		
		GPIOA->ODR^=(1<<5);
		
	}
	
	return 0 ;
}