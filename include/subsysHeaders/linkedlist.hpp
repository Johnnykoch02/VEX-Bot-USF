#include "subsysheaders/Node.hpp"
#ifndef linkedlist_h
#define linkedlist_h

template <class T>
class linkedlist {

  Node<T> head;
  Node<T> tail;
  int size;
  Node<T> g(int index, int cur, Node<T> curr);
public:
  linkedlist(Node<T> h, Node<T> t);
  bool isEmpty();

  void add(T data);
  void remove(T data);
  void clear();
  T get(int index);
  T pop();
  T peek();
  int length();

};
#endif
