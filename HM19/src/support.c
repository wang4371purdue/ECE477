#include "stm32f0xx.h"

void drive_column(int c)
{
    GPIOC->BSRR = 0xf00000 | ~(1 << (c + 4));
}

int read_rows()
{
    return (~GPIOC->IDR) & 0xf;
}

char check_keypad()
{
	char output;
    for(int c=0; c<4; c++) {

        drive_column(c);
        nano_wait(5000000); // wait 1 ms
        int r = read_rows();
        if (c==3) { // leftmost column

        	if (r & 8) { // '1'
        		output = '1';
        	}
        	if (r & 4) { // '4'
        		output = '4';
        	}
        	if (r & 2) { // '7'
        		output = '7';
        	}
        	if (r & 0) { // '*'
        		output = '*';
        	}

        } else if (c == 2) { // column 2
            if (r & 8) { // '2'
            	output = '2';
            }
            if (r & 4) { // '5'
            	output = '5';
            }
            if (r & 2) { // '8'
            	output = '8';
            }
            if (r & 0) { // '0'
            	output = '0';
            }
        } else if (c == 1) { // column 3
        	if (r & 8) { // '3'
        		output = '3';
        	}
            if (r & 4) { // '6'
            	output = '6';
            }
            if (r & 2) { // '9'
            	output = '9';
            }
            if (r & 0) { // '#'
            	output = '#';
            }

        }
        else if (c == 1) {
        	if (r & 8) { // 'A'
        		output = 'A';
        	}
        	if (r & 4) { // 'B'
        		output = 'B';
        	}
        	if (r & 2) { // 'C'
        		output = 'C';
        	}
        	if (r & 0) { // 'D'
        		output = 'D';
        	}
        }

    }
    return output;
}
