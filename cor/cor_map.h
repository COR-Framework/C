//
//  cor_map.h
//  COR-Framework-C
//
//  Created by denis lavrov on 20/04/16.
//  Copyright © 2016 bahus. All rights reserved.
//

#ifndef cor_map_h
#define cor_map_h

#include <stdio.h>

typedef struct cor_map_node {
  char *key;
  void *value;
  struct cor_map_node *next;
} cor_map_node;

typedef struct cor_map {
  cor_map_node *first;
  cor_map_node *last;
} cor_map;

cor_map *cor_map_create();
void cor_map_destroy(cor_map *map);
void *cor_map_get(cor_map *map, char *key);
void cor_map_set(cor_map *map, char *key, void *value);

#endif /* cor_map_h */
