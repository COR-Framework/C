//
//  cor_comm.c
//  COR-Framework-C
//
//  Created by denis lavrov on 19/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#include "cor_comm.h"
#include <stdlib.h>

cor_callback_adapter *cor_callback_create(cor_network_adapter *module_adapter){
	cor_callback_adapter *adapter = malloc(sizeof(cor_callback_adapter));
	adapter->routes = cor_map_create();
	adapter->cor_adapter = module_adapter;
	module_adapter->original_adapter = adapter;
	module_adapter->message_out = callback_message_out;
	return adapter;
}

void register_callback(cor_callback_adapter *callback_adapter, char *type, message_in callback){
	cor_map_set(callback_adapter->routes, type, callback);
}

void callback_message_out(cor_callback_adapter *callback_adapter, char *type, void *message){
	message_in callback = cor_map_get(callback_adapter->routes, type);
	callback(callback_adapter->cor_adapter->module, type, message);
}