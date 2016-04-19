//
//  cor_api.c
//  COR-Framework-C
//
//  Created by denis lavrov on 19/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#include "cor_api.h"
#include <stdlib.h>

cor_module *cor_create_module(){
	cor_module *module = malloc(sizeof(cor_module));
	module->message_handlers = cor_map_create();
	module->message_types = cor_map_create();
	module->message_in = cor_message_in;
	return module;
}

void cor_add_topic(cor_module *module, char *type, cor_handler handle){
	cor_map_set(module->message_handlers, type, handle);
}

void cor_message_in(cor_module *module, char *type, void *message){
	cor_handler handler = cor_map_get(module->message_handlers, type);
	handler(message);
}

void cor_message_out(cor_module *module, char *type, void *message){
	cor_network_adapter *na = module->network_adapter;
	na->message_out(na->original_adapter, type, message);
}

cor_network_adapter *create_adapter(cor_module *module){
	cor_network_adapter *adapter = malloc(sizeof(cor_network_adapter));
	adapter->module = module;
	adapter->message_in = module->message_in;
	return adapter;
}
