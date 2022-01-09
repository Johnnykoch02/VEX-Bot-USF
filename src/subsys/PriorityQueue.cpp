#include "main.h"
#include "subsysheaders/PriorityQueue.hpp"

template <class T>
PriorityQueue<T>::PriorityQueue() {
    this->pq = new linkedlist<T>();
}

template <class T>
bool PriorityQueue<T>::isEmpty() {
    return this->pq->isEmpty();
}


template <class T>
void PriorityQueue<T>::enqueue(T* data, int priority) {
  this->pq->add(data, priority);
}

template <class T>
T* PriorityQueue<T>::deque() {
    return this->pq->pop();
}

template <class T>
T* PriorityQueue<T>::deque_index(int index) {
    T* node = this->get(index);
    T* copy = new T(*node);
    bool removed = this->pq->remove(this->get(index));
    if (removed) {
        return copy;
    }
    return nullptr;
}

template <class T>
T* PriorityQueue<T>::peek() {
    return this->pq->peek();
}

template <class T>
T* PriorityQueue<T>::get(int index) {
    return this->pq->get(index);
}
