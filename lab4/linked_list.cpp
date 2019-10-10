#include "linked_list.h"
#include <iostream>
using namespace std;

// TODO
LinkedList::LinkedList() {
  this->head = this->tail = new Node();
}

// TODO
LinkedList::~LinkedList() {
  while(this->size() > 0) {
    this->remove(this->get_head(), this->get_head()->next);
  }
}

// TODO
void LinkedList::insert(Node* prev, Node* ins) {
  ins->next = prev->next;
  prev->next = ins;
  if (prev == tail) {
    this->tail = ins;
  }
  ++this->_size;
}


// TODO
void LinkedList::remove(Node* prev, Node* del) {
  prev->next = del->next;

  if (del == tail) {
    this->tail = prev;
  }

  delete del;
  del=nullptr;

  --this->_size;
}
