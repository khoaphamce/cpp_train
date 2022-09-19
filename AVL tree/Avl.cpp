#include "Avl.h"
/**
 * Tree constructor
 */
Avl::Avl() {
    root = NULL;
}

Avl::Avl(int value) {
    root = new Node(value);
}


/**
 * Rotation methods
 */
void Avl::rightRotate(Node* rootNode) {
    Node* newRoot = rootNode->pLeft;
    if (newRoot == NULL) return;

    Node* rightChild = newRoot->pRight;

    newRoot->pRight = rootNode;
    rootNode->pLeft = rightChild;
}

void Avl::leftRotate(Node* rootNode) {
    Node* newRoot = rootNode->pRight;
    if (newRoot == NULL) return;

    Node* leftChild = newRoot->pLeft;

    newRoot->pLeft = rootNode;
    rootNode->pRight = leftChild;
}

void Avl::leftRightRotate(Node* rootNode) {
    if (rootNode->pLeft == NULL)
        return;

    leftRotate(rootNode->pLeft);
    rightRotate(rootNode);
}

void Avl::rightLeftRotate(Node* rootNode) {
    if (rootNode->pRight == NULL)
        return;

    rightRotate(rootNode->pRight);
    leftRotate(rootNode);
}


/**
 * Height and balance factor
 */
int Avl::height(Node* rootNode) {
    if (rootNode == NULL) return 0;

    int leftHeight = height(rootNode->pLeft);
    int rightHeight = height(rootNode->pRight);

    return std::max(leftHeight, rightHeight) + 1;
}

int Avl::balanceFactor(Node* rootNode) {
    if (rootNode == NULL) return 0;
    return height(rootNode->pLeft) - height(rootNode->pRight);
}


/**
 * Methods for tree
 */
Avl::Node * Avl::insertRec(Node* rootNode, int value) {
    if (rootNode == NULL) {
        rootNode = new Node(value);
        return rootNode;
    }
    else if ((rootNode->value) > value) {
        rootNode->pLeft = insertRec(rootNode->pLeft, value);
    }
    else{
        rootNode->pRight = insertRec(rootNode->pRight, value);
    }
    return rootNode;
}

bool Avl::insertion(int value) {
    root = insertRec(root, value);
    return 1;
}


void Avl::display() {
    displayRec(root, 0);
    std::cout << std::endl;
}

void Avl::displayRec(Node * ptr, int level) {
    int i;
    if (ptr != NULL)
    {
        displayRec(ptr->pRight, level + 1);
        std::cout << std::endl;
        for (i = 0; i < level; i++)
            std::cout << "         ";
        std::cout << ptr->value;
        displayRec(ptr->pLeft, level + 1);
    }
}
