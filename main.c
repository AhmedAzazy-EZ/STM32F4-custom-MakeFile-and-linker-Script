
#include <stdint.h>

typedef struct
{
   uint32_t CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */
    uint32_t PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
    uint32_t CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
    uint32_t CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
    uint32_t AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
    uint32_t AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
    uint32_t AHB3RSTR;      /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */
  uint32_t      RESERVED0;     /*!< Reserved, 0x1C                                                                    */
    uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
    uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  uint32_t      RESERVED1[2];  /*!< Reserved, 0x28-0x2C                                                               */
    uint32_t AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
    uint32_t AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
    uint32_t AHB3ENR;       /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */
  uint32_t      RESERVED2;     /*!< Reserved, 0x3C                                                                    */
    uint32_t APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
    uint32_t APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  uint32_t      RESERVED3[2];  /*!< Reserved, 0x48-0x4C                                                               */
    uint32_t AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
    uint32_t AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
    uint32_t AHB3LPENR;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */
  uint32_t      RESERVED4;     /*!< Reserved, 0x5C                                                                    */
    uint32_t APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
    uint32_t APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  uint32_t      RESERVED5[2];  /*!< Reserved, 0x68-0x6C                                                               */
    uint32_t BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
    uint32_t CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  uint32_t      RESERVED6[2];  /*!< Reserved, 0x78-0x7C                                                               */
    uint32_t SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
    uint32_t PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
    uint32_t PLLSAICFGR;    /*!< RCC PLLSAI configuration register,                           Address offset: 0x88 */
    uint32_t DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
    uint32_t CKGATENR;      /*!< RCC Clocks Gated ENable Register,                            Address offset: 0x90 */
    uint32_t DCKCFGR2;      /*!< RCC Dedicated Clocks configuration register 2,               Address offset: 0x94 */
} RCC_TypeDef;



typedef struct
{
    uint32_t MODER;    /*!< GPIO port mode register,               Address offset: 0x00      */
    uint32_t OTYPER;   /*!< GPIO port output type register,        Address offset: 0x04      */
    uint32_t OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
    uint32_t PUPDR;    /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
    uint32_t IDR;      /*!< GPIO port input data register,         Address offset: 0x10      */
    uint32_t ODR;      /*!< GPIO port output data register,        Address offset: 0x14      */
    uint32_t BSRR;     /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
    uint32_t LCKR;     /*!< GPIO port configuration lock register, Address offset: 0x1C      */
    uint32_t AFR[2];   /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;

#define RCC 	((RCC_TypeDef *) 0x40023800)
#define GPIOA	((GPIO_TypeDef *) 0x40020000)


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