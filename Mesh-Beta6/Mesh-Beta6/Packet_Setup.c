/*
 * Packet_Setup.c
 *
 *  Created: 5/28/2020 11:58:29 AM
 *  Author: Michael
 *  Functions for reading/writing to the information packages
 */ 
#include <avr/io.h>
#include <string.h>
#include "Packet_Setup.h"
#include "bitmanip.h"
#include "packet_specs.h"


void clear_buffer(uint8_t* buff)
{
	uint8_t buff_size = sizeof(buff);
	memset(buff,0,buff_size);
}
void clear_data(uint8_t* buff)
{
	uint8_t data_size = sizeof(buff);
	memset(&buff[PK_DATA_START],0,data_size-PK_DATA_START);
}
void Pk_Set_Packet_Size(uint8_t* buff, uint8_t sz)
{
	buff[PK_COMMAND_HEADER + PK_SZ_PACKET] = sz;
}

void Pk_Set_Target_Node(uint8_t* buff, uint16_t target_node)
{
	word_to_bytes(&buff[PK_DEST_ADDR_HI],target_node);
}

void Pk_Set_Final_Node(uint8_t* buff, uint16_t target)
{
	word_to_bytes(&buff[PK_FINAL_ADDR_HI],target);
}

/*Pk_Set_Data_Direction(uint8_t* buff, uint8_t direction)
{
	buff[PK_COMMAND_HEADER+PK_DATA_DIRECTION] = direction;
}*/

void Pk_Set_Command(uint8_t* buff, uint16_t cmd_id, uint8_t cmd2, uint8_t cmd3, uint8_t cmd4, uint8_t cmd5)
{
	word_to_bytes(&buff[PK_COMMAND_HEADER+PK_CMD_HI],cmd_id);
	buff[PK_COMMAND_HEADER+PK_CMD_DATA_0] = cmd2;
	buff[PK_COMMAND_HEADER+PK_CMD_DATA_1] = cmd3;
	buff[PK_COMMAND_HEADER+PK_CMD_DATA_2] = cmd4;
	buff[PK_COMMAND_HEADER+PK_CMD_DATA_3] = cmd5;
}

void Pk_Set_Src_Node(uint8_t* buff, uint16_t origin)
{
	//used for setting where this particular packet is coming from: the source of "data" would be held
	//later in the packet, in the data bytes.
	word_to_bytes(&buff[PK_SRC_ADDR_HI],origin);
}

void Pk_Add_Data(uint8_t* buff, uint16_t data, uint8_t data_location)
{   //adds data in two byte elements to the data_start area
	//TODO: incorporate "hop count"?
	word_to_bytes(&buff[PK_DATA_START+data_location*3],data);
	//location*2 to separate data [0,1],[1,2],[3,4] etc.
}

void Pk_Set_Hop_Count(uint8_t* buff, uint8_t hop_count)
{
	buff[PK_COMMAND_HEADER+PK_HOP_COUNT] = hop_count;
}