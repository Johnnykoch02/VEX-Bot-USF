#include "main.h"
#include "./subsysheaders/linkedlist.hpp"

template <class T>
linkedlist<T>::linkedlist(Node<T> h, Node<T> t) {
    if (h != NULL) {
        this->head = h;
         this->size++;
    }

    if (t != NULL) {
        this->tail = t;
         this->size++;
    }
}

template <class T>
void linkedlist<T>::add(T data, int priority) {
    bool insertion = false;
    if(this->head == NULL) {
        this->head=Node<T>(data, priority);
         this->size++;
    }   else if(this->tail == NULL) {
        if (this->head.priority < priority) {
            Node<T> copy = Node<T>(this->head.data, this->head.priority);
            head = Node<T>(data, priority, NULL, copy);
            this->tail = copy;
        }
        else {
            this->tail = Node<T>(data, priority, this->head, NULL);
        }
    } else  {
        Node<T> current = this->tail;
        while(priority>current->priority && insertion==false) {
            if (current != this->head) {
                current = current.getPrev();
            }
            else {
                Node<T> node = Node<T>(data, priority, NULL, this->head);
                this->head = node;
                insertion = true; 
                this->size++; 
            }
        }
        // WE found our spot!
        if(insertion == false) {
            /*
            * Point our new nodes nodes to the current and the currents next node
            * Point the next nodes previous to our new node
            * Point our current nodes next node to our new node
            */
            Node<T> node = Node<T>(data, priority, current, current.getNext()); 
            current.getNext().setPrev(node);
            current.setNext(node);
            insertion = true;
            this->size++;
        }
    }

}


template <class T>
void linkedlist<T>::remove(T data) {
    
}


template <class T>
T linkedlist<T>::get(int index) {
    
}


