//
//  cor_map.c
//  COR-Framework-C
//
//  Created by denis lavrov on 20/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#include "cor_map.h"
#include <stdlib.h>
#include <string.h>

cor_map *cor_map_create(){
	cor_map *map = (cor_map*) malloc(sizeof(cor_map));
	map->first = NULL;
	map->last = NULL;
	return map;
}

void cor_map_destroy(cor_map* map){
	free(map);
}

void *cor_map_get(cor_map *map, char *key){
	cor_map_node *np = map->first;
	while (np != NULL) {
		if (strcmp(np->key, key) == 0) {
			return np->value;
		}
		np = np->next;
	}
	return NULL;
}

cor_map_node *create_node(char *key, void *value){
	cor_map_node *node = malloc(sizeof(cor_map_node));
	node->key = key;
	node->value = value;
	return node;
}

void cor_map_set(cor_map* map, char *key, void *value){
	if (cor_map_get(map, key) == NULL) {
		if (map->first == NULL) {
			map->first = create_node(key, value);
			map->last = map->first;
		} else {
			cor_map_node *last_node = map->last;
			last_node->next = create_node(key, value);
			map->last = last_node->next;
		}
	}
}