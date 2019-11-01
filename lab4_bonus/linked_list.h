#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class Node {
    public:
    std::string content;
    Node* next {nullptr};
    Node* prev {nullptr};

    Node() {}
    Node(std::string _content):content(_content) {}
};

class LinkedList {

public:
    LinkedList();
    // LinkedList(const LinkedList& other);
    ~LinkedList();
    void insert(Node* prev, Node* ins);
    void remove(Node* del);
    void push_back(std::string content) {
        this->insert(this->get_tail(), new Node{content});
    }
    int size() const {return this->_size;}
    Node* get_head() const {return this->head;}
    Node* get_tail() const {return this->get_head()->next->prev;}

private:
    Node* head;
    // Node* tail;
    int _size {0};
};

#endif // LINKED_LIST_H
