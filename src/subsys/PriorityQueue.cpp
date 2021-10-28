#include "main.h"
#include "subsysheaders/PriorityQueue.hpp"

template <class T>
PriorityQueue::PriorityQueue() {

}


bool PriorityQueue::isEmpty(){return pq[front] == NULL;}
void PriorityQueue::enqueue(T data, int priority) {
  
}
T PriorityQueue::deque();
T PriorityQueue::peek();
