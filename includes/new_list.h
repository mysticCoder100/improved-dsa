#ifndef NEW_LIST_H
#define NEW_LIST_H
#include <stdexcept>

/**
 * This is the header file for the NewList class, which is a template class that
 * implements a singly linked list data structure. The NewList class provides
 * basic functionalities such as adding, removing, and accessing elements in the
 * list. The Node struct is defined within the NewList class and represents each
 * element in the list, containing the data and pointers to the next nodes.
 *
 */
template <typename Object> class NewList {
  struct Node {
    Object data;
    Node *next;

    Node(const Object &d = Object{}, Node *n = nullptr) : data{d}, next{n} {}
  };

  Node *head;
  Node *tail;
  int size;

public:
  NewList() {
    head = new Node;
    tail = head;
    size = 0;
  }

  void add(const Object data) {
    Node *newNode = new Node{data, nullptr};
    tail->next = newNode;
    tail = newNode;
    size++;
  }

  int getSize() const { return size; }
};
#endif