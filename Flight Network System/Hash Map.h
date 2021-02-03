#ifndef FLIGHT_NETWORK_SYSTEM_HASH_MAP_H
#define FLIGHT_NETWORK_SYSTEM_HASH_MAP_H

#include <iostream>
using namespace std;

// Using Linear Probing
// So there is a unique entry at unique index

class HashMap {
public:
    // Array to hold the airport IDs
    int *array;
    // Current size taken
    int currSize;

    HashMap() {
        array = new int[NUMBER_OF_AIRPORTS];
        currSize = 0;
        for (int i = 0; i < NUMBER_OF_AIRPORTS; i++)
            array[i] = -1; // -1 to indicate emptiness
    }

    // This function will return the index at which insertion will be done
    // Airport_id mod NUMBER_OF_AIRPORTS  ->  value between 0-3332 accordingly
    int HashFunction(int ID) {
        return ID % NUMBER_OF_AIRPORTS;
    }

    bool isFull() {
        return currSize == NUMBER_OF_AIRPORTS;
    }

    void Insert(int ID) {
        bool inserted = false;
        int hashCode = HashFunction(ID);

        if (isFull()) {
            cout << "Hash table is full\n";
            return;
        }

        // If the location is empty, we can directly do insertion here
        if (array[hashCode] == -1) {
            array[hashCode] = ID;
            currSize++;
            return;
        }

        // Starts finding the next free location to perform insertion ( Linear Probing Approach )
        for (int i = hashCode + 1; i != hashCode; i++) {

            if (array[i] == -1) { // If the location is empty, insert value and break
                array[i] = ID;
                inserted = true;
                currSize++;
                break;
            }

            if (i == NUMBER_OF_AIRPORTS - 1) // Loop back to the start
                i = -1; // -1 so that loop increments it to 0
        }

        if (!inserted)
            cout << "ID could not be inserted in the array\n";
    }

    // Returns the index for the Airport ID
    int GetIdIndex(int ID) {
        // Get index using HashFunction
        int hashCode = HashFunction(ID);

        // If the ID is at the hashCode
        if (array[hashCode] == ID)
            return hashCode;

        // If the ID wasn't at the HashCode given by hash Function it must be
        // somewhere further from that location

        for (int i = hashCode + 1; i != hashCode; i++) {

            if (ID == array[i])
                return i;

            if (i == NUMBER_OF_AIRPORTS - 1)
                i = -1;
        }

        cout << "ID was not found in the hash table\n";
        return -1;
    }

    bool isPresent(int ID) {
        if (ID < 0 || ID > 12000)
            return false;
        for (int i = 0; i < NUMBER_OF_AIRPORTS; i++) {
            if (array[i] == ID)
                return true;
        }
        return false;
    }

    // Prints the array so we can see which ID are mapped to what index
    void PrintMap() {
        for (int i = 0; i < NUMBER_OF_AIRPORTS; i++) {
            cout << i << ": " << array[i] << endl;
        }
    }
};

#endif //FLIGHT_NETWORK_SYSTEM_HASH_MAP_H
