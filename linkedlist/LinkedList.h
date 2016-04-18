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
 * An implementation of a List. The list is a wrapper around the Iterator class
 * that keep track of the size of underlining linked list.
 */

#include "Iterator.h"

#ifndef LIST_H
#define LIST_H

template<class T>
class LinkedList {
public:
    LinkedList();

    ~LinkedList();

    // Removes a value from the LinkedList
    void remove(int index);

    // Adds a value to the LinkedList
    void add(T value);

    // Returns the value at a specific position in the LinkedList
    T get(int index);

    void set(int index, T value);

    // Returns the size of the LinkedList
    int getSize();

private:
    // Backend
    Iterator<T> *iterator;

    // Size
    int size;
};


template<class T>
LinkedList<T>::LinkedList() {
    this->iterator = new Iterator<T>();
    size = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
    //delete (this->iterator);
}


template<class T>
void LinkedList<T>::add(T value) {
    iterator->add(value);
    size += 1;
}

template<class T>
void LinkedList<T>::remove(int index) {
    // TODO: Implement
}

template<class T>
int LinkedList<T>::getSize() {
    return size;
}

template<class T>
T LinkedList<T>::get(int index) {
    T value;

    // We avoid unnecessary loops by checking if we want the first item or the last item of this iterator;
    if (index == 0) {
        value = iterator->getFirstItem();
    }
    else if (index == size - 1) {
        value = iterator->getLastItem();
    }
    else {
        for (int i = 0; i <= index && iterator->hasNext(); i++) {
            value = iterator->next();
        }
        iterator->resetPosition();
    }
    return value;
}

template<class T>
void LinkedList<T>::set(int index, T value) {
    Node<T> *ptr = nullptr;
    for (int i = 0; i <= index && iterator->hasNext(); i++) {
        ptr = iterator->nextNode();
    }

    if (ptr != nullptr) {
        ptr->setValue(value);
    }
    iterator->resetPosition();
}


#endif //LIST_H
