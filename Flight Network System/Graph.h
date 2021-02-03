#ifndef FLIGHT_NETWORK_SYSTEM_GRAPH_H
#define FLIGHT_NETWORK_SYSTEM_GRAPH_H

#include <iostream>

using namespace std;

#include "Adjacency List.h"
#include "AVL Tree.h"
#include "Hash Map.h"
#include "Queue.h"
#include "Stack.h"

class Graph {
public:
    int vertices;
    bool isDirected;
    EdgeList **adjacencyList;

    Graph(int vertices, bool isDirected) {
        this->vertices = vertices;
        this->isDirected = isDirected;

        // This is an array of multiple linked lists. Each vertex has its own linked list
        adjacencyList = new EdgeList *[vertices];

        for (int i = 0; i < vertices; i++) {
            adjacencyList[i] = new EdgeList();
        }
    }

    // From sourceAirport->destinationAirport
    void AddEdge(int sourceAirport, int destinationAirport, float distance) {
        if (isDirected)
            adjacencyList[sourceAirport]->Insert(destinationAirport, distance);
        else {
            adjacencyList[sourceAirport]->Insert(destinationAirport, distance);
            adjacencyList[destinationAirport]->Insert(sourceAirport, distance);
        }
    }

    // Checks for direct flight between source and destination
    bool areConnected(int sourceAirport, int destinationAirport) {
        ListNode *temp = adjacencyList[sourceAirport]->start;
        while (temp) {
            if (temp->vertex == destinationAirport)
                return true;
            temp = temp->next;
        }

        return false;
    }

    // Traversal of all list of all vertices
    void PrintGraph() {
        for (int i = 0; i < vertices; i++) {
            cout << i << "-> ";
            adjacencyList[i]->PrintEdgeList();
            cout << endl << endl << endl;
        }
    }

    // Print the list of all flights (edges) that an airport (vertex) has
    void SearchFlights(AVLTree *database, int indexOfAirport, HashMap *map) {
        adjacencyList[indexOfAirport]->PrintFlights(database, map);
    }

    // Standard BFS
    bool BFS (int sourceVertex, int destVertex, int parent[], int dist[]) {
        auto *queue = new Queue(vertices);
        bool isVisited[NUMBER_OF_AIRPORTS];
        for (int i = 0; i < vertices; i++) {
            isVisited[i] = false;
            parent[i] = -1;
            dist[i] = INT_MAX;
        }

        isVisited[sourceVertex] = true;
        dist[sourceVertex] = 0;
        queue->Enqueue(sourceVertex);

        int i;
        ListNode *temp;
        while (!queue->isEmpty()) {
            i = queue->Dequeue();
            temp = adjacencyList[i]->start;
            while (temp) {
                if (!isVisited[temp->vertex]) {
                    isVisited[temp->vertex] = true;
                    dist[temp->vertex] = dist[i] + 1;
                    parent[temp->vertex] = i;
                    queue->Enqueue(temp->vertex);
                }

                if (temp->vertex == destVertex)
                    return true;

                temp = temp->next;
            }
        }
        delete queue;
        return false;
    }

    // This Function will tell give you the shortest path between two cities
    // Uses BFS to find shortest path
    Stack<int> *ShortestPath (int sourceVertex, int destVertex) {
        int parent[NUMBER_OF_AIRPORTS];
        int dist[NUMBER_OF_AIRPORTS];

        auto *stack = new Stack<int>();

        if (!BFS(sourceVertex, destVertex, parent, dist)) {
            cout << "The airports have no path between them\n";
            return stack;
        }

        int pred = destVertex;
        stack->push(pred);

        while (parent[pred] != -1) { // Store the predecessors in the stack until the sourceVertex is encountered
            stack->push(parent[pred]);
            pred = parent[pred];
        }

        stack->push(dist[destVertex]); // Push the number of flights at the top of stack, which we pop right as the function returns
        return stack;
    }

    // Get distance between to cities
    float GetDistance(int sourceVertex, int destinationVertex) {
        return adjacencyList[sourceVertex]->GetDistance(destinationVertex);
    }
};

#endif //FLIGHT_NETWORK_SYSTEM_GRAPH_H
