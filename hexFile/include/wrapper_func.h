/*
 * wrapper_func.h
 *
 * Created: 2/7/2017 3:11:52 PM
 *  Author: colab
 */ 

#ifndef WRAPPER_FUNC_H_
#define WRAPPER_FUNC_H_

#include <stdint.h>
#include "user_template.h"
#include "droplet_init.h"
// typedef struct ir_msg_struct
// {
// 	uint32_t arrival_time;	// Time of message receipt.
// 	float range;
// 	float bearing;
// 	float heading;
// 	uint16_t sender_ID;		// ID of sending robot.
// 	char* msg;				// The message.
// 	uint8_t dir_received;	// Which side was this message received on?
// 	uint8_t length;			// Message length.
// 	uint8_t wasTargeted;
// } ir_msg;




void init_wrapper() __attribute__ ((section (".WRAPPERFUNCS ")));
void loop_wrapper() __attribute__ ((section (".WRAPPERFUNCS ")));
void handle_msg_wrapper(ir_msg* msg_struct) __attribute__ ((section (".WRAPPERFUNCS ")));


#endif /* WRAPPER_FUNC_H_ */