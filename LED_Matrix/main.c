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
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
			
void init_usart1();
void send_message();
void USART_stole();

void init_usart1() {
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // enables port B
	GPIOB->MODER |= 0x0000a000; //Configures Ports PB6 and PB7 for AFR

	// https://www.mouser.com/datasheet/2/389/dm00115237-1798191.pdf
	// tables 14-19
	// check for what pins can be connected to the USART's voia AFR's
	//
	// PC12 + USART5_TX = AF2
	// PD2 + USART5_RX = AF2
    // configure alternate function for AF2, need 0010 for AF2
	// AFR[0] -> AFRL
	// AFR[1] -> AFRH
	GPIOB->AFR[0] |= 0x77000000; // 0010 is AF2, and shift 16 bits left to reference pin 12

	// enable clock for USART
	RCC->APB2ENR |= RCC_APB2ENR_USART1EN;

	// disable USART5 by turning off UE bit
	USART1->CR1 &= ~(USART_CR1_UE);

	// set word size of 8 bits
	USART1->CR1 &= ~(USART_CR1_M);

	// set for one stop bit
	USART1->CR2 &= ~(USART_CR2_STOP);

	// set it for no parity
	USART1->CR1 &= ~(USART_CR1_PCE);

	// use 16x oversampling
	USART1->CR1 &= ~(USART_CR1_OVER8);

	// baud rate of 19200 (19.2k baud)
	USART1->BRR = 0x9C4; // look at table 96 of the family reference manual

	// enable transmitter and the receiver by setting the TE and RE bits
	USART1->CR1 |= USART_CR1_TE;
	USART1->CR1 |= USART_CR1_RE;

	// enable the USART
	USART1->CR1 |= USART_CR1_UE;

	// wait for the TE and RE bits to be acknowledged by checking the TEACK and REACK bits are both set in the ISR
	// indicates that the USART is ready to transmit and receive
	USART1->ISR |= USART_ISR_TEACK;
	USART1->ISR |= USART_ISR_REACK;
}

void USART_stole() {
	RCC->AHBENR |= RCC_AHBENR_GPIOBEN; // enables port B
	GPIOB->MODER |= 0x0000a000; //Configures Ports PB6 and PB7 for AFR
	GPIOB->AFR[0] |= 0x77000000;

	USART_InitTypeDef USART_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);

	/* Configure USART1 */
	USART_InitStruct.USART_BaudRate = 19200;
	USART_InitStruct.USART_WordLength = USART_WordLength_8b;
	USART_InitStruct.USART_StopBits = USART_StopBits_1;
	USART_InitStruct.USART_Parity = USART_Parity_No;
	USART_InitStruct.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStruct.USART_Mode = USART_Mode_Tx;
	USART_Init(USART1, &USART_InitStruct);

	/* Enable USART1 */
	USART_Cmd(USART1, ENABLE);
}

void send_message(void) {
	USART_SendData(USART1, 0xFE);
	USART_SendData(USART1, 0x42);
	USART_SendData(USART1, 0x8A);
	USART_SendData(USART1, 0xA0);
	USART_SendData(USART1, 0xCA);
	USART_SendData(USART1, 0x32);
	USART_SendData(USART1, 0xAC);
	USART_SendData(USART1, 0xA0);
	//Last Universal
	USART_SendData(USART1, 0x08);
	USART_SendData(USART1, 0x02);
	USART_SendData(USART1, 0x00);
	USART_SendData(USART1, 0x98);
	USART_SendData(USART1, 0x28);
	USART_SendData(USART1, 0x2A);
	USART_SendData(USART1, 0x0A);
	USART_SendData(USART1, 0xCC);
	USART_SendData(USART1, 0xA0);
	USART_SendData(USART1, 0xA0);
	USART_SendData(USART1, 0x08);
	USART_SendData(USART1, 0x32);
	USART_SendData(USART1, 0x42);

}



int main(void)
{
	//init_usart1();
	USART_stole();
	/*for(;;) {

		if ((USART1->ISR & USART_ISR_TC) == USART_ISR_TC)
		{
			if (send == sizeof(stringtosend))
			{
				send=0;
				//USART1->ICR |= USART_ICR_TCCF;
			}
			else
			{
				// clear transfer complete flag and fill TDR with a new char
				USART1->TDR = stringtosend[send++];
			}
		}
	}*/
	send_message();
	while (1){
		USART_SendData(USART1, 0xFF);
	}
}
