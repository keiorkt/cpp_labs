/*
 * Person.h
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#ifndef PERSON_H_
#define PERSON_H_

#include "Ticket.h"

enum Gender { MALE, FEMALE };

struct Person {
	string name;
	int age;
	Gender gender;
	Ticket* ticket = nullptr;
};

void print_person(const Person&);

// Task 2 (Part II)
void initialize_person_with_ticket_by_pointer(Person* person, string name, int age, Gender gender, Ticket* ticket);
void initialize_person_by_pointer(Person* person, string name, int age, Gender gender);
Person* create_person(string, int, Gender);
Person* create_person_with_ticket(string, int, Gender, string, TicketClass);
void destroy_person(Person*);

#endif /* PERSON_H_ */
