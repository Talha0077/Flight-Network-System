#ifndef FLIGHT_NETWORK_SYSTEM_AVL_TREE_H
#define FLIGHT_NETWORK_SYSTEM_AVL_TREE_H

#include <iostream>
#include <cmath>

using namespace std;

// The data part of an AVL tree node
class Airport {
public:
    int airportID;
    string airportIATA;
    string airportName;

    Airport(int airportID, string airportIATA, string airportName) {
        this->airportID = airportID;
        this->airportIATA = airportIATA;
        this->airportName = airportName;
    }
};

class AVLnode {
public:
    Airport *airport;
    AVLnode *lChild;
    AVLnode *rChild;

    AVLnode(int airportID, string airportIATA, string airportName) {
        airport = new Airport(airportID, airportIATA, airportName);
        lChild = nullptr;
        rChild = nullptr;
    }
};

void PrintData(AVLnode *node);

class AVLTree {
public:
    AVLnode *root;
    AVLnode *loc;
    AVLnode *ploc;
    AVLnode *imbalancedNode;

    AVLTree() {
        root = nullptr;
        loc = nullptr;
        ploc = nullptr;
    }

    bool isEmpty() {
        return root == nullptr;
    }

    // Checks if an airportID is present
    bool isPresent(int airportID) {

        if (!isEmpty()) {
            loc = root;
            ploc = nullptr;
            while (loc != nullptr) {
                if (loc->airport->airportID == airportID) {
                    return true; // Airport Id is found
                } else if (airportID < loc->airport->airportID) {
                    ploc = loc;
                    loc = loc->lChild;
                } else if (airportID > loc->airport->airportID) {
                    ploc = loc;
                    loc = loc->rChild;
                }
            }
        } else {
            return false;
        }

        return false;
    }

    //Search the Airport
    void Search(Airport *newAirport) {
        loc = root;
        ploc = nullptr;
        while (loc != nullptr) {
            if (loc->airport->airportID == newAirport->airportID) { // This function is not for duplications so function exits here
                break;
            } else if (newAirport->airportID < loc->airport->airportID) {
                ploc = loc;
                loc = loc->lChild;
            } else if (newAirport->airportID > loc->airport->airportID) {
                ploc = loc;
                loc = loc->rChild;
            }
        }
    }

    // Get height of the node
    int GetHeight(AVLnode *node) {
        int height = 0;
        if (!node) // If node is null
            height = -1;
        else
            height = max(GetHeight(node->lChild), GetHeight(node->rChild)) + 1;
        return height;
    }

    int BalanceFactor(AVLnode *node) {
        if (node != nullptr) {
            int balanceFactor = GetHeight(node->lChild) - GetHeight(node->rChild);
            return balanceFactor;
        } else
            return -1;
    }


    void RotateLeft(AVLnode *x, AVLnode *y) {
        Search(x->airport); // To get parent of imbalanced node
        x->rChild = y->lChild;
        y->lChild = x;
        if (x == root) {
            root = y;
        } else {
            if (ploc->lChild == x)
                ploc->lChild = y;
            else
                ploc->rChild = y;
        }
    }

    void RotateRight(AVLnode *x, AVLnode *y) {
        Search(x->airport); // To get parent of imbalanced node
        x->lChild = y->rChild;
        y->rChild = x;
        if (x == root) {
            root = y;
        } else {
            if (ploc->lChild == x)
                ploc->lChild = y;
            else
                ploc->rChild = y;
        }
    }

    void RightLeftRotate(AVLnode *x, AVLnode *y) {
        RotateRight(y, y->lChild);
        RotateLeft(x, x->rChild);
    }

    void LeftRightRotate(AVLnode *x, AVLnode *y) {
        RotateLeft(y, y->rChild);
        RotateRight(x, x->lChild);
    }


