//
//  cor_comm.h
//  COR-Framework-C
//
//  Created by denis lavrov on 19/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#ifndef cor_comm_h
#define cor_comm_h

#include <stdio.h>
#include "cor_map.h"
#include "cor_api.h"

// Callback Adapter

typedef struct cor_callback_adapter{
	cor_map		*routes;
	cor_network_adapter *cor_adapter;
} cor_callback_adapter;

cor_callback_adapter *cor_callback_create(cor_network_adapter *module_adapter);
void register_callback(cor_callback_adapter *callback_adapter, char *type, message_in callback);
void callback_message_out(cor_callback_adapter *callback_adapter, char *type, void *message);

#endif /* cor_comm_h */
