
#include "SortedList.h"


template<class T>
SortedList<T>::SortedList() {

}

template<class T>
void SortedList<T>::MakeEmpty() {

}

template<class T>
bool SortedList<T>::IsFull() const {
    return false;
}

template<class T>
int SortedList<T>::GetLength() const {
    return length;
}

template<class T>
bool SortedList<T>::Contains(T someItem) {
    return false;
}

//first     ok
//middle    ok
//end       ok
//empty     ok
template<class T>
void SortedList<T>::PutItem(T item) {

    //empty case
    if (head == nullptr){
        head = new NodeT;
        head->info = item;
        head->next = nullptr;
        length++;
        return;
    }

    NodeT* curr = head;
    NodeT* prevN = nullptr;

    //found place where node should be added
    //middle case
    while (curr != nullptr) {
        if (item < curr->info) {
            NodeT* insertedNode = new NodeT;
            insertedNode->info = item;
            insertedNode->next = curr;

            //beginning case
            if (prevN != nullptr) {
                prevN->next = insertedNode;
            }
            else {
                head = insertedNode;
            }


            length++;
            return;
        }

        prevN = curr;
        curr = curr->next;

    }

    //end case
    if (curr == nullptr) {
        NodeT* insertedNode = new NodeT;
        insertedNode->info = item;
        insertedNode->next = nullptr;
        prevN->next = insertedNode;
        length++;
    }
}

//empty             ok
//beginning         ok
//general/middle    ok
//end               ok
template<class T>
void SortedList<T>::DeleteItem(T item) {

    NodeT* curr = head;
    NodeT* prevN = nullptr;

    while (curr != nullptr) {

        //stops searching when the item is less than the info
        if (item <  curr->info) {
            break;
        }

        if (item == curr->info) {
            if (prevN != nullptr){
                prevN->next = curr->next; //handles the beginning case
            }
            else {
                head = curr->next;
            }
            delete curr;
            length--;
            break;
        }

        prevN = curr;
        curr = curr->next;
    }

}

template<class T>
void SortedList<T>::ResetIterator() {

}

template<class T>
int SortedList<T>::GetNextItem() {
    if (currentPos >= length) {
        throw "Out of bounds";
    }

    return T();
}