    AVLnode *GetImbalancedNode(AVLnode *node) {
        AVLnode *temp = nullptr; // Stores latest imbalanced node
        loc = root;
        while (loc != node) { // Traverse to the node currently inserted and check balance factors of its ancestors
            if (node->airport->airportID < loc->airport->airportID) {
                if (abs(BalanceFactor(loc)) > 1) {
                    temp = loc;
                }
                loc = loc->lChild;
            } else {
                if (node->airport->airportID > loc->airport->airportID) {
                    if (abs(BalanceFactor(loc)) > 1) {
                        temp = loc;
                    }
                    loc = loc->rChild;
                }
            }
        }

        return temp;
    }

    void Insert(Airport *airport) {
        if (isEmpty()) { // Populate root node
            auto *newNode = new AVLnode(airport->airportID, airport->airportIATA, airport->airportName);
            newNode->airport = airport;
            root = newNode;
            return;
        }

        Search(airport);

        if (loc == nullptr && ploc != nullptr) { // Value was not found and its logical parent is in ploc
            auto *newNode = new AVLnode(airport->airportID, airport->airportIATA, airport->airportName);
            newNode->airport = airport;
            if (newNode->airport->airportID < ploc->airport->airportID) {
                ploc->lChild = newNode;
                imbalancedNode = GetImbalancedNode(newNode); // Gets the node that may have become imbalanced due to inserting this new node
            } else {
                ploc->rChild = newNode;
                imbalancedNode = GetImbalancedNode(newNode);
            }
        } else if (loc != nullptr && ploc == nullptr) { // Value was in the root
            cout << "Value is already present in the root node.\n";
        } else {  // loc and ploc both are non-null so the value was found somewhere in the tree
            cout << "Value is already present in the binary tree.\n";
        }

        if (imbalancedNode != nullptr) {
            int balanceFactor = BalanceFactor(imbalancedNode);
            int lChildBalanceFactor = BalanceFactor(imbalancedNode->lChild);
            int rChildBalanceFactor = BalanceFactor(imbalancedNode->rChild);
            if (balanceFactor == -2 && rChildBalanceFactor == -1) { // Right right heavy so rotate left
                RotateLeft(imbalancedNode, imbalancedNode->rChild);
            } else if (balanceFactor == 2 && lChildBalanceFactor == 1) { // Left left heavy so rotate right
                RotateRight(imbalancedNode, imbalancedNode->lChild);
            } else if (balanceFactor == -2 && rChildBalanceFactor == 1) { // Right left heavy so right left rotate
                RightLeftRotate(imbalancedNode, imbalancedNode->rChild);
            } else if (balanceFactor == 2 && lChildBalanceFactor == -1) { // Left right heavy so left right rotate
                LeftRightRotate(imbalancedNode, imbalancedNode->lChild);
            }
        }
    }


    void PrintDetails(int airportID, bool formatted = false) {
        AVLnode *temp = root;
        while (temp != nullptr) {
            if (temp->airport->airportID == airportID) {
                if (!formatted)
                    cout << temp->airport->airportID << " " << temp->airport->airportIATA << " " << temp->airport->airportName;
                else
                    PrintData(temp);
                return;
            } else if (airportID < temp->airport->airportID) {
                temp = temp->lChild;
            } else if (airportID > temp->airport->airportID) {
                temp = temp->rChild;
            }
        }
        cout << "No airport found with this ID\n";
    }
};

void PrintData(AVLnode *node) {
    cout << "Aiport ID: " << node->airport->airportID << endl;
    cout << "Aiport IATA: " << node->airport->airportIATA << endl;
    cout << "Aiport Name: " << node->airport->airportName << endl << endl;
}

void PrintInOrder(AVLnode *node) {
    if (node != nullptr) {
        PrintInOrder(node->lChild);
        PrintData(node);
        PrintInOrder(node->rChild);
    }
}

#endif //FLIGHT_NETWORK_SYSTEM_AVL_TREE_H
