/*
 * Ticket.cpp
 *
 *  Created on: 30 Sep 2019
 *      Author: keitaiwasaki
 */

#include "Ticket.h"

void print_ticket(const Ticket& ticket) {
	cout << "  Movie name: " << ticket.movie << endl;
	cout << "  Ticket class: " << (ticket.ticket_class == STANDARD ? "Standard" :
									ticket.ticket_class == PREMIUM ? "Premium" :
									ticket.ticket_class == GOLD ? "Gold" :
									"Platinum") << endl;
}

/*
 * Task 1 - Passing arguments by reference and pointer
 *
 * You are required to implement the following functions:
 *
 *   void initialize_ticket_by_reference(Ticket&, string, TicketClass)
 *   void initialize_ticket_by_pointer(Ticket*, string, TicketClass)
 * Initialize the data members of the given ticket according to the arguments provided.
 *
 *   void swap_tickets_by_reference(Ticket&, Ticket&)
 *   void swap_tickets_by_pointer(Ticket*, Ticket*)
 * Swap the data members of the given tickets. Do nothing if the function arguments are nullptr.
 *
 */

void initialize_ticket_by_reference(Ticket& ticket, string movie, TicketClass ticket_class) {
	ticket.movie = movie;
	ticket.ticket_class = ticket_class;
}

void initialize_ticket_by_pointer(Ticket* ticket, string movie, TicketClass ticket_class) {
	if (ticket == nullptr) ticket = new Ticket;
	ticket->movie = movie;
	ticket->ticket_class = ticket_class;
}

void swap_tickets_by_reference(Ticket& ticket1, Ticket& ticket2) {
	Ticket temp = ticket2;
	ticket2 = ticket1;
	ticket1 = temp;
}

void swap_tickets_by_pointer(Ticket* ticket1, Ticket* ticket2) {
	if (ticket1 == nullptr || ticket2 == nullptr) return;
	Ticket temp = *ticket2;
	*ticket2 = *ticket1;
	*ticket1 = temp;
}

/*
 * Task 2 (Part I) - Dynamic allocation and deallocation of Ticket objects
 *
 * You are required to implement the following functions:
 *
 *   Ticket* create_ticket(string, TicketClass)
 * Dynamically create and initialize a ticket with the given arguments on every call.
 *
 *   void destroy_ticket(Ticket*)
 * Dynamically deallocate the ticket provided. Do nothing in the case of nullptr.
 *
 * You may utilize the functions implemented in Task 1 if required.
 */

Ticket* create_ticket(string movie, TicketClass ticket_class) {
	Ticket* ticket = new Ticket;
	initialize_ticket_by_pointer(ticket, movie, ticket_class);
	return ticket;
}

void destroy_ticket(Ticket* ticket) {
	if (ticket == nullptr) return;
	delete ticket;
	ticket = nullptr;
}
