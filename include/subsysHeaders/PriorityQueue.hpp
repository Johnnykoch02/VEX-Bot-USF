#include "main.h"
#include "./subsysHeaders/linkedlist.hpp"

using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <class T>
class PriorityQueue {
private:

  linkedlist<T> pq;

public:
  PriorityQueue();
  bool isEmpty();
  void enqueue(T* data, int priority);
  T* get(int index);
  T* deque();
  T* peek();
  void dequeue_all();
};

#endif
