//
//  test.c
//  COR-Framework-C
//
//  Created by denis lavrov on 20/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#include <stdio.h>
#include "cor_api.h"
#include "cor_comm.h"

int main(int argc, char* argv[]){
	cor_module *requester = cor_create_module();
	cor_callback_adapter *requester_adapter = cor_callback_create(requester->network_adapter);
	
	cor_module *responder = cor_create_module();
	cor_callback_adapter *responder_adapter = cor_callback_create(responder->network_adapter);
}
