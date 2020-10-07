/*
 * pktspec.h
 *
 * Created: 2019-02-08 2:00:56 PM
 *  Author: hoyla
 */ 


#ifndef PKTSPEC_H_
#define PKTSPEC_H_


#define PK_SZ_TXRX_BUFFER 40
#define PK_SZ_ERR_BUFFER 24

// Addressing header bytes
#define PK_SZ_ADDR_HEADER 8
#define PK_DEST_PANID_HI 0
#define PK_DEST_PANID_LO 1
#define PK_DEST_ADDR_HI 2
#define PK_DEST_ADDR_LO 3
#define PK_SRC_PANID_HI 4
#define PK_SRC_PANID_LO 5
#define PK_SRC_ADDR_HI 6	// column no
#define PK_SRC_ADDR_LO 7	// row no

#define PK_COMMAND_HEADER 8

// Command header bytes
#define PK_SZ_CMD_HEADER 8		
#define PK_HOP_COUNT 0				// Hop count is used to count number of nodes the message is passed over
#define PK_SZ_PACKET 1				// Size of the entire message including the header
#define PK_CMD_HI 2					// MSB of the command word
#define PK_CMD_LO 3					// LSB of the command word
#define PK_CMD_DATA_0 4				// Command data bytes: 
#define PK_CMD_DATA_1 5				//     These four bytes are used for command specific arguments.
#define PK_CMD_DATA_2 6				//	   All four bytes must be sent even if not needed for the specific message
#define PK_CMD_DATA_3 7				//

// Body
#define PK_DATA_START 16			// Actual data starts here

#define PK_DATUM_SIZE 3				// Size of individual data item. Three bytes are used to pack 2 x 12 bit values representing mean and sd.


#endif /* INCFILE1_H_ */