#include <stdlib.h>
#include <stdint.h>
#define LED_DELAY 5000

/* AHB1 Base Addresses ******************************************************/

#define STM32_RCC_BASE      0x40021000     /* 0x40021000 - 0x400213ff: Reset and Clock control RCC */

/* AHB2 Base Addresses ******************************************************/

#define STM32_GPIOC_BASE    0x40011000     /* 0x40011000 - 0x400113ff: GPIO Port C */

/* Register Offsets *********************************************************/

#define STM32_RCC_APB2ENR_OFFSET    0x0018  /* APB2 peripheral clock enable register */

#define STM32_GPIO_CRL_OFFSET       0x0000  /* Port configuration register low */
#define STM32_GPIO_CRH_OFFSET       0x0004  /* Port configuration register high */


/* Register Addresses *******************************************************/

#define STM32_RCC_APB2ENR            (STM32_RCC_BASE+STM32_RCC_APB2ENR_OFFSET)

#define STM32_GPIO_CRL               (STM32_GPIOC_BASE+STM32_GPIO_CRL_OFFSET)
#define STM32_GPIO_CRH               (STM32_GPIOC_BASE+STM32_GPIO_CRH_OFFSET)

/* APB2 Peripheral Clock enable register (RCC_APB2ENR) */

#define RCC_APB2ENR_IOPCEN         (1 << 4)    /* Bit 4 IOPCEN: IO port C clock enable */

/* Port configuration register */

#define GPIO_MODE_INPUT               (0) /* Input */
#define GPIO_MODE_OUTPUT_10MHZ        (1) /* Output 10MHz */
#define GPIO_MODE_OUTPUT_2MHZ         (2) /* Output 2MHz */
#define GPIO_MODE_OUTPUT_50MHZ        (3) /* Output 50MHz */

#define GPIO_CNF_I_ANALOG_MODE        (0) /* Input: Analog mode */
#define GPIO_CNF_I_FLOATING_INPUT     (1) /* Input: Floating input (reset state) */
#define GPIO_CNF_I_PULL_UP_DOWN       (2) /* Input: Input with pull-up / pull-down */
                                          /* Input 11 (3): Reserved */

#define GPIO_CNF_O_GPO_PUSH_PULL      (0) /* Output: General purpose output push-pull */
#define GPIO_CNF_O_GPO_OPEN_DRAIN     (1) /* Output: General purpose output Open-drain */
#define GPIO_CNF_O_AFO_PUSH_PULL      (2) /* Output: Alternate function output Push-pull */
#define GPIO_CNF_O_AFO_OPEN_DRAIN     (3) /* Output: Alternate function output Open-drain */


#define GPIO_MODE_SHIFT(n)            (n < 8) ? (3 << n) : (3 << (n - 8))
#define GPIO_MODE_MASK(n)             (3 << GPIO_MODE_SHIFT(n))

// #define GPIO_MODER_SHIFT(n)        (n << 1)
// #define GPIO_MODER_MASK(n)         (3 << GPIO_MODER_SHIFT(n))

// #define GPIO_MODER_INPUT           (0) /* Input */
// #define GPIO_MODER_OUTPUT          (1) /* General purpose output mode */
// #define GPIO_MODER_ALT             (2) /* Alternate mode */
// #define GPIO_MODER_ANALOG          (3) /* Analog mode */

// #define GPIO_MODER_SHIFT(n)        (n << 1)
// #define GPIO_MODER_MASK(n)         (3 << GPIO_MODER_SHIFT(n))


// /* GPIO port bit set/reset register */
// #define GPIO_BSRR_SET(n) (1 << (n))
// #define GPIO_BSRR_RST(n) (1 << (n + 16))

// OQ EU PRECISO SETAR PARA LIGAR O LED?? E O Q EU PRECISO RESETAR

int main(int argc, char *argv[])
{
    uint32_t reg;
    uint32_t i;

    /* Ponteiros para registradores */
    uint32_t *pRCC_APB2ENR  = (uint32_t *)STM32_RCC_APB2ENR;
    uint32_t *pGPIO_CRL  = (uint32_t *)STM32_GPIO_CRL;
    uint32_t *pGPIO_CRH  = (uint32_t *)STM32_GPIO_CRH;


    /* Habilita clock GPIOC */
    reg  = *pRCC_AHB1ENR;
    reg |= RCC_AHB1ENR_GPIOCEN;
    *pRCC_AHB1ENR = reg;
    
    /* Configura PC13 como saida pull-up off e pull-down off */
    reg = *pGPIOC_MODER;
    reg &= ~GPIO_MODER_MASK(13);
    reg |= (GPIO_MODER_OUTPUT << GPIO_MODER_SHIFT(13));
    *pGPIOC_MODER = reg;  

    reg = *pGPIOC_OTYPER;
    reg &= ~GPIO_OT_MASK(13);
    reg |= (GPIO_OTYPER_PP << GPIO_OT_SHIFT(13));
    *pGPIOC_OTYPER = reg;

    reg = *pGPIOC_PUPDR;
    reg &= ~GPIO_PUPDR_MASK(13);
    reg |= (GPIO_PUPDR_NONE << GPIO_PUPDR_SHIFT(13));
    *pGPIOC_PUPDR = reg;

    while(1)
    {
        *pGPIOC_BSRR = GPIO_BSRR_SET(13);
        for(i = 0; i < LED_DELAY; i++);
        *pGPIOC_BSRR = GPIO_BSRR_RST(13);
        for(i = 0; i < LED_DELAY; i++);
    }

    return EXIT_SUCCESS;
}

