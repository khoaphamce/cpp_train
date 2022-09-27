#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>

class Bst {
public:
    /*
    * Node declare and constructor
    */
    struct Node {
        float value;
        Node* pLeft;
        Node* pRight;

        Node() : value(0), pLeft(NULL), pRight(NULL) {}
        Node(float newValue) : value(newValue), pLeft(NULL), pRight(NULL) {}

    };

private:
    Node* root = NULL;

    Node* addRec(Node* rootNode, float newValue);
    Node* deleteRec(Node* rootNode, float deleteValue);
    void displayRec(Node* ptr, int level);
    Node* minNode(Node* rootNode);
    std::vector<Node*> bfs(Node* rootNode);

public:
    /*
    * BST contructor
    */
    Bst();

    /*
    * BST basic method
    */
    void addNode(float newValue); 
    void deleteNode(float deleteValue);
    void display();
    void writeToFile(std::fstream& outFile);
    void addFromFile(std::fstream& inFile);
};

namespace b927 {
    void execute();
}