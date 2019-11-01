#include "linked_list.h"
#include <iostream>
using namespace std;

// TODO
LinkedList::LinkedList() {
  this->head = new Node();
}

// TODO
LinkedList::~LinkedList() {
  while(this->size() > 0) {
    this->remove(this->get_head()->next);
  }
}

// TODO
void LinkedList::insert(Node* prev, Node* ins) {
  if (this->size() == 0) {
    this->head->next = ins;
    ++this->_size;
    return;
  }

  if (this->size() == 1) {
    prev->next = ins;
    prev->prev = ins;
    ins->prev = prev;
    ins->next = prev;
    ++this->_size;
    return;
  }

  ins->next = prev->next;
  ins->prev = prev;
  prev->next->prev = ins;
  prev->next = ins;

  if (prev == get_tail()) {
    this->head->next->prev = ins;
    ins->next = this->head;
  }

  ++this->_size;
}


// TODO
void LinkedList::remove(Node* del) {
  del->prev->next = del->next;
  del->next->prev = del->prev;

  if (del == get_tail()) {
    this->head->prev = del->prev;
    del->prev->next = this->head;
  }

  delete del;
  del = nullptr;

  --this->_size;
}
