#ifndef FLIGHT_NETWORK_SYSTEM_FLIGHT_NETWORK_H
#define FLIGHT_NETWORK_SYSTEM_FLIGHT_NETWORK_H

// Built in libraries
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// Our own header files
#include "Graph.h"
#include "AVL Tree.h"
#include "Hash Map.h"
#include "Stack.h"

// Give absolute path for Clion, relative for VS
#define filePath "Dataset.txt"

class FlightNetwork {
public:
    int airports; // Number of Airports
    bool oneWay;  // Graph is directed or not

    Graph *flightRoutes; // A graph of the routes
    AVLTree *airportDatabase; // An AVL tree having the details of all the airports arranged by their IDs
    HashMap *IDtoIndex; //  A hashmap that maps the airport IDs to array indexes in the graph

    int sourceAirportID; // Source vertex
    string sourceAirportIATA;
    string sourceAirportName;

    int destAirportID; // Destination vertex
    string destAirportIATA;
    string destAirportName;

    float distance; // Weight of edge

    FlightNetwork(int airports, bool oneWay) {
        this->oneWay = oneWay;

        flightRoutes = new Graph(NUMBER_OF_AIRPORTS, oneWay);
        airportDatabase = new AVLTree();
        IDtoIndex = new HashMap();

        ifstream dataFile(filePath);
        string temp; // To discard garbage data
        string line;

        if (!dataFile.is_open()) {
            cout << "File failed to open. Make sure the path you have given is correct\n";
            exit(1);
        }

        while (getline(dataFile, line)) {
            stringstream currentLine(line);

            // Source data
            getline(currentLine, temp, ',');
            if (!temp.empty())
                sourceAirportID = stoi(temp);
            else
                sourceAirportID = -1;
            getline(currentLine, sourceAirportIATA, ',');
            getline(currentLine, sourceAirportName, ',');

            // Destination data
            getline(currentLine, temp, ',');
            if (!temp.empty())
                destAirportID = stoi(temp);
            else
                destAirportID = -1;
            getline(currentLine, destAirportIATA, ',');
            getline(currentLine, destAirportName, ',');

            // Distance
            getline(currentLine, temp);
            if (!temp.empty())
                distance = stof(temp);
            else
                distance = -1;

            // Execute only if the source airport ID is not Present in the database and if it is not null
            if (!airportDatabase->isPresent(sourceAirportID) && sourceAirportID != -1) {
                auto *sourceAirport = new Airport(sourceAirportID, sourceAirportIATA, sourceAirportName);
                airportDatabase->Insert(sourceAirport); // Inserting it to the AVL Tree for airport Database
                IDtoIndex->Insert(sourceAirportID); // Inserting the Source Airport ID in Hash Table
            }


            // Execute only if the destination airport ID is not Present in the database and if it is not null
            if (!airportDatabase->isPresent(destAirportID) && destAirportID != -1) {
                auto *destAirport = new Airport(destAirportID, destAirportIATA, destAirportName);
                airportDatabase->Insert(destAirport);
                IDtoIndex->Insert(destAirportID);
            }

            // Execute only if the both source & destination IDs are not null and they are not connected
            if (sourceAirportID != -1 && destAirportID != -1 && !flightRoutes->areConnected(IDtoIndex->GetIdIndex(sourceAirportID), IDtoIndex->GetIdIndex(destAirportID)))
                flightRoutes->AddEdge(IDtoIndex->GetIdIndex(sourceAirportID), IDtoIndex->GetIdIndex(destAirportID), distance);
        }
        dataFile.close();
    }

    void PrintDetails(int airportID, bool isMappingNeeded = false) {
        if (!isMappingNeeded)
            airportDatabase->PrintDetails(airportID);
        else
            airportDatabase->PrintDetails(IDtoIndex->array[airportID]);
    }


    // This function is showing all the flights from a specific Airport
    void SearchFlights(int airportID) {
        cout << "\nThe airport ";
        airportDatabase->PrintDetails(airportID); // Print the source airport details from the airportDatabase (AVL Tree)
        cout << " has flights to:\n";

        // Call the Search flights method in Graph Class that will further call a print Method in Adjacency List class
        // IDtoIndex is a Hash map here
        flightRoutes->SearchFlights(airportDatabase, IDtoIndex->GetIdIndex(airportID), IDtoIndex);
    }


    // This Function will tell you the shortest path between two airports
    Stack<int> *GetRoute(int sourceAirport, int destAirport) {
        return flightRoutes->ShortestPath(IDtoIndex->GetIdIndex(sourceAirport), IDtoIndex->GetIdIndex(destAirport));
    }


    // This function will return the distance between two airports
    float GetDistance(int sourceAirport, int destinationAirport) {
        float dist = flightRoutes->GetDistance(IDtoIndex->GetIdIndex(sourceAirport), IDtoIndex->GetIdIndex(destinationAirport));
        return dist != 0 ? dist : 0;
    }
};

#endif //FLIGHT_NETWORK_SYSTEM_FLIGHT_NETWORK_H
