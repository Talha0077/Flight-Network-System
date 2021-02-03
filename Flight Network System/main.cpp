#define NUMBER_OF_AIRPORTS 3333

#include <iostream>
#include "Flight Network.h"
using namespace std;

int main() {
    auto *flightNetwork = new FlightNetwork(NUMBER_OF_AIRPORTS, true);

    cout << "\t\t\t\t----- WELCOME TO THE FLIGHT NETWORK SYSTEM -----\n";
    cout << "What action would you like to perform, enter the respective number (-1 to exit) :\n";
    cout << "1. Get name and IATA code of an airport from its ID.\n";
    cout << "2. Search flights from an airport.\n";
    cout << "3. Shortest path between two airports.\n";
    cout << "4. Distance between two airports.\n";
    cout << "5. Print the whole database.\n";

    int choice = -1;
    cout << "Enter:";
    cin >> choice;

    // The variables to store what the user is going to enter
    int srcAirportID;
    int destAirportID;
    Stack<int> *stack; // To store the path of the shortest route
    float dist;

    if (choice != -1) {
        do {
            switch (choice) {
                case 1:
                    cout << "Enter airport ID:";
                    cin >> srcAirportID;
                    flightNetwork->airportDatabase->PrintDetails(srcAirportID, true);
                    break;

                case 2:
                    cout << "Enter airport ID:";
                    cin >> srcAirportID;
                    if (flightNetwork->IDtoIndex->isPresent(srcAirportID)) //
                        flightNetwork->SearchFlights(srcAirportID);
                    else
                        cout << "No airport exists in the database with this ID" << endl;
                    break;

                case 3:
                    cout << "Enter starting airport ID:";
                    cin >> srcAirportID;
                    cout << "Enter destination airport ID:";
                    cin >> destAirportID;
                    // We are already maintaining an array of the airport IDs in the hash map class so we use that to check if the user entered IDs are present
                    // This is to avoid calling functions with the wrong ID so the program does not crash
                    if (flightNetwork->IDtoIndex->isPresent(srcAirportID) && flightNetwork->IDtoIndex->isPresent(destAirportID)) {
                        stack = flightNetwork->GetRoute(srcAirportID, destAirportID);
                        cout << endl;
                        if (!stack->isEmpty()) {
                            int flights = stack->pop();
                            while (!stack->isEmpty()) {
                                flightNetwork->PrintDetails(stack->pop(), true);
                                cout << " -> ";
                            }
                            cout << "\b\b\b  " << endl;
                            cout << "You will have to take " << flights << " flight(s).";
                            delete stack; // Was created using new operator in Graph->ShortestPath
                        }
                    } else
                        cout << "No airport exists in the database with this ID" << endl;
                    break;

                case 4:
                    cout << "Enter starting airport ID:";
                    cin >> srcAirportID;
                    cout << "Enter destination airport ID:";
                    cin >> destAirportID;

                    if (flightNetwork->IDtoIndex->isPresent(srcAirportID) && flightNetwork->IDtoIndex->isPresent(destAirportID)) {
                        if (!flightNetwork->flightRoutes->areConnected(srcAirportID, destAirportID)) {
                            cout << "There is no flight between these two airports\n";
                            break;
                        }
                        dist = flightNetwork->GetDistance(srcAirportID, destAirportID);
                        cout << "\nDistance from ";
                        flightNetwork->PrintDetails(srcAirportID);
                        cout << " to ";
                        flightNetwork->PrintDetails(destAirportID);
                        cout << " is " << dist << " km" << endl;
                        cout << "The flight is about " << int(dist / 750) + 1 << " to " << int(dist / 750) + 2 << " hours";
                    } else
                        cout << "No airport exists in the database with this ID" << endl;
                    break;

                case 5:
                    PrintInOrder(flightNetwork->airportDatabase->root);
                    cout << endl;
                    break;

                default:
                    cout << "Enter something from 1-5\n";
            }
            cout << "\nEnter:";
            cin >> choice;
        } while (choice != -1);
    }

    cout << "Happy flying!\n";
    return 0;
}
