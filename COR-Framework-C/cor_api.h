//
//  cor_api.h
//  COR-Framework-C
//
//  Created by denis lavrov on 19/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#ifndef cor_api_h
#define cor_api_h

#include <stdio.h>
#include "cor_map.h"


typedef void (*cor_handler)(char *type, void* message);

struct cor_network_adapter;

typedef void *(*cor_type_callback)(void *message);

typedef struct _cor_module{
	cor_map				*message_handlers;
	cor_map				*message_types;
	struct cor_network_adapter *network_adapter;
	void (*message_in)(struct _cor_module *module, char *type, void *message);
} cor_module;

typedef void (*message_in)(cor_module *module, char *type, void *message);

cor_module *cor_create_module();
void cor_add_topic(cor_module *module, char *type, cor_handler handle);
void cor_register_type(cor_module *module, char *type, cor_type_callback callback);
void cor_message_out(cor_module *module, char *type, void *message);
void cor_message_in(cor_module *module, char *type, void *message);

// Network Adapter

typedef struct cor_network_adapter{
	void		*original_adapter;
	void (*message_in)(cor_module *module, char *type, void *message);
	cor_module	*module;
	void (*message_out)(void *original_adapter, char *type, void *message);
} cor_network_adapter;

cor_network_adapter *cor_create_adapter(cor_module *module);



#endif /* cor_api_h */
