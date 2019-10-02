/*
 * Queue.h
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include "Person.h"

struct Queue {
	Person** queue_array = nullptr; // Dynamic array of Person* (pointers to Person).
	unsigned int queue_size = 0; // Actual number of Person objects in the queue.
	unsigned int queue_capacity = 0; // Raw array capacity of queue_array.
};

// Task 3
void reallocate_queue_array(Queue&, unsigned int);
void queue_enqueue(Queue&, Person*);
void queue_dequeue(Queue&);
const Person* queue_front(const Queue&);
bool queue_is_empty(const Queue&);
void destroy_queue(Queue&);

#endif /* QUEUE_H_ */
