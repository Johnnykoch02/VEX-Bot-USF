#include "./subsysHeaders/linkedlist.hpp"

/**
 * Constructors for Linked List 
**/
template <class T>
linkedlist<T>::linkedlist() {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

template <class T>
linkedlist<T>::linkedlist(Node<T> *h) {
    this->size = 0;
    if (h != nullptr) {
        this->head = h;
         this->size++;
    }

}
template <class T>
linkedlist<T>::~linkedlist() {

    if (this->head != nullptr) {  
        Node<T> *node = this->head;
        Node<T> *tempNode;
        while(node->hasNext()) {
        tempNode = node;
        node = node->getNext();
        delete tempNode;
    }
    delete node;
    }
  
}

template <class T>
linkedlist<T>::linkedlist(Node<T> *h, Node<T> *t) {
    this->size = 0;
    if (h != nullptr) {
        this->head = h;
         this->size++;
    }

    if (t != nullptr) {
        this->tail = t;
         this->size++;
    }
}


/**
 * Add Function For Linked List 
**/
template <class T>
void linkedlist<T>::add(T* data, int priority) {

    bool insertion = false;
    Node<T> *node = new Node<T>(data, priority);
    /*
    The List is empty
    */
    if(this->head == nullptr) {
        this->head= node;
        this->tail= node;
        this->size++;
        insertion = true;

    }   
    /*
    The List has only one node, check the prioritys and insert accordingly
    */
    else if(this->tail == this->head) {

        if (this->head->getPriority() < node->getPriority()) { // HEAD has less priority, swap them
            /*Create Linkage*/
            this->head->setPrev(node);
            node->setNext(this->head);
            this->tail = this->head;
            this->head = node;
            insertion = true;
            this->size++;
        }

        else {
            /*Create Linkage*/
            this->tail = node;
            this->head->setNext(this->tail);
            this->tail->setPrev(this->head);
            insertion = true;
            this->size++;
        }
        
    } else  {
        /*
            Our list has multiple nodes, back->front approach until we find our insertion spot
        */
        Node<T> *current = this->tail;
        while(priority>current->getPriority() && insertion==false) {
            //Our current node has not found the right insertion spot, and we haven't reached the end of the list
            if (current != this->head) { 

                current = current->getPrev();
            }
            //Our current node has not found the right insertion spot, and we have reached our head node.
            else {
                /*Create Linkage*/
                node->setNext(this->head);
                this->head->setPrev(node);
                this->head = node;
                insertion = true; 
                this->size++; 
            }
        }
        // WE found our spot!
        if(!insertion) {
            /*
            * Point our new nodes nodes to the current and the currents next node
            * Point the next nodes previous to our new node
            * Point our current nodes next node to our new node
            */
            if(current == this->tail) {// Insertion at end of list (tail)
                /*Create Linkage*/
                this->tail->setNext(node);
                node->setPrev(this->tail);
                this->tail = node;
                this->size++;
            }
            // Insertion in middle of list
            else {
                node->setPrev(current);
                node->setNext(current->getNext());
                current->getNext()->setPrev(node);
                current->setNext(node);
                insertion = true;
                this->size++;
            }
           
        }
    }

}


/**
 * Remove Function for Linked List
**/
template <class T>
bool linkedlist<T>::remove(T* data) {
        /* To Prevent a break, we want to return null if index isn't in our list.*/
    Node<T> *node = this->head;

    for (int i=0; i<this->length(); i++) {
        if (data == node->getData()) {
            /*We want to get references to these two nodes and link them*/
            Node<T> *prev = node->getPrev();
            Node<T> *next = node->getNext();
            /*But as always, edge cases:*/
            if (this->length() > 2)
            {
            /*Edge Case Handling of populated list, with deletions at the front or back*/
                if(prev == nullptr) {
                    next->setPrev(nullptr);
                    this->head = next;
                    delete node;
                }
                else if(next == nullptr) {
                    prev->setNext(nullptr);
                    this->tail = prev;
                    delete node;
                }
                else {
                    /*Create Linkage*/
                    prev->setNext(next);
                    next->setPrev(prev);
                    delete node;
                }

            }/* if (this->length > 2) */

            else /* We have either 1 or two nodes in our list.*/
            {
                if (this->length() == 1) 
                {
                    this->head = nullptr;
                    this->tail = nullptr;
                    delete node;
                }
                else
                {/* We are deleting the head node of a length-2 list */
                    if(node == this->head)
                    {
                        this->head = this->tail;
                        delete node;
                    }/* We are deleting the tail node of a length-2 list */
                    else {
                        this->tail = this->head;
                        delete node;
                    }
                }
            }
            this->size--;
            return true;
        }
        node = node->getNext();
    }/* for (int i=0; i<this->length(); i++) */
    
    return false;
}


/**
 * Get function for Linked List
**/
template <class T>
T* linkedlist<T>::get(int index) {
    /* To Prevent a break, we want to return null if index isn't in our list.*/
    Node<T> *node = this->head;
    if (index >= this->length()) return nullptr;

    for (int i=0; i<this->length(); i++) {
        if(i == index) return node->getData();
        node = node->getNext();
    }
    return nullptr;
}

template <class T>
bool linkedlist<T>::isEmpty() {
    return this->size < 1;
}

template <class T>
T* linkedlist<T>::pop() {
    T* returnValue = new T(this->head->getData());
    this->remove(this->get(0));
    return returnValue;
    /*This could easily be wrong*/
}

template <class T>
T* linkedlist<T>::peek() {
    T* returnValue = new T(this->head->getData());
    return returnValue;
}

template <class T>
void linkedlist<T>::clear() {
    if (this->head != nullptr) {  
        Node<T> *node = this->head;
        Node<T> *tempNode;
        while(node->hasNext()) {
            tempNode = node;
            node = node->getNext();
            delete tempNode;
        }
        delete node;
    }
}

// int length() {return this->size;}