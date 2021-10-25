
#ifndef Node_h
#define Node_h

template <typename T>
class Node {

    Node prev;
    Node next;
    int priority;
    T data;

public:

  Node(T data, int priority, Node p, Node n);
  Node getNext();
  Node getPrev();
  bool hasPrev();
  bool hasNext();
  void setPrev(Node p);
  void setNext(Node n);
  void setData(T data);
  T getData();
  friend ostream &operator<<( ostream &stream, const Node &node) {
      stream << "Node " << &node << ":" << endl;
      stream << data << endl;
      return stream;
  }
};
#endif
