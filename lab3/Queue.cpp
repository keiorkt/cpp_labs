/*
 * Queue.cpp
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#include "Queue.h"

/*
 * Task 3 - Implementing a queue using a dynamic array
 *
 * Your task is to implement the following functions:
 *
 *   void reallocate_queue_array(Queue&, unsigned int);
 * Create a new dynamic array of the specified size.
 * Remember to copy the Person pointers from the old queue_array to the new array, and then destroy the old queue_array.
 *
 *   void queue_enqueue(Queue&, Person*)
 * Add the given Person at the back of the queue. Resize queue_array if needed.
 *
 *   void queue_dequeue(Queue&)
 * Remove the Person at the front of the queue and deallocate memory accordingly if the queue is non-empty; otherwise, do nothing.
 * Remember to also shift the remaining array elements forward in order to maintain correct Queue order (e.g. "move the Queue forward").
 * In other words, make sure that index 0 is always the valid front element of the non-empty queue, with no "holes" in the queue.
 * It is not necessary to resize queue_array.
 *
 *   const Person* queue_front(const Queue&)
 * Return a pointer to the Person at the front of the queue if the queue is non-empty; otherwise, it return nullptr.
 *
 *   bool queue_is_empty(const Queue&)
 * Return a boolean value indicating whether the queue is currently empty, meaning no valid elements in the queue (i.e. no Person in the queue).
 * A queue with non-zero queue_capacity but otherwise no valid elements is also considered empty.
 *
 *   void destroy_queue(Queue&);
 * Destroy all Person objects in the queue if any, and also destroy the queue_array itself.
 */

void reallocate_queue_array(Queue& queue, unsigned int new_capacity) {
	Person** oldPtr = queue.queue_array;
	Person** newPtr = new Person* [new_capacity];
	queue.queue_array = newPtr;
	queue.queue_capacity = new_capacity;

	for (unsigned int i = 0; i < new_capacity-1; ++i)
		newPtr[i] = oldPtr[i];

	delete [] oldPtr;
	oldPtr = nullptr;
}

// Add the given Person at the back of the queue. Resize queue_array if needed.
void queue_enqueue(Queue& queue, Person* person) {
	if (queue.queue_capacity == queue.queue_size) {
		reallocate_queue_array(queue, queue.queue_capacity+1);
		queue_enqueue(queue, person);
		return;
	}

	queue.queue_array[queue.queue_size] = person;
	++queue.queue_size;
	return;
}

void queue_dequeue(Queue& queue) {
	if (queue_is_empty(queue)) return;

	Person* front = queue.queue_array[0];
	delete front;

	for (unsigned int i = 0; i < queue.queue_size; ++i) {
		if (i == (queue.queue_size-1))
			queue.queue_array[i] = nullptr;
		else
			queue.queue_array[i] = queue.queue_array[i+1];
	}

	--queue.queue_size;
}

const Person* queue_front(const Queue &queue) {
	return queue_is_empty(queue) ? nullptr : queue.queue_array[0];
}

bool queue_is_empty(const Queue &queue) {
	for (unsigned int i = 0; i < queue.queue_capacity; ++i) {
		if (queue.queue_array[i] != nullptr)
			return false;
	}
	return true;
}

void destroy_queue(Queue& queue) {
	for (unsigned int i = 0; i < queue.queue_capacity; ++i)
		destroy_person(queue.queue_array[i]);

	delete [] queue.queue_array;
	queue.queue_array = nullptr;
}
