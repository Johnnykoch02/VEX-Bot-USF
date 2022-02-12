#ifndef Node_h
#define Node_h

//#ifdef __cplusplus
#include <iostream>
#include <string>
//#endif

using namespace std;


template <class T>
class Node {
    Node<T> *prev;
    Node<T> *next;
    int16_t priority;
    T *data;

public:

  Node(){}

  ~Node() {}

  Node(T *data, int priority, Node<T> *p, Node<T> *n) {
    this->data = data;
    this->prev = p;
    this->next = n;
    this->priority = priority;
}

  Node(T *data, int priority) {
    this->data = data;
    this->prev = nullptr;
    this->next = nullptr;
    this->priority = priority;
}

  Node* getNext() { return  this->next; }

  Node* getPrev() { return  this->prev; }

  bool hasPrev() { return !(this->prev == nullptr); }

  bool hasNext(){ return  !(this->next == nullptr); }

  void setPrev(Node<T> *p) {
    this->prev = p;
}
  void setNext(Node<T> *n) {
    this->next = n;
}

  void setData(T* data) {
    this->data = data;
}
  T *getData() { return this->data; }
  
  int16_t getPriority() { return this->priority; }

  friend ostream &operator<<(ostream &stream, const Node<T> &node) {
      stream << "\tNode " << &node << ":" << endl;
      stream << "\t" << *node.data <<"\t Priority: " << node.priority;
      return stream;
  }
};
#endif
