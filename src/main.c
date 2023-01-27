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
void setCommand()
{
        //C/D = H = command
}

/**
 * @brief Set the C/D signal LOW to indicate
 *        data bytes to be sent.
 *
 * @return none
 */
void setData()
{
       //C/D = L = data
}

/**
 * @brief Set the WR signal LOW to indicate
 *        a write sequence is occuring.
 *
 * @return none
 */
void enableWrite()
{

}

/**
 * @brief Set the WR signal HIGH to indicate
 *        that writing is disabled.
 *
 * @return none
 */
void disableWrite()
{

}

/**
 * @brief Toggle the WR signal LOW to HIGH to
 *        latch data.
 *
 * @return none
 */
void dataLatch()
{
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
void comm_out(unsigned char command)
{
  setCommand();

  //PORTA = command; // Put command byte on port A (D22-D29)
  dataLatch();
}

/**
 * @brief Send a data byte to the display.
 *
 * @param data Data byte to be sent.
 * @return none
 */
void data_out(unsigned char data)
{
  setData();

  //PORTA = data; // Put data byte on port A (D22-D29)
  dataLatch();
}

/**
 * @brief Perform a hardware reset on the display.
 *
 * @return none
 */
void reset()
{
  //digitalWrite(_RES, LOW);
  //delay(100);
  //digitalWrite(_RES, HIGH);
  //delay(100);
}

void initLCD()
{

}

int main(void)
{
	// setup
	initLCD();

}
