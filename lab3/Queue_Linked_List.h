/*
 * Queue_Linked_List.h
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#ifndef QUEUE_LINKED_LIST_H_
#define QUEUE_LINKED_LIST_H_

#include "Person.h"

struct Node {
	Person* person = nullptr;
	Node* next = nullptr;
};

struct Queue_Linked_List {
	Node* front = nullptr;
	Node* back = nullptr;
};

// Bonus Task
void queue_linked_list_enqueue(Queue_Linked_List&, Person*);
void queue_linked_list_dequeue(Queue_Linked_List&);
const Person* queue_linked_list_front(const Queue_Linked_List&);
bool queue_linked_list_is_empty(const Queue_Linked_List&);

#endif /* QUEUE_LINKED_LIST_H_ */
