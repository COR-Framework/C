//
//  test.c
//  COR-Framework-C
//
//  Created by denis lavrov on 20/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#include "cor/cor_api.h"
#include "cor/cor_comm.h"
#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <string.h>

pthread_t requester_thread;

typedef struct request{
	char *message;
} request;

typedef struct response{
	char *message;
}response;

void requester_worker(cor_module *requester){
	while (1) {
		request r = {"Hello"};
		cor_message_out(requester, "request", &r);
		sleep(1);
	}
}

void response_handler(char *type, void *message){
	if (strcmp(type, "response")){
		response *res = (response*) message;
		printf("Got response: %s\n", res->message);
	}
}

void request_handler(cor_module *module, char *type, void *message){
	if (strcmp(type, "request")){
		request *req = (request*) message;
		printf("Got request: %s\n", req->message);
	}
	response res = {"Hi"};
	cor_message_out(module, "response", &res);
}

int main(int argc, char *argv[]) {
	cor_module *requester = cor_create_module();
	cor_callback_adapter *requester_adapter = cor_callback_create(requester->network_adapter);
	cor_add_topic(requester, "response", response_handler);
	pthread_create(&requester_thread, NULL, requester_worker, requester);


	cor_module *responder = cor_create_module();
	cor_callback_adapter *responder_adapter = cor_callback_create(responder->network_adapter);
	cor_add_topic(responder, "request", response_handler);

	sleep(100);
}
