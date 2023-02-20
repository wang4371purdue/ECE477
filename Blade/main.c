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
#include "main.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>

static int target = -1;

static void nano_wait(unsigned int n) {
    asm(    "        mov r0,%0\n"
            "repeat: sub r0,#83\n"
            "        bgt repeat\n" : : "r"(n) : "r0", "cc");
}

void enable_ports(void) {
    // Only enable port B for the Blade
    RCC->AHBENR |= RCC_AHBENR_GPIOBEN | RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOCEN;
    GPIOB->MODER &= ~0xffffffff;
    GPIOB->MODER |= 0x00550000;
    GPIOA->MODER &= ~0x000fffff;
    GPIOA->MODER |= 0x00050000;
    GPIOB->PUPDR |= 0xaaaaaaa;
    GPIOA->PUPDR |= 0xaaaaaaa;
    GPIOC->MODER |= 0xffffffff;
    GPIOC->MODER &= ~0xffffffff;
    //GPIOC->PUPDR |= 0x55555555;
    //GPIOB->PUPDR |= 0x55555595;
    //GPIOB->PUPDR |= 0x00000040;
}


int main(void)
{
	enable_ports();
	//enable_TIM2();
	//TIM2->CR1 |= 0x1;
	while(1){

		play_game();
		nano_wait(500);
	}
}

void enable_TIM2(void){


	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC = 48000 - 1;
	TIM2->ARR = 500 - 1;
	TIM2->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM2_IRQn);
	NVIC_SetPriority(TIM2_IRQn, 29);
	TIM2->CR1 = TIM_CR1_CEN;
}

void TIM2_IRQHandler(void) {
	TIM2->SR = ~TIM_SR_UIF;
	play_game();
}


void play_game(void){
	uint32_t hit;
	if (target == -1) {
		pick_target();
	}
	else if (target == 1){
		GPIOB->ODR = 0x0100;
		hit = GPIOC->IDR;
		hit = hit & ~0xfff0;
		if (hit != 0x000f){
			if (hit == 0x0007) {
				GPIOA->ODR = 0x0100;
				pick_target();
			}
			else {
				GPIOA->ODR = 0x0200;
				nano_wait(500);
			}
		}
	}
	else if (target == 2){
		GPIOB->ODR = 0x0200;
		hit = GPIOC->IDR;
		hit = hit & ~0xfff0;
		if (hit != 0x000f){
			if (hit == 0x000b) {
				GPIOA->ODR = 0x0100;
				pick_target();
			}
			else {
				GPIOA->ODR = 0x0200;
			}
		}

	}
	else if (target == 3){
		GPIOB->ODR = 0x0400;
		hit = GPIOC->IDR;
		hit = hit & ~0xfff0;
		if (hit != 0x000f){
			if (hit == 0x000d) {
				GPIOA->ODR = 0x0100;
				pick_target();
			}
			else {
				GPIOA->ODR = 0x0200;
			}
		}
	}
	else if (target == 4){
		GPIOB->ODR = 0x0800;
		hit = GPIOC->IDR;
		hit = hit & ~0xfff0;
		if (hit != 0x000f){
			if (hit == 0x000e) {
				GPIOA->ODR = 0x0100;
				pick_target();
			}
			else {
				GPIOA->ODR = 0x0200;
			}
		}
	}
}

int randomX(){
    return ((rand() % (4)) + 1) ;
}

void pick_target(void){
	target = randomX();
	if (target == 1){
		GPIOB->ODR = 0x0100;
	}
	if (target == 2){
		GPIOB->ODR = 0x0200;
	}
	if (target == 3){
		GPIOB->ODR = 0x0400;
	}
	if (target == 4){
		GPIOB->ODR = 0x0800;
	}
}

