/*
 * lab3_main.cpp
 * Grader file for Lab 3: Pointers and Linked Lists
 * Do NOT modify any section of this file that is not marked with "NOTE"!
 */

#include <chrono> // For measuring performance in the Bonus Task
#include "Queue.h"
#include "Queue_Linked_List.h"

void task1_test_cases() {
	cout << "Task 1" << endl << endl << endl;
	Ticket ticket, ticket1, ticket2;

	cout << "Executing tests for void initialize_ticket_by_reference(Ticket&, string, TicketClass)" << " (3 total)" << endl;
	initialize_ticket_by_reference(ticket, "Avengers", STANDARD);
	print_ticket(ticket);
	initialize_ticket_by_reference(ticket, "Black Phoenix", PREMIUM);
	print_ticket(ticket);
	initialize_ticket_by_reference(ticket, "Superman", PLATINUM);
	print_ticket(ticket);
	cout << endl << endl;

	cout << "Executing tests for void initialize_ticket_by_pointer(Ticket*, string, TicketClass)" << " (5 total)" << endl;
	initialize_ticket_by_pointer(&ticket, "Pikachu", GOLD);
	print_ticket(ticket);
	initialize_ticket_by_pointer(&ticket, "Sherlock Holmes", STANDARD);
	print_ticket(ticket);
	initialize_ticket_by_pointer(nullptr, "Game of Thrones", PREMIUM); // Should not crash
	print_ticket(ticket); // Should be same as before
	initialize_ticket_by_pointer(&ticket, "Star Wars", STANDARD);
	print_ticket(ticket);
	initialize_ticket_by_pointer(nullptr, "Enchanted", PLATINUM); // Should not crash
	print_ticket(ticket); // Should be same as before
	cout << endl << endl;

	cout << "Executing tests for void swap_tickets_by_reference(Ticket&, Ticket&) (2 total)" << endl;
	initialize_ticket_by_reference(ticket1, "Up", PREMIUM);
	initialize_ticket_by_pointer(&ticket2, "Pets", PLATINUM);
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1);
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2);
	swap_tickets_by_reference(ticket1, ticket2);
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1);
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2);
	swap_tickets_by_reference(ticket1, ticket2);
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1);
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2);
	cout << endl << endl;

	cout << "Executing tests for void swap_tickets_by_pointer(Ticket*, Ticket*) (5 total)" << endl;
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1);
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2);
	swap_tickets_by_pointer(&ticket1, &ticket2);
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1);
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2);
	swap_tickets_by_pointer(&ticket1, &ticket2);
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1);
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2);
	swap_tickets_by_pointer(nullptr, &ticket2); // Should not crash
	cout << "Test Passed - No crash when 1st argument == nullptr" << endl;
	swap_tickets_by_pointer(&ticket1, nullptr); // Should not crash
	cout << "Test Passed - No crash when 2nd argument == nullptr" << endl;
	swap_tickets_by_pointer(nullptr, nullptr); // Should not crash
	cout << "Test Passed - No crash when both arguments are nullptr" << endl;
	cout << "Ticket 1: " << endl;
	print_ticket(ticket1); // Should be same as before
	cout << "Ticket 2: " << endl;
	print_ticket(ticket2); // Should be same as before
	cout << endl << endl;
	cout << "Task 1 tests complete!" << endl;
}

void task2_test_cases() {
	cout << "Task 2 (Part I) (3 sets of tests total)" << endl;
	cout << "N.B. Graders may wish to manually inspect the students' implementations of " << endl
		<< "Ticket* create_ticket(string, TicketClass) and void destroy_ticket(Ticket*) " << endl
		<< "to ensure that proper dynamic memory allocation/deallocation is taking place." << endl << endl << endl;

	cout << "Creating tickets ..." << endl;
	Ticket* ticket1 = create_ticket("The Da Vinci Code", PLATINUM);
	Ticket* ticket2 = create_ticket("Smurfs", STANDARD);
	Ticket* ticket3 = create_ticket("La la land", PREMIUM);

	cout << "Printing tickets ..." << endl;
	print_ticket(*ticket1);
	print_ticket(*ticket2);
	print_ticket(*ticket3);

	cout << "Destroying tickets ..." << endl;
	destroy_ticket(ticket3);
	destroy_ticket(nullptr); // Should not crash
	destroy_ticket(ticket2);
	destroy_ticket(nullptr); // Should not crash
	destroy_ticket(ticket1);
	cout << "Test Passed - destroy_ticket did not crash on nullptrs" << endl << endl << endl;

	cout << "Task 2 (Part II) (4 sets of tests total)" << endl;
	cout << "N.B. Graders should inspect students' solutions carefully, " << endl
		<<	"in particular void destroy_person(Person*), " << endl
		<< "to ensure that there is no memory leak." << endl << endl << endl;

	cout << "Creating people ..." << endl;
	Person* ada = create_person("Ada", 18, FEMALE);
	Person* brian = create_person("Brian", 30, MALE);
	Person* charles = create_person_with_ticket("Charles", 25, MALE, "Pacific Rim", GOLD);
	Person* descartes = create_person_with_ticket("Descartes", 42, MALE, "Passion of the Christ", PREMIUM);

	cout << "Printing people ..." << endl;
	print_person(*ada);
	print_person(*brian);
	print_person(*charles);
	print_person(*descartes);

	cout << "Destroying people ..." << endl;
	destroy_person(descartes);
	destroy_person(nullptr); // Should not crash
	destroy_person(charles);
	destroy_person(brian);
	destroy_person(nullptr); // Should not crash
	destroy_person(nullptr); // Should not crash
	destroy_person(ada);
	cout << "Test Passed - destroy_person did not crash on nullptrs" << endl;
	cout << endl << endl;
	cout << "Task 2 tests complete!" << endl;
}

