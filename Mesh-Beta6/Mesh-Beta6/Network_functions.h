/*
 * Network_functions.h
 *
 * Created: 6/26/2020 1:29:03 PM
 *  Author: Michael
 * Functions for setting up the network and sending messages
 */ 

void COMMAND_HANDLER(uint8_t*);


void setup_network(/*uint8_t**/); 
void continue_setup(uint8_t);

void ping_handler(uint8_t*);
void echo_handler(uint8_t*);

void set_downstairs_neighbor(uint8_t*);
void set_upstairs_neighbor(uint8_t*);
void set_last_node(uint8_t*);

void confirm_network_complete();

void probe_neighbor_status(uint16_t);
void confirm_neighbor(uint8_t*);

void send_message(uint16_t,uint8_t*);
void wait_for_response(uint8_t*);
void send_downstream(uint8_t*);
void send_upstream(uint8_t*);
void send_directly_to_pi(uint8_t*);
void send_down_to_pi(uint8_t*);

void set_light(uint8_t*);

void get_adc_data(uint8_t*);
void collect_data(uint8_t*);
