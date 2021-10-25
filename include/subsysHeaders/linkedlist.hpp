#include "subsysheaders/Node.hpp"
#ifndef linkedlist_h
#define linkedlist_h


class linkedlist {

  Node<int> head;
  Node<int> tail;
  int size;

public:

  bool isEmpty();
  void add(Node<int> node);

};
#endif
