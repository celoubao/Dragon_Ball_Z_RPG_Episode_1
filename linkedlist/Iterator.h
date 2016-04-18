/*
 *   Copyright 2016 Charles-Eugene Loubao
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

/**
 * The iterator iterates over a 'Linked List'. This implementation uses instances of Nodes (Node.h)
 * to keep track of the various positions (First, current, last, etc)
 * */
#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template<class T>
class Iterator {
public:

    Iterator();

    // Returns the first element in the iterator (Does not change the current position)
    T getFirstItem();

    // Adds an element to the iterator (Does not change the current position)
    void add(T value);

    // Returns the next element available in the iterator and increment the current position
    T next();

    bool hasNext();

    // Returns the last element in the iterator (Does not change the current position)
    T getLastItem();

    // Reset the position of the iterator
    void resetPosition();

    Node<T> *nextNode();

private:
    bool shouldBeFirst = true;

    Node<T> *head;                  // Represents the first element in the linked list
    Node<T> *current;               // Represents the current element in the linked list
    Node<T> *latestUpdated;         // Represents the latest element updated in the linked list
    Node<T> *tail;                  // Represents the last element in the linked list
};

template<class T>
Iterator<T>::Iterator() {
    head = nullptr;
    current = nullptr;
    latestUpdated = nullptr;
    tail = nullptr;
}

template<class T>
T Iterator<T>::getFirstItem() {
    return head->getValue();
}

template<class T>
void Iterator<T>::add(T value) {
    if (shouldBeFirst) {
        latestUpdated = new Node<T>(value);
        head = latestUpdated;
        tail = latestUpdated;
        shouldBeFirst = false;
    }
    else {
        latestUpdated->setNext(new Node<T>(value));
        latestUpdated = latestUpdated->getNext();
        tail = latestUpdated;
    }
}

template<class T>
T Iterator<T>::getLastItem() {
    return tail->getValue();
}

template<class T>
T Iterator<T>::next() {
    return nextNode()->getValue();
}


template<class T>
bool Iterator<T>::hasNext() {
    return current == nullptr || current->hasNext();
}

template<class T>
void Iterator<T>::resetPosition() {
    current = nullptr;
}

template<class T>
Node<T> *Iterator<T>::nextNode() {
    if (current == nullptr) {
        current = head;
        return current;
    }
    else {
        Node<T> *next = current->getNext();
        current = next;
        return next;
    }
}


#endif //ITERATOR_H
