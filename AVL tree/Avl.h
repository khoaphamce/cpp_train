#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <map>

#pragma once

class Avl
{
private:
    /**
     * struct Node for tree
     */
    struct Node {
        int value;
        Node* pLeft = NULL;
        Node* pRight = NULL;

        /**
         * Node constructor
         */
        Node(int newValue) {
            value = newValue;
            Node* pLeft = NULL;
            Node* pRight = NULL;
        };
    };

    /**
     * Tree data 
     */
    Node* root;

    /**
     * Rotation methods
     */
    Node* rightRotate(Node* rootNode);
    Node* leftRotate(Node* rootNode);
    Node* leftRightRotate(Node* rootNode);
    Node* rightLeftRotate(Node* rootNode);

    /**
     * Height and balance factor
     */
    int height(Node* rootNode);
    int balanceFactor(Node* rootNode);

    /**
     * Recursion methods for tree
     */
    Node * insertRec(Node* rootNode, int value);

    void displayRec(Node* rootNode, int level = 0);

public:
    /**
     * Tree constructor
     */
    Avl();
    Avl(int value);

    /**
     * Methods for tree
     */
    bool insertion(int value);
    bool deletion(int value);
    bool search(int value);

    void display();
};

