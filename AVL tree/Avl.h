#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <map>

#pragma once

class Avl
{
public:
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
private:
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
    Node* insertRec(Node* rootNode, int value);
    Node* deleteRec(Node* rootNode, int value);
    Node* searchRec(Node* rootNode, int value);
    Node* minNode(Node* rootNode);
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
    void insertion(int value);
    void deletion(int value);
    Node* search(int value);

    void display();
};