void task3_test_cases() {
	cout << "Task 3" << endl;
	cout << "N.B. Graders may wish to first inspect students' solutions to check that there is no memory leak." << endl << endl << endl;

	Queue movie_queue; // An empty movie queue
	if (queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned true on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return true on empty queue" << endl;
	}
	cout << endl << endl;

	queue_dequeue(movie_queue);
	cout << "Test Passed - queue_dequeue() did not crash on empty queue" << endl;
	if (queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned true on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return true on empty queue" << endl;
	}
	cout << endl << endl;

	if (queue_front(movie_queue) == nullptr) {
		cout << "Test Passed - queue_front() returned nullptr on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_front() should return nullptr on empty queue" << endl;
	}
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person("Adrian", 20, MALE));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Adrian's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person("Bob", 25, MALE));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Adrian's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Catherine", 23, FEMALE, "Game of Thrones", PLATINUM));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Adrian's details
	cout << endl << endl;

	queue_dequeue(movie_queue);
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Bob's details
	cout << endl << endl;

	queue_dequeue(movie_queue);
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Catherine's details
	cout << endl << endl;

	queue_dequeue(movie_queue);
	if (queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned true on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return true on empty queue" << endl;
	}
	cout << endl << endl;

	queue_dequeue(movie_queue);
	cout << "Test Passed - queue_dequeue() did not crash on empty queue" << endl;
	if (queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned true on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return true on empty queue" << endl;
	}
	cout << endl << endl;

	if (queue_front(movie_queue) == nullptr) {
		cout << "Test Passed - queue_front() returned nullptr on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_front() should return nullptr on empty queue" << endl;
	}
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Dominic", 7, MALE, "Teletubbies", STANDARD));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Dominic's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Esther", 13, FEMALE, "When I First Met Him", PREMIUM));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Dominic's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Fahim", 16, MALE, "The King of Boxers", STANDARD));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Dominic's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Georgina", 19, FEMALE, "Apocalypse", GOLD));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Dominic's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Henrietta", 33, FEMALE, "A Modern Remake of \"Much Ado About Nothing\"", STANDARD));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Dominic's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Ingrid", 3, FEMALE, "Barbie - The Movie", STANDARD));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Dominic's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Jared", 10, MALE, "Cars II", PREMIUM));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Dominic's details
	cout << endl << endl;

	queue_dequeue(movie_queue);
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Esther's details
	cout << endl << endl;

	queue_dequeue(movie_queue);
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Fahim's details
	cout << endl << endl;

	queue_dequeue(movie_queue);
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should print Georgina's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Karl", 41, MALE, "Mission Impossible", GOLD));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Georgina's details
	cout << endl << endl;

	queue_enqueue(movie_queue, create_person_with_ticket("Leonardo", 29, MALE, "Hamlet", PLATINUM));
	if (!queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned false on nonempty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return false on nonempty queue" << endl;
	}
	print_person(*queue_front(movie_queue)); // Should still print Georgina's details
	cout << endl << endl;

	cout << "Executing dequeue loop ..." << endl;
	while (!queue_is_empty(movie_queue)) {
		cout << endl;
		print_person(*queue_front(movie_queue)); // Should print, in succession:
		// - Georgina's details
		// - Henrietta's details
		// - Ingrid's details
		// - Jared's details
		// - Karl's details
		// - Leonardo's details
		queue_dequeue(movie_queue);
	}
	cout << endl << endl;

	queue_dequeue(movie_queue);
	cout << "Test Passed - queue_dequeue() did not crash on empty queue" << endl;
	if (queue_is_empty(movie_queue)) {
		cout << "Test Passed - queue_is_empty() returned true on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_is_empty() should return true on empty queue" << endl;
	}
	cout << endl << endl;

	if (queue_front(movie_queue) == nullptr) {
		cout << "Test Passed - queue_front() returned nullptr on empty queue" << endl;
	}
	else {
		cout << "Test Failed - queue_front() should return nullptr on empty queue" << endl;
	}
	cout << endl << endl;

	destroy_queue(movie_queue);
	cout << "Test Passed - destroy_queue() did not crash on empty queue" << endl;
	if (movie_queue.queue_array == nullptr) {
		cout << "Test Passed - queue_array deallocated." << endl;
	}
	else {
		cout << "Test Failed - queue_array not deallocated." << endl;
	}
	cout << endl << endl;

	Queue test_queue;
	queue_enqueue(test_queue, create_person("Adrian", 20, MALE));
	queue_enqueue(test_queue, create_person("Bob", 25, MALE));
	queue_enqueue(test_queue, create_person_with_ticket("Catherine", 23, FEMALE, "Game of Thrones", PLATINUM));
	queue_enqueue(test_queue, create_person_with_ticket("Dominic", 7, MALE, "Teletubbies", STANDARD));
	queue_enqueue(test_queue, create_person_with_ticket("Esther", 13, FEMALE, "When I First Met Him", PREMIUM));
	queue_enqueue(test_queue, create_person_with_ticket("Fahim", 16, MALE, "The King of Boxers", STANDARD));
	queue_enqueue(test_queue, create_person_with_ticket("Georgina", 19, FEMALE, "Apocalypse", GOLD));
	queue_enqueue(test_queue, create_person_with_ticket("Henrietta", 33, FEMALE, "A Modern Remake of \"Much Ado About Nothing\"", STANDARD));
	queue_enqueue(test_queue, create_person_with_ticket("Ingrid", 3, FEMALE, "Barbie - The Movie", STANDARD));
	queue_enqueue(test_queue, create_person_with_ticket("Jared", 10, MALE, "Cars II", PREMIUM));
	queue_enqueue(test_queue, create_person_with_ticket("Karl", 41, MALE, "Mission Impossible", GOLD));
	queue_enqueue(test_queue, create_person_with_ticket("Leonardo", 29, MALE, "Hamlet", PLATINUM));
	destroy_queue(test_queue);
	cout << "Test Passed - destroy_queue() did not crash on non-empty queue" << endl;
	if (test_queue.queue_array == nullptr) {
		cout << "Test Passed - queue_array deallocated." << endl;
	}
	else {
		cout << "Test Failed - queue_array not deallocated." << endl;
	}
	cout << endl << endl;

	cout << "Task 3 tests complete!" << endl;
}

