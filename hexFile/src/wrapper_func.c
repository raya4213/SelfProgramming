/*
 * wrapper_func.c
 *
 * Created: 2/7/2017 3:13:33 PM
 *  Author: colab
 */ 

#include "wrapper_func.h"

void loop_wrapper(){
	loop();
}

void handle_msg_wrapper(ir_msg* msg_struct){
	handle_msg(msg_struct);
}

void init_wrapper(){
	init();
}