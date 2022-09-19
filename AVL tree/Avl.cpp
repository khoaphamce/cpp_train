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
Avl::Node* Avl::rightRotate(Node* rootNode) {
    Node* newRoot = rootNode->pLeft;
    if (newRoot == NULL) return NULL;

    Node* rightChild = newRoot->pRight;

    newRoot->pRight = rootNode;
    rootNode->pLeft = rightChild;

    return newRoot;
}

Avl::Node* Avl::leftRotate(Node* rootNode) {
    Node* newRoot = rootNode->pRight;
    if (newRoot == NULL) return NULL;

    Node* leftChild = newRoot->pLeft;

    newRoot->pLeft = rootNode;
    rootNode->pRight = leftChild;

    return newRoot;
}

Avl::Node * Avl::leftRightRotate(Node* rootNode) {
    if (rootNode->pLeft == NULL)
        return NULL;

    rootNode->pLeft = leftRotate(rootNode->pLeft);
    rootNode = rightRotate(rootNode);

    return rootNode;
}

Avl::Node * Avl::rightLeftRotate(Node* rootNode) {
    if (rootNode->pRight == NULL)
        return NULL;

    rootNode->pRight = rightRotate(rootNode->pRight);
    rootNode = leftRotate(rootNode);

    return rootNode;
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
        display();
        return rootNode;
    }
    else if ((rootNode->value) > value) {
        rootNode->pLeft = insertRec(rootNode->pLeft, value);
    }
    else{
        rootNode->pRight = insertRec(rootNode->pRight, value);
    }

    // left-left
    if (balanceFactor(rootNode) == 2 && balanceFactor(rootNode->pLeft) == 1) {
        rootNode = rightRotate(rootNode);
        display();
    }
    // left-right
    else if (balanceFactor(rootNode) == 2 && balanceFactor(rootNode->pLeft) == -1) {
        rootNode = leftRightRotate(rootNode);
        display();
    }
    // right-right
    else if (balanceFactor(rootNode) == -2 && balanceFactor(rootNode->pRight) == -1) {
        rootNode = leftRotate(rootNode);
        display();
    }
    // right-left
    else if (balanceFactor(rootNode) == -2 && balanceFactor(rootNode->pRight) == 1) {
        rootNode = rightLeftRotate(rootNode);
        display();
    }

    return rootNode;
}

bool Avl::insertion(int value) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Add: " << value << std::endl;
    root = insertRec(root, value);
    return 1;
}


void Avl::display() {
    std::cout << "----------------------------------------" << std::endl;
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
