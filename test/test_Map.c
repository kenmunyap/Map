#include "unity.h"
#include "Map.h"
#include "LinkedList.h"
#include "Student.h"
#include "mock_HashFunction.h"

void setUp(void){}
void tearDown(void){}

void test_createMap_should_return_A_map(void){
	Map *map = createMap(10);
  
  TEST_ASSERT_NOT_NULL(map);
  TEST_ASSERT_EQUAL(10,map->size);
  TEST_ASSERT_NOT_NULL(map->table);
}
void test_destroyMap_should_return_all_resources(void){
	Map *map = createMap(10);
  
  destroyMap(map);
}
void test_map_given_Ali_should_add_in_slot_4(void){
  LinkedList *firstList;
	Student ali = {.name = "Ali", .age = 10};
	Map *map = createMap(10);
  
  hash_ExpectAndReturn((void *)&ali,4);
  firstList = map->table[4];
  addMap(map, (void *)&ali, hash);
  TEST_ASSERT_NOT_NULL(map->table[4]);
  TEST_ASSERT_EQUAL_PTR(&ali, (Student *)(firstList->data));
}