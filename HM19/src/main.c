/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include <stdint.h>

void init_usart5();

void init_usart5() {
    // TODO
    // Enable GPIO C
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN; // enables port C

    // Enable GPIO D
    RCC->AHBENR |= RCC_AHBENR_GPIODEN; // enables port D

    GPIOC->MODER |= 0x2000000;
    GPIOD->MODER |= 0x20;

    // https://www.mouser.com/datasheet/2/389/dm00115237-1798191.pdf
    // tables 14-19
    // check for what pins can be connected to the USART's voia AFR's
    //
    // PC12 + USART5_TX = AF2
    // PD2 + USART5_RX = AF2

    // configure alternate function for AF2, need 0010 for AF2
    // AFR[0] -> AFRL
    // AFR[1] -> AFRH
    GPIOC->AFR[1] |= 2<<16; // 0010 is AF2, and shift 16 bits left to reference pin 12
    GPIOD->AFR[0] |= 2<<8; // 0010 is AF2, and shift 8 bits left to reference pin 2

    // enable clock for USART
    RCC->APB1ENR |= RCC_APB1ENR_USART5EN;

    // disable USART5 by turning off UE bit
    USART5->CR1 &= ~(USART_CR1_UE);

    // set word size of 8 bits
    USART5->CR1 &= ~(USART_CR1_M);

    // set for one stop bit
    USART5->CR2 &= ~(USART_CR2_STOP);

    // set it for no parity
    USART5->CR1 &= ~(USART_CR1_PCE);

    // use 16x oversampling
    USART5->CR1 &= ~(USART_CR1_OVER8);

    // baud rate of 115200 (115.2k baud)
    USART5->BRR = 0x1A1; // look at table 96 of the family reference manual

    // enable transmitter and the receiver by setting the TE and RE bits
    USART5->CR1 |= USART_CR1_TE;
    USART5->CR1 |= USART_CR1_RE;

    // enable the USART
    USART5->CR1 |= USART_CR1_UE;

    // wait for the TE and RE bits to be acknowledged by checking the TEACK and REACK bits are both set in the ISR
    // indicates that the USART is ready to transmit and receive
    USART5->ISR |= USART_ISR_TEACK;
    USART5->ISR |= USART_ISR_REACK;

}

void enable_ports(void) {
    // Only enable port C for the keypad
    RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
    GPIOC->MODER &= ~0xffff;
    GPIOC->MODER |= 0x55 << (4*2);
    GPIOC->OTYPER &= ~0xff;
    GPIOC->OTYPER |= 0xf0;
    GPIOC->PUPDR &= ~0xff;
    GPIOC->PUPDR |= 0x55;



}



int main(void)
{
	init_usart5();

	for(;;);
		check_keypad();
		while (!(USART5->ISR & USART_ISR_RXNE)) { }
	    char c = USART5->RDR;
	    while(!(USART5->ISR & USART_ISR_TXE)) { }
	    USART5->TDR = c;
}
