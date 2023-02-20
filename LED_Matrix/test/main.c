/**
  ******************************************************************************
  * @file    main.c
  * @author  Weili An
  * @version V1.0
  * @date    Nov 26, 2022
  * @brief   ECE 362 Lab 11 student template
  ******************************************************************************
*/


#include "stm32f0xx.h"
#include <stdint.h>

// Uncomment only one of the following to test each step
#define STEP41
//#define STEP42
//#define STEP43
//#define STEP44

void init_usart5();
void send_message(void);

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

void send_message(void) {
	while(!(USART5->ISR & USART_ISR_TXE)) { }
	USART_SendData(USART1, 0xFE);
	while(!(USART5->ISR & USART_ISR_TXE)) { }
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

#ifdef STEP41
int main(void){
    init_usart5();
    send_message();
    for(;;) {
        while (!(USART5->ISR & USART_ISR_RXNE)) { }
        char c = USART5->RDR;
        while(!(USART5->ISR & USART_ISR_TXE)) { }
        USART5->TDR = c;
    }
}
#endif

#ifdef STEP42
#include <stdio.h>

// TODO Resolve the echo and carriage-return problem

int __io_putchar(int c) {
    while(!(USART5->ISR & USART_ISR_TXE));
    if (c == '\n'){
        USART5->TDR = '\r';
    }
    while(!(USART5->ISR & USART_ISR_TXE));
    USART5->TDR = c;
    return c;
}

int __io_getchar(void) {
    while (!(USART5->ISR & USART_ISR_RXNE));
    char c = USART5->RDR;
    if (c == '\r') {
        c = '\n';
    }
    c = __io_putchar(c);
    return c;
}

int main() {
    init_usart5();
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);
    printf("Enter your name: ");
    char name[80];
    fgets(name, 80, stdin);
    printf("Your name is %s", name);
    printf("Type any characters.\n");
    for(;;) {
        char c = getchar();
        putchar(c);
    }
}
#endif

#ifdef STEP43
#include <stdio.h>
#include "fifo.h"
#include "tty.h"
int __io_putchar(int c) {
    // TODO Copy from your STEP42
    while(!(USART5->ISR & USART_ISR_TXE));
    if (c == '\n'){
        USART5->TDR = '\r';
    }
    while(!(USART5->ISR & USART_ISR_TXE));
    USART5->TDR = c;
    return c;
}

int __io_getchar(void) {
    // TODO
    int c = line_buffer_getchar();
    return c;
}

int main() {
    init_usart5();
    setbuf(stdin,0);
    setbuf(stdout,0);
    setbuf(stderr,0);
    printf("Enter your name: ");
    char name[80];
    fgets(name, 80, stdin);
    printf("Your name is %s", name);
    printf("Type any characters.\n");
    for(;;) {
        char c = getchar();
        putchar(c);
    }
}
#endif

#ifdef STEP44

#include <stdio.h>
#include "fifo.h"
#include "tty.h"

// TODO DMA data structures
#define FIFOSIZE 16
char serfifo[FIFOSIZE];
int seroffset = 0;

