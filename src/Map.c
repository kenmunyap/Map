#include <malloc.h>
#include <stdio.h>
#include "Map.h"

Map *createMap(int size){
  Map *map = malloc(sizeof(Map));
  
  map->size = size;
  map->table = malloc(sizeof(LinkedList *)* size);
}

void destroyMap(Map *map){
  int i;
  if(!map){
    for(i = 0 ; i < map->size ; i++){
      destroyAllLinkedList(map->table[i]);
    }
  }
  free(map->table);
  free(map);
}
void addMap(Map *map, void *data, int (*hash)(void *data)){
  int hashValue = hash(data);
  printf("hashValue is %d", hashValue);
}