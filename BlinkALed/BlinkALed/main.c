/*
 * BlinkALed.c
 *
 * Created: 01.12.2017 14:28:23
 * Author : st118796
 */ 
 #define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* LED A3 als Ausgang */
    DDRB = 0x02;
	/* Sensor Bandanfang und Bandende als Eingang definieren */
	DDRD = 0x00;
	PORTD = 0x0C;
	
	while(1)
	{
		if ((PIND & 0x08) == 0)
		{
			PORTB = 0x02; // LED einschalten Mode 1
			_delay_ms(200);
			PORTB = 0x00;
			_delay_ms(100);
		}
		else
		{
			PORTB = 0x02; // LED Mode 2
			_delay_ms(1000);
			PORTB = 0x00;
			_delay_ms(500);
		}
	}
}