void enable_tty_interrupt(void) {
    // TODO
    // Raise an interrupt every time the receive data register becomes not empty
    // Remember to set the proper bit in the NVIC ISER as well
    // Note that the name of the bit to set is difficult to determine. It is USART3_8_IRQn
    USART5->CR1 |= USART_CR1_RXNEIE;

    // Trigger a DMA operation every time the receive data register becomes not empty
    USART5->CR3 |= USART_CR3_DMAR;
    NVIC->ISER[0] = 1<<USART3_8_IRQn; // same as 29

    // The subroutine should also enable the RCC clock for DMA Controller 2
    RCC->AHBENR |= RCC_AHBENR_DMA2EN;
    DMA2->RMPCR |= DMA_RMPCR2_CH2_USART5_RX;
    DMA2_Channel2->CCR &= ~DMA_CCR_EN;  // First make sure DMA is turned off

    // CMAR should be set to the address of serfifo
    DMA2_Channel2->CMAR = (uint32_t)(serfifo); // configure memory address

    // CPAR should be set to the address of the USART5->RDR
    DMA2_Channel2->CPAR = (uint32_t)(&(USART5->RDR)); // Set CPAR to the address of the USART5->RDR register.

    // CNDTR should be set to FIFOSIZE
    DMA2_Channel2->CNDTR = FIFOSIZE;

    // The DIRection of copying should be from peripheral to memory
    DMA2_Channel2->CCR &= ~DMA_CCR_DIR; // this sets it so it reads from peripheral

    // Neither the total-completion nor the half-transfer interrupt should be enabled
    DMA2_Channel2->CCR &= ~DMA_CCR_HTIE; // no total completion
    DMA2_Channel2->CCR &= ~DMA_CCR_TCIE; // no half transfer

    // Both the MSIZE and the PSIZE should be set for 8 bits
    //set memory datum size to 8bit
    DMA2_Channel2->CCR &= ~DMA_CCR_MSIZE; // clears out the bits for msize
    //set peripheral datum size to 8bit
    DMA2_Channel2->CCR &= ~DMA_CCR_PSIZE; // clears out the bits for psize

    // MINC should be set to increment the CMAR
    DMA2_Channel2->CCR |= DMA_CCR_MINC; // increments the CMAR for every transfer

    // PINC should not be set so that CPAR always points at the USART5->RDR.
    DMA2_Channel2->CCR &= ~DMA_CCR_PINC; // peripheral increment mode disabled

    // Enable CIRCular transfers.
    DMA2_Channel2->CCR |= DMA_CCR_CIRC; //Set the channel for CIRCular operation.

    // Do not enable MEM2MEM transfers.
    DMA2_Channel2->CCR &= ~DMA_CCR_MEM2MEM; // memory to memory mode disabled

    // Set the Priority Level to highest.
    DMA2_Channel2->CCR |= DMA_CCR_PL;

    //Finally, make sure that the channel is enabled for operation.
    DMA2_Channel2->CCR |= DMA_CCR_EN; // enable DMA

}

// Works like line_buffer_getchar(), but does not check or clear ORE nor wait on new characters in USART
char interrupt_getchar() {
    // TODO

    // USART_TypeDef *u = USART5;

    /*
    // If we missed reading some characters, clear the overrun flag.
    if (u->ISR & USART_ISR_ORE)
        u->ICR |= USART_ICR_ORECF;
    */

    // Wait for a newline to complete the buffer.
    while(fifo_newline(&input_fifo) == 0) {
        asm volatile ("wfi"); // wait for an interrupt
        /*
        while (!(u->ISR & USART_ISR_RXNE))
            ;
        insert_echo_char(u->RDR);
        */
    }
    // Return a character from the line buffer.
    char ch = fifo_remove(&input_fifo);
    return ch;
}

int __io_putchar(int c) {
    // TODO Copy from step 42
    while(!(USART5->ISR & USART_ISR_TXE));
    if (c == '\n'){
        USART5->TDR = '\r';
    }
    while(!(USART5->ISR & USART_ISR_TXE));
    USART5->TDR = c;
    return c;
}

int __io_getchar(void) {
    // TODO Use interrupt_getchar() instead of line_buffer_getchar()
    int c = interrupt_getchar();
    return c;
}

// TODO Copy the content for the USART5 ISR here
// TODO Remember to look up for the proper name of the ISR function
// name from startup_stm32.s
void USART3_4_5_6_7_8_IRQHandler(void) {
    while(DMA2_Channel2->CNDTR != sizeof serfifo - seroffset) {
        if (!fifo_full(&input_fifo))
            insert_echo_char(serfifo[seroffset]);
        seroffset = (seroffset + 1) % sizeof serfifo;
    }
}

int main() {
    init_usart5();
    enable_tty_interrupt();
    setbuf(stdin,0); // These turn off buffering; more efficient, but makes it hard to explain why first 1023 characters not dispalyed
    setbuf(stdout,0);
    setbuf(stderr,0);
    printf("Enter your name: "); // Types name but shouldn't echo the characters; USE CTRL-J to finish
    char name[80];
    fgets(name, 80, stdin);
    printf("Your name is %s", name);
    printf("Type any characters.\n"); // After, will type TWO instead of ONE
    for(;;) {
        char c = getchar();
        putchar(c);
    }
}
#endif
