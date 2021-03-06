/*
 * MRFcommExperiment.c
 *
 * Created: 10/18/2019 6:21:46 PM
 * Author : Michael
 * This program will simply send a message to another node, which will light up when the message is sent
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "PinDefs_1_31_2020.h"
#include "mrf24j.h"
#include "blinkin.h"
#include "tinyspi.h"

#define BUTTON_PIN PIND
#define BUTTON PD0

#define THIS_DEVICE 0x0031
#define DEVICE_13 0x0013
#define ASMP_PANID 0xcafe //sets ID for entire network

uint16_t message; //this is the message that will be sent

void setup()
{
	DDRD |= (1 << RED_LIGHT); //set PD7 to output for LED
	DDRD |= (1 << GREEN_LIGHT);
	DDRD |= (1 << BLUE_LIGHT);
	DDRD &= ~(1<<BUTTON); //set PD0 as input for the button
	
	PORTB |= (1<<SPI_MOSI) | (1<<SPI_SCK) | (1<<ADC_CS) | (1<<SPI_SS) |(1<<MRF_CS); //set these ports to high (required)
	DDRB |= (1<<SPI_MOSI) | (1<<SPI_SCK) | (1<<ADC_CS) | (1<<SPI_SS) |(1<<MRF_CS);  //set these to output

	DDRB &= ~(1<<SPI_MISO);	//master in slave out, input on attiny
	
	
	BLINK(LIGHT_PORT,GREEN_LIGHT);
	spi_setup();
	BLINK(LIGHT_PORT,GREEN_LIGHT);
	BLINK(LIGHT_PORT,BLUE_LIGHT);
	mrf_reset();
	BLINK(LIGHT_PORT,RED_LIGHT);
	mrf_init(); //takes a very long time
	BLINK(LIGHT_PORT,RED_LIGHT);
	
	mrf_set_pan(ASMP_PANID);
	mrf_address16_write(THIS_DEVICE); //do I need this??
	EIMSK |= (1<<INT0);
	EICRA |= (1<<ISC01);
	sei(); //starts interrupts, essential to let chip know message is being handled
}

ISR(INT0_vect) {
	//running_status |= (1<<RU_INTERRUPT);
	mrf_interrupt_handler(); // mrf24 object interrupt routine
	//running_status &= ~(1<<RU_INTERRUPT);
}

uint8_t pollButton()
{
	if(BUTTON_PIN & (1<<BUTTON)) return 0;
	else return 1;
}

void handle_rx(){
	if(mrf_get_bufferPHY()){} //not needed
	
	uint8_t * rx_data = mrf_get_rxdata();
	
	//look at the rx_data and make a decision
}

void handle_tx(){ //a successful transmission involves sending and receiving a message.
	//This loop never seems to happen??
	if(mrf_tx_ok()){
		BLINK(LIGHT_PORT,BLUE_LIGHT);
		BLINK(LIGHT_PORT,GREEN_LIGHT);
	}
	else{
		//transmitted and not received acknowledgment
		BLINK(LIGHT_PORT,RED_LIGHT);
		BLINK(LIGHT_PORT,BLUE_LIGHT);
		BLINK(LIGHT_PORT,RED_LIGHT);
	}
}

int main(void)
{
	setup();

    /* Replace with your application code */
    while (1) 
    {
		mrf_check_flags(&handle_rx, &handle_tx);
		if(!pollButton())
		{
			//BLINK(LIGHT_PORT,GREEN_LIGHT);
			message = 31; //might need to typecast message to 8 bit pointer
			mrf_send16(DEVICE_13,(uint8_t*)&message,2); //send the message to device 32.
			//BLINK(LIGHT_PORT,GREEN_LIGHT);
			mrf_check_flags(&handle_rx, &handle_tx); //when should this be inserted?
		}
	}
}


