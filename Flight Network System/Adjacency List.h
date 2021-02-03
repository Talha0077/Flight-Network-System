#ifndef FLIGHT_NETWORK_SYSTEM_ADJACENCY_LIST_H
#define FLIGHT_NETWORK_SYSTEM_ADJACENCY_LIST_H

#include <iostream>

#include "AVL Tree.h"
#include "Hash Map.h"

// vertex is an airport
// weight is the distance to that airport
class ListNode {
public:
    int vertex;
    float weight;
    ListNode *next;
};

// The list of edges (flights) of a vertex (airport)
class EdgeList {
public:
    ListNode *start;
    ListNode *last;

    EdgeList() {
        start = nullptr;
        last = nullptr;
    }

    bool isEmpty() {
        return start == nullptr;
    }

    void Insert(int vertex, int weight) {
        auto *node = new ListNode();
        node->vertex = vertex;
        node->weight = weight;

        if (!start && !last) {
            start = node;
            last = node;
        }
        else {
            last->next = node;
            last = node;
        }
    }

    // Prints the edges for this vertex
    void PrintEdgeList() {
        ListNode *temp = start;

        while (temp) {
            std::cout << "(" << temp->vertex << ", " << temp->weight << ")";
            temp = temp->next;
            if (temp) {
                std::cout << "->";
            }
        }

    }

    void PrintFlights(AVLTree *database, HashMap *map) {
        ListNode *temp = start;
        while (temp) {
            database->PrintDetails(map->array[temp->vertex]); // Get the ID of the airport from the map
            std::cout << std::endl;
            temp = temp->next;
        }
    }

    float GetDistance(int destinationVertex) {
        ListNode *temp = start;
        while (temp) {
            if (temp->vertex == destinationVertex)
                return temp->weight;
            temp = temp->next;
        }
        return 0;
    }
};

#endif //FLIGHT_NETWORK_SYSTEM_ADJACENCY_LIST_H
