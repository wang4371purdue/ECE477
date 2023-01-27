/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/
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
			

// NOTES FOR LCD
/*
 *  *   Wiring Reference:
 *   - 1 FG - ground
 *   - 2 VSS - ground (need resistor/potentiometer?)
 *   - 3 VDD - 5V
 *   - 4 V0 - (not needed unless we want contrast?)
 *   - 5 VEE - (not needed unless we want contrast?)
 *   - 6 /WR -
 *   - 7 /RD -
 *   - 8 /CE - ground
 *   - 9 C/D -
 *   - 10 /HALT -
 *   - 11 /RES -
 *   - 12 DB0 - A0
 *   - 13 DB1 - A1
 *   - 14 DB2 - A2
 *   - 15 DB3 - A3
 *   - 16 DB4 - A4
 *   - 17 DB5 - A5
 *   - 18 DB6 - A6
 *   - 19 DB7 - A7
 *   - A LED+ - 3.5V
 *   - K LED- - ground
 */

// CD: high will set command, low will set data
// WR: high will disable writing. low will enable write
// RD: read signal (active low)
// RES: reset signal (active low) I think you write it low then high to do a hardware reset
// HALT: clock stop signal (active low)

// command designates the area that can be edited
// data actaully writes it?

/* example process:
 *
 */



/**
 * @brief Set the C/D signal HIGH to indicate
 *        command bytes to be sent.
 *
 * @return none
 */

void enable_ports() {
	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;

	GPIOA->MODER &= ~0xffffffff;
	GPIOA->MODER |= 0x00555555;

}

static void nano_wait(unsigned int n) {
    asm(    "        mov r0,%0\n"
            "repeat: sub r0,#83\n"
            "        bgt repeat\n" : : "r"(n) : "r0", "cc");
}

void setCommand()
{
        GPIOA->ODR |= GPIO_ODR_10;
}

/**
 * @brief Set the C/D signal LOW to indicate
 *        data bytes to be sent.
 *
 * @return none
 */
void setData()
{
	GPIOA->ODR &= ~GPIO_ODR_10;
}

/**
 * @brief Set the WR signal LOW to indicate
 *        a write sequence is occuring.
 *
 * @return none
 */
void enableWrite()
{
	GPIOA->ODR &= ~GPIO_ODR_8;
}

/**
 * @brief Set the WR signal HIGH to indicate
 *        that writing is disabled.
 *
 * @return none
 */
void disableWrite()
{
	GPIOA->ODR |= GPIO_ODR_8;
}

/**
 * @brief Toggle the WR signal LOW to HIGH to
 *        latch data.
 *
 * @return none
 */
void dataLatch()
{
	enableWrite();
	nano_wait(1);
	disableWrite();
	nano_wait(1);

  //enableWrite();
  //delay(1);
  //disableWrite();
  //delay(1);
}

/**
 * @brief Send a command byte to the display.
 *
 * @param command Command byte to be sent.
 * @return none
 */
void comm_out(uint8_t command)
{
  setCommand();
  GPIOA->ODR &= ~0xff;
  GPIOA->ODR |= command;
  //PORTA = command; // Put command byte on port A (D22-D29)
  dataLatch();
}

/**
 * @brief Send a data byte to the display.
 *
 * @param data Data byte to be sent.
 * @return none
 */
void data_out(uint8_t data)
{
	setCommand();
	GPIOA->ODR &= ~0xff;
	GPIOA->ODR |= data;
	  //PORTA = command; // Put command byte on port A (D22-D29)
	dataLatch();
}

/**
 * @brief Perform a hardware reset on the display.
 *
 * @return none
 */
void reset()
{
	GPIOA->ODR &= ~GPIO_ODR_11;
  //digitalWrite(_RES, LOW);
	nano_wait(100);
    GPIOA->ODR |= GPIO_ODR_11;
  //digitalWrite(_RES, HIGH);
    nano_wait(100);
}

void initLCD()
{
	enable_ports();
	GPIOA->ODR = GPIO_ODR_11 | GPIO_ODR_10 | GPIO_ODR_9 | GPIO_ODR_8;
	// calls setCommand sets port A and calls dataLatch
	reset();
	data_out(0x00);
	data_out(0x00);
	comm_out(0x40);      //text home address
	data_out(0x00);
	data_out(0x40);

	comm_out(0x42);      //graphic home address
	data_out(0x1E);
	data_out(0x00);

	comm_out(0x41);      //text area
	data_out(0x1E);
	data_out(0x00);

	comm_out(0x43);      //graphic area

	comm_out(0x80);      //OR mode

	nano_wait(100);
}

void drawVerticalBars()
{
	comm_out(0x98); //graphics ON, text OFF
	data_out(0x00);
	data_out(0x40);
	comm_out(0x24); //set address pointer = 0x0040 (first pixel)

	comm_out(0xB0); //auto write ON

	int width = 160;
	int height = 128;
	int pixelsPerByte = 8;
	//fill screen with vertical bars
	for (unsigned int i = 0; i < (width / pixelsPerByte) * height; i++)
	{
	  data_out(0x1C); // Send graphical data
	}
	comm_out(0xB2); //auto write OFF
}

void loop()
{

}

int main(void)
{
	// setup
	initLCD();

	while(1)
	{
		nano_wait(100000000);
		GPIOA->ODR &= ~0xff;
		GPIOA->ODR |= 0xc0;
	}

}
