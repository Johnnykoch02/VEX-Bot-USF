
#ifndef linkedlist_h
#define linkedlist_h

//#ifdef __cplusplus
#include "./subsysHeaders/Node.hpp"
#include <iostream>
#include <string>
//#endif

using namespace std;

template <class T>
class linkedlist {


  int size;
  Node<T> *g(int index, int cur, Node<T> *curr);
public:
    
  Node<T> *head;
  Node<T> *tail;
  linkedlist<T>();
  ~linkedlist();
  linkedlist(Node<T> *h);
  linkedlist(Node<T> *h, Node<T> *t);
  bool isEmpty();

  void add(T* data, int priority);
  bool remove(T* data);
  void clear(); 
  T* get(int index);
  T* pop();
  T* peek();
  int length(){ return this->size;}

friend ostream& operator<<(ostream &stream, linkedlist<T> const &ll) {
      stream << "LinkedList @ " << &ll << " of size " << ll.size << ", " << "data:" << endl;
      Node<T> *curr = ll.head;
      int16_t index = 0;
      while(!(curr == nullptr)) {
        stream << *curr << ": "<<"at Index "<<index<< endl;
        curr = curr->getNext();
        index++;
      }
      return stream;
  }
};

#endif
