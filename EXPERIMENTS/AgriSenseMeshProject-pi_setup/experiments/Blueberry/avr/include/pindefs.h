#ifndef __PINDEFS_H
#define __PINDEFS_H

/* Pinout definitions for MCU */

// Diagnostic LED pins

#define LED_PORT    PORTD	/* + */
#define LED_3       PD5    /*+REMOTE LED   GREEN*/
#define LED_2       PD6    /*+LOCAL LED 		YELLOW*/
#define LED_1		PD7		/*+ RED */


// MRF24J40 wifi pins


#define MRF_INT     PD2		// <-- Interrupt line
#define MRF_WAKE    PD3		// --> Wake line (for waking MRF)
#define MRF_RESET   PD4		// --> Reset line

#define MRF_RESET_PORT PORTD

// SPI Pins
#define SPI_MOSI    PB3		// --> SPI MOSI line
#define SPI_MISO    PB4		// <-- SPI MISO line
#define SPI_SCK     PB5		// --> SPI Clock line

// SPI Chip select lines
#define MRF_CS      PB2		// --> For wireless transceiver
#define ADC_CS 		PB7		// --> For ADC

#endif