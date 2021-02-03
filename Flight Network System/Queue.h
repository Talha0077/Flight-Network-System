#ifndef FLIGHT_NETWORK_SYSTEM_QUEUE_H
#define FLIGHT_NETWORK_SYSTEM_QUEUE_H

#include <iostream>
#include<string>

using namespace std;

class Queue {
public:
    int *queue; // Array to hold the elements
    int front;
    int rear;
    int size;
    int count;

    Queue(int size) {
        count = 0;
        front = 0;
        rear = size - 1;
        this->size = size;
        queue = new int[size];
    }

    bool isEmpty() {
        return count <= 0;
    }

    bool isFull() {
        return count == size;
    }

    // Inserting to a Queue
    void Enqueue(int element) {
        //overflow
        if (isFull()) {
            cout << endl << "    The Queue is full , No insertion Allowed";
            return;
        } else {
            rear++;
            if (rear == size) {
                rear = 0;
            }
            queue[rear] = element;
            count++;
        }
    }

    // Deleting from a Queue
    int Dequeue() {
        // underflow
        if (isEmpty()) {
            cout << endl << "   The list is already Empty , nothing can be delete ";
            return 0;

        } else {

            if (front == size) {
                front = 0;
            }
            count--;
            return queue[front++];

        }
    }
};

#endif //FLIGHT_NETWORK_SYSTEM_QUEUE_H
