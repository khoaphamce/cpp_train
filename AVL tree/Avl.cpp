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
 * Find min node method
 */
Avl::Node* Avl::minNode(Node* rootNode) {
    if (rootNode == NULL)
        return NULL;

    Node* receiveNode = minNode(rootNode->pLeft);

    if (receiveNode == NULL)
        return rootNode;
}

/**
 * Insert methods for tree
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
    //display();


    // left-left
    if (balanceFactor(rootNode) == 2 && rootNode->pLeft != NULL && (value < rootNode->pLeft->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Left left case" << std::endl;
        rootNode = rightRotate(rootNode);
    }
    // left-right
    else if (balanceFactor(rootNode) == 2 && rootNode->pLeft != NULL && (value >= rootNode->pLeft->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Left right case" << std::endl;
        rootNode = leftRightRotate(rootNode);
    }
    // right-right
    else if (balanceFactor(rootNode) == -2 && rootNode->pRight != NULL && (value >= rootNode->pRight->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Right right case" << std::endl;
        rootNode = leftRotate(rootNode);
    }
    // right-left
    else if (balanceFactor(rootNode) == -2 && rootNode->pRight != NULL && (value < rootNode->pRight->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Right left case" << std::endl;
        rootNode = rightLeftRotate(root);
    }

    return rootNode;
}

void Avl::insertion(int value) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Add: " << value << std::endl;
    root = insertRec(root, value);
    //display();
    return;
}


/**
 * Delete method for tree
 */
Avl::Node * Avl::deleteRec(Node * rootNode, int value){
    Node* deleteNode = NULL;
    bool rootFlag = 0;
    
    if (rootNode == NULL) {
        return rootNode;
    }
    else if ((rootNode->value) > value) {
        rootNode->pLeft = deleteRec(rootNode->pLeft, value);
    }
    else if ((rootNode->value) < value){
        rootNode->pRight = deleteRec(rootNode->pRight, value);
    }
    // Found node
    else {
        if (rootNode == root)
            rootFlag = 1;

        Node* newNode = minNode(rootNode->pRight);
        newNode->pLeft = rootNode->pLeft;
        Node* toDeleteNode = rootNode;
        delete toDeleteNode;

        if (!rootFlag) {
            rootNode = NULL;
        }
        else {
            rootNode = newNode;
            root = newNode;
        }
        return newNode;
    }

    // left-left
    if (balanceFactor(rootNode) == 2 && rootNode->pLeft != NULL && (value < rootNode->pLeft->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Left left case" << std::endl;
        rootNode = rightRotate(root);
    }
    // left-right
    else if (balanceFactor(rootNode) == 2 && rootNode->pLeft != NULL && (value >= rootNode->pLeft->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Left right case" << std::endl;
        rootNode = leftRightRotate(root);
    }
    // right-right
    else if (balanceFactor(rootNode) == -2 && rootNode->pRight != NULL && (value >= rootNode->pRight->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Right right case" << std::endl;
        rootNode = leftRotate(root);
    }
    // right-left
    else if (balanceFactor(rootNode) == -2 && rootNode->pRight != NULL && (value < rootNode->pRight->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Right left case" << std::endl;
        root = rightLeftRotate(rootNode);
    }

    return rootNode;
}

void Avl::deletion(int value) {
    int rootVal;
    if (root != NULL)
        rootVal = root->value;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Delete: " << value << std::endl;
    deleteRec(root, value);
    //display();

    if (value)

    // left-left
    if (balanceFactor(root) == 2 && root->pLeft != NULL && (value < root->pLeft->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Left left case" << std::endl;
        root = rightRotate(root);
    }
    // left-right
    else if (balanceFactor(root) == 2 && root->pLeft != NULL && (value >= root->pLeft->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Left right case" << std::endl;
        root = leftRightRotate(root);
    }
    // right-right
    else if (balanceFactor(root) == -2 && root->pRight != NULL && (value >= root->pRight->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Right right case" << std::endl;
        root = leftRotate(root);
    }
    // right-left
    else if (balanceFactor(root) == -2 && root->pRight != NULL && (value < root->pRight->value)) {
        std::cout << "----------------------------------------" << std::endl;
        std::cout << "Right left case" << std::endl;
        root = rightLeftRotate(root);
    }

    //display();
    return;
}


void Avl::display() {
    std::cout << "----------------------------------------" << std::endl;
    displayRec(root, 0);
    std::cout << std::endl;
    std::cout << "----------------------------------------\n\n\n" << std::endl;

}

void Avl::displayRec(Node * ptr, int level) {
    int i;
    if (ptr != NULL)
    {
        displayRec(ptr->pRight, level + 1);
        std::cout << std::endl;
        if (ptr == root)
            std::cout << "Root -> ";
        for (i = 0; i < level; i++)
            std::cout << "                ";
        std::cout << ptr->value;
        displayRec(ptr->pLeft, level + 1);
    }
}


/**
 * Search method for tree
 */
Avl::Node* Avl::searchRec(Node* rootNode, int value) {
    if (rootNode == NULL)
        return NULL;
    if (rootNode->value == value)
        return rootNode;

    if (rootNode->value > value)
        return searchRec(rootNode->pLeft, value);
    else
        return searchRec(rootNode->pRight, value);

}

Avl::Node* Avl::search(int value) {
    return searchRec(root, value);
}