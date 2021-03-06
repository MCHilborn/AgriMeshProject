/*
 * pktspec.h
 *
 * Created: 2019-02-08 2:00:56 PM
 *  Author: hoyla
 */ 


#ifndef PKTSPEC_H_
#define PKTSPEC_H_

/*
	Defines the structure of the messages sent on the network
*/


#define PK_SZ_TXRX_BUFFER 40
#define PK_SZ_TX_BUFFER aMaxPHYPacketSize
#define PK_SZ_RX_BUFFER aMaxPHYPacketSize
#define PK_SZ_ERR_BUFFER 24

// Addressing header bytes
#define PK_SZ_ADDR_HEADER 4
//#define PK_DEST_PANID_HI 0 //sending to this node
//#define PK_DEST_PANID_LO 1
#define PK_DEST_ADDR_HI 0
#define PK_DEST_ADDR_LO 1
#define PK_FINAL_ADDR_HI 2 //final address for message
#define PK_FINAL_ADDR_LO 3
//#define PK_SRC_PANID_HI 4
//#define PK_SRC_PANID_LO 5
#define PK_SRC_ADDR_HI 4	
#define PK_SRC_ADDR_LO 5	

#define PK_COMMAND_HEADER 6

// Command header bytes
#define PK_SZ_CMD_HEADER 8		
#define PK_HOP_COUNT 0				// Hop count is used to count number of nodes the message is passed over
#define PK_SZ_PACKET 1				// Size of the entire message including the header
#define PK_CMD_HI 2					// MSB of the command word
#define PK_CMD_LO 3					// LSB of the command word
#define PK_CMD_DATA_0 4				// Command data bytes: 0 is req_id
#define PK_CMD_DATA_1 5				//     These four bytes are used for command specific arguments.
#define PK_CMD_DATA_2 6				//	   All four bytes must be sent even if not needed for the specific message
#define PK_CMD_DATA_3 7				//
#define PK_ADC_CHANNEL 8			//Specifies ADC channel to read from
// Body
#define PK_DATA_START 15			// Actual data starts here

#define PK_DATUM_SIZE 3				// Size of individual data item. Three bytes are used to pack 2 x 12 bit values representing mean and sd.


#endif /* INCFILE1_H_ */