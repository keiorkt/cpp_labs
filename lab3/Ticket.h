/*
 * Ticket.h
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#ifndef TICKET_H_
#define TICKET_H_

#include <iostream>
using std::string;
using std::cout;
using std::endl;

enum TicketClass {
	STANDARD,
	PREMIUM,
	GOLD,
	PLATINUM
};

struct Ticket {
	string movie;
	TicketClass ticket_class;
};

void print_ticket(const Ticket&);

// Task 1
void initialize_ticket_by_reference(Ticket&, string, TicketClass);
void initialize_ticket_by_pointer(Ticket*, string, TicketClass);
void swap_tickets_by_reference(Ticket&, Ticket&);
void swap_tickets_by_pointer(Ticket*, Ticket*);

// Task 2 (Part I)
Ticket* create_ticket(string, TicketClass);
void destroy_ticket(Ticket*);

#endif /* TICKET_H_ */
