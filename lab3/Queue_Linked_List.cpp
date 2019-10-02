/*
 * Queue_Linked_List.cpp
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#include "Queue_Linked_List.h"

void queue_linked_list_enqueue(Queue_Linked_List& queue_linked_list, Person* person) {
  Node* frontNode = queue_linked_list.front;
  Node* backNode = queue_linked_list.back;

  Node* newNode = new Node;
  newNode->person = person;

  if (queue_linked_list_is_empty(queue_linked_list)) {
    queue_linked_list.front = newNode;
    return;
  }

  if (backNode == nullptr) {
    frontNode->next = newNode;
    queue_linked_list.back = newNode;
    return;
  }

  backNode->next = newNode;
  queue_linked_list.back = newNode;
}

void queue_linked_list_dequeue(Queue_Linked_List& queue_linked_list) {
  if (queue_linked_list_is_empty(queue_linked_list)) return;

  Node* frontNode = queue_linked_list.front;
  Node* backNode = queue_linked_list.back;
  Node* secondNode = frontNode->next;

  if (secondNode == nullptr)
    queue_linked_list.front = nullptr;
  else {
    if (secondNode == backNode)
      queue_linked_list.back = nullptr;

    queue_linked_list.front = secondNode;
  }

  delete frontNode;
  frontNode = nullptr;
}

const Person* queue_linked_list_front(const Queue_Linked_List& queue_linked_list) {
  return queue_linked_list.front->person;
}

bool queue_linked_list_is_empty(const Queue_Linked_List& queue_linked_list) {
  return queue_linked_list.front == nullptr;
}
