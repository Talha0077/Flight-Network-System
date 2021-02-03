#ifndef FLIGHT_NETWORK_SYSTEM_STACK_H
#define FLIGHT_NETWORK_SYSTEM_STACK_H

#include <iostream>
using namespace std;

template<class dataType>
class Node {
public:
    dataType data;
    Node* prev; // Previous pointer because we are implementing stack
};

template<class dataType>
class Stack {
public:
    Node<dataType>* top;

    Stack() {
        top = nullptr;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    void push(dataType value) {
        auto* newNode = new Node<dataType>();
        newNode->data = value;

        if (isEmpty()) {
            top = newNode;
        } else {
            newNode->prev = top;
            top = newNode;
        }
    }

    int pop() {
        Node<dataType>* temp;
        int poppedValue;
        if (!isEmpty()) {
            Node<dataType>* poppedNode;
            poppedNode = top;
            top = top->prev;
            poppedValue = poppedNode->data;
            poppedNode->prev = nullptr;
            delete poppedNode;
            return poppedValue;
        } else {
            cout << "Stack underflow.\n";
            exit(1);
        }
    }

    dataType peek() {
        if (!isEmpty()) {
            return top->data;
        }
        else {
            cout << "Stack is empty.\n";
            exit(1);
        }
    }
};

#endif //FLIGHT_NETWORK_SYSTEM_STACK_H
