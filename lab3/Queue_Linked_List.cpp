/*
 * Queue_Linked_List.cpp
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#include "Queue_Linked_List.h"

// struct Node {
// 	Person* person = nullptr;
// 	Node* next = nullptr;
// };

// struct Queue_Linked_List {
// 	Node* front = nullptr;
// 	Node* back = nullptr;
// };

void queue_linked_list_enqueue(Queue_Linked_List&, Person*) {
  // create if head is nullptr, otherwise insert to the back last
  return;
}

void queue_linked_list_dequeue(Queue_Linked_List&) {
  // identify the back node and delete
  return;
}

// simply return the front person pointer
const Person* queue_linked_list_front(const Queue_Linked_List&);

// if front is empty return true
bool queue_linked_list_is_empty(const Queue_Linked_List&);
