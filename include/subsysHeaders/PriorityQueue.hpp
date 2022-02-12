using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "./subsysHeaders/linkedlist.hpp"

template <class T>
class PriorityQueue {
private:

  linkedlist<T> *pq;

public:
  PriorityQueue();
  bool isEmpty();
  T* deque_index(int index);
  void enqueue(T* data, int priority);
  T* get(int index);
  T* deque();
  T* peek();
  void deque_all();
};

#endif
