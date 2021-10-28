#include "main.h"
#include linkedlist_h;
using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <class T>
class PriorityQueue {
private:
  //

  linkedlist<T> pq;

public:
  PriorityQueue();
  bool isEmpty();
  void enqueue(T data, int priority);
  T deque();
  T peek();

};

#endif