// void bonus_task_test_cases() {
// 	cout << "Bonus Task - Performance tests for queue operations" << endl;
// 	cout << "If this test finishes under 5000ms then bonus marks will be given" << endl;

// 	std::chrono::time_point<std::chrono::steady_clock> start = std::chrono::steady_clock::now();
// 	Queue_Linked_List queue;

// 	for (int i = 0; i < 1e6; ++i) {
// 		queue_linked_list_enqueue(queue, create_person_with_ticket("Chandra Nalaar", 21, FEMALE, "Phoenix Rising", PLATINUM));
// 		queue_linked_list_is_empty(queue);
// 		const Person* test1 =  queue_linked_list_front(queue);
// 	}

// 	for (int i = 0; i < 1e6; ++i) {
// 		if (rand() % 2) {
// 			queue_linked_list_enqueue(queue, create_person_with_ticket("Teysa Karlov", 21, FEMALE, "Orzhov Intrigue", GOLD));
// 			queue_linked_list_is_empty(queue);
// 			const Person* test2 = queue_linked_list_front(queue);
// 		}
// 		else {
// 			const Person* test3 = queue_linked_list_front(queue);
// 			queue_linked_list_dequeue(queue);
// 			queue_linked_list_is_empty(queue);
// 		}
// 	}

// 	while (!queue_linked_list_is_empty(queue)) {
// 		const Person* test4 = queue_linked_list_front(queue);
// 		queue_linked_list_dequeue(queue);
// 	}

// 	std::chrono::time_point<std::chrono::steady_clock> end = std::chrono::steady_clock::now();
// 	cout << "Execution time: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << endl;

// 	cout << "Bonus Task tests complete!" << endl;
// }

int main(int argc, char *argv[]) {
	task1_test_cases();
	cout << endl << endl << endl;
	task2_test_cases();
	cout << endl << endl << endl;
	task3_test_cases();

	// NOTE: Uncomment the two lines below to run the tests for the Bonus Task
	//cout << endl << endl << endl;
	//bonus_task_test_cases();

	return 0;
}