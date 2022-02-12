using namespace std;

#ifndef PriorityQueue_h
#define PriorityQueue_h

#include "./subsysHeaders/linkedlist.hpp"

template <class T>
class PriorityQueue {
private:

  linkedlist<T> *pq;

public:
  PriorityQueue() {
    this->pq = new linkedlist<T>();
}
  bool isEmpty() {
    return this->pq->isEmpty();
}

  T* deque_index(int index) {
    T* node = this->get(index);
    T* copy = new T(*node);
    bool removed = this->pq->remove(this->get(index));
    if (removed) {
        return copy;
    }
    return nullptr;
}

  void enqueue(T* data, int priority) {
    this->pq->add(data, priority);
}

  T* get(int index) {
    return this->pq->get(index);
}
  T* deque() {
    return this->pq->pop();
}

  T* peek() {
    return this->pq->peek();
}
  void deque_all() {
    this->pq->clear();
}
};

#endif
