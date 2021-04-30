/**
 * @file Activity4.c
 * @author 255974 (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <avr/io.h>
#define F_CPU 1600000UL
#include <util/delay.h>
#include "Activity2.h"
#include "Activity3.h"
#include "Activity4.h"

void initUART(uint16_t ubrr_value){

    UBRR0L = ubrr_value;
    UBRR0H = (ubrr_value>>8)&(0x00ff);
    UCSR0C = (1<<UMSEL00)|(1<<UCSZ01)|(1<<UCSZ01);

    UCSR0B = (1<<RXEN0)|(1<<TXEN0)|(1<<RXCIE0)|(1<<TXCIE0);

}


void writeCharUART(char input_UART){

while(!(UCSR0A & (1<<UDRE0))){

}
UDR0 = input_UART;

}