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

  Node();
  ~Node();
  Node(T *data, int priority, Node<T> *p, Node<T> *n);
  Node(T *data, int priority);
  Node* getNext();
  Node* getPrev();
  bool hasPrev();
  bool hasNext();
  void setPrev(Node<T> *p);
  void setNext(Node<T> *n);
  void setData(T* data);
  T *getData();
  int16_t getPriority();
  friend ostream &operator<<(ostream &stream, const Node<T> &node) {
      stream << "\tNode " << &node << ":" << endl;
      stream << "\t" << *node.data <<"\t Priority: " << node.priority;
      return stream;
  }
};
#endif
