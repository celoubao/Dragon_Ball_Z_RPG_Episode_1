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
 * Implementation of the 'node' pattern to create linked lists
 * A node represents an element in a linked list.
 * Each node has a value, and a pointer to the element next to it in the list
 * and a pointer to the element before it in the list
 */

#ifndef NODE_H
#define NODE_H

template<class T>
class Node {
public:
    Node(T value);

    bool hasNext();

    Node<T> *getNext();

    void setNext(Node *node);

    bool hasPrevious();

    Node<T> *getPrevious();

    void setPrevious(Node<T> *node);

    T getValue();

    void setValue(T newValue);

private:
    T value;
    Node<T> *previousNode = nullptr;
    Node<T> *nextNode = nullptr;
};

template<class T>
Node<T>::Node(T value) {
    this->value = value;
}


template<class T>
bool Node<T>::hasNext() {
    return this->getNext() != nullptr;
}

template<class T>
Node<T> *Node<T>::getNext() {
    return this->nextNode;
}

template<class T>
void Node<T>::setNext(Node<T> *node) {
    this->nextNode = node;
}

template<class T>
bool Node<T>::hasPrevious() {
    return this->getPrevious() != nullptr;
}

template<class T>
Node<T> *Node<T>::getPrevious() {
    return this->previousNode;
}

template<class T>
void Node<T>::setPrevious(Node<T> *node) {
    this->previousNode = node;
}

template<class T>
T Node<T>::getValue() {
    return this->value;
}

template<class T>
void Node<T>::setValue(T newValue) {
    this->value = newValue;
}

#endif //NODE_H
