#ifndef Node_h
#define Node_h
#include "main.h"

template <class T>
class Node {

    Node *prev;
    Node *next;
    int priority;
    T data;

public:

  Node(T data, int priority, Node<T> p, Node<T> n);
  Node(T data, int priority);
  Node* getNext();
  Node* getPrev();
  bool hasPrev();
  bool hasNext();
  void setPrev(Node<T> p);
  void setNext(Node<T> n);
  void setData(T data);
  T getData();
  int getPriority();
  friend std::ostream &operator<<(std::ostream &stream, const Node &node) {
      stream << "Node " << &node << ":" << std::endl;
      stream << node->data << std::endl;
      return stream;
  }
};
#endif
