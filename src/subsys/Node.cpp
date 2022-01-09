#include "./subsysHeaders/Node.hpp"

template <class T>
Node<T>::Node(T* data, int priority, Node<T> *p, Node<T> *n) {
    this->data = data;
    this->prev = p;
    this->next = n;
    this->priority = priority;
}

template <class T>
Node<T>::~Node() {
    // if (this->prev!=nullptr) delete prev;
    // if (this->next!=nullptr)delete next;
}

template <class T>
Node<T>::Node(T* data, int priority) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
    this->priority = priority;
}

template <class T>
bool Node<T>::hasPrev() { return  !(this->prev == nullptr); }

template <class T>
bool Node<T>::hasNext() { return  !(this->next == nullptr); }

template <class T>
Node<T>* Node<T>::getNext() { return  this->next; }
template <class T>
Node<T>* Node<T>::getPrev() { return  this->prev; }

template <class T>
void Node<T>::setPrev(Node<T> *p) {
    this->prev = p;
}

template <class T>
void Node<T>::setNext(Node<T> *n) {
    this->next = n;
}

template <class T>
void Node<T>::setData(T* data) {
    data = data;
}

template <class T>
T* Node<T>::getData(){ return this->data;}

template <class T>
int16_t Node<T>::getPriority(){ return this->priority; }
