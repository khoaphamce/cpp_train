#include "b927.h"

/*
* BST contructor
*/
Bst::Bst() {
    root = NULL;
}


/*
* BST basic method
*/
void Bst::addNode(float newValue) {
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Add: " << newValue << std::endl;
    this->root = addRec(root, newValue);
};

Bst::Node* Bst::addRec(Node* rootNode, float newValue) {
    if (rootNode == NULL) {
        rootNode = new Node(newValue);
    }
    else if ((rootNode->value) > newValue) {
        rootNode->pLeft = addRec(rootNode->pLeft, newValue);
    }
    else {
        rootNode->pRight = addRec(rootNode->pRight, newValue);
    }

    return rootNode;
}

Bst::Node* Bst::minNode(Node* rootNode) {
    if (rootNode == NULL)
        return NULL;

    Node* receiveNode = minNode(rootNode->pLeft);

    if (receiveNode == NULL)
        return rootNode;
}

void Bst::deleteNode(float deleteValue) {
    int rootVal;
    if (root != NULL)
        rootVal = root->value;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "Delete: " << deleteValue << std::endl;
    deleteRec(root, deleteValue);
}

Bst::Node* Bst::deleteRec(Node* rootNode, float deleteValue) {
    Node* deleteNode = NULL;
    bool rootFlag = 0;

    if (rootNode == NULL) {
        return rootNode;
    }
    else if ((rootNode->value) > deleteValue) {
        rootNode->pLeft = deleteRec(rootNode->pLeft, deleteValue);
    }
    else if ((rootNode->value) < deleteValue) {
        rootNode->pRight = deleteRec(rootNode->pRight, deleteValue);
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
    return rootNode;
}

void Bst::displayRec(Node* ptr, int level) {
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

void Bst::display() {
    std::cout << "----------------------------------------" << std::endl;
    displayRec(root, 0);
    std::cout << std::endl;
    std::cout << "----------------------------------------\n\n\n" << std::endl;
}

/*
* BFS through the tree
*/
std::vector<Bst::Node*> Bst::bfs(Node * rootNode) {
    std::vector<Node*> nodeVector;
    std::queue<Node*> nodeQueue;

    if (rootNode == NULL) return nodeVector;

    nodeQueue.push(rootNode);

    while (!nodeQueue.empty()) {
        Node* frontNode = nodeQueue.front();
        nodeQueue.pop();

        nodeVector.push_back(frontNode);

        if (frontNode->pLeft != NULL)
            nodeQueue.push(frontNode->pLeft);
        
        if (frontNode->pRight != NULL)
            nodeQueue.push(frontNode->pRight);
    }

    return nodeVector;
}

/*
* Write, read tree to/from file using bfs method
*/
void Bst::writeToFile(std::fstream& outFile) {
    try {
        if (outFile.fail())
            throw std::exception("File is not open properly");

        std::vector<Node*> nodeVector = bfs(this->root);

        for (int i = 0; i < nodeVector.size(); i++) {
            outFile << nodeVector[i]->value;
            if (i < nodeVector.size() - 1)
                outFile << ' ';
        }
    }
    catch (std::exception msg) {
        std::cout << "Error writing tree to file: " << msg.what() << std::endl;
        return;
    }
}

void Bst::addFromFile(std::fstream& inFile) {
    try {
        if (inFile.fail())
            throw std::exception("File is not open properly");

        while (!inFile.eof()) {
            std::string inStr;
            inFile >> inStr;

            addNode(std::stof(inStr));
        }
    }
    catch (std::exception msg) {
        std::cout << "Error reading file into tree: " << msg.what() << std::endl;
        return;
    }
}


/*
* Execute
*/

void b927::execute(){
    Bst tree;
    char choice;

    std::cout << "-------------- Bst TREE VISUALIZE --------------\n\n\n";

    while (1) {
        std::cout << "Press 1 to insert node \n";
        std::cout << "Press 2 to delete node \n";
        std::cout << "Press 3 to write tree to file \n";
        std::cout << "Press 4 to read tree from file \n";
        std::cout << "Press 5 to exit \n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            float value;
            std::cout << "\nValue of insert node (float): ";
            std::cin >> value;
            tree.addNode(value);
            tree.display();
        }
        else if (choice == '2') {
            float value;
            std::cout << "\nValue of delete node (float): ";
            std::cin >> value;
            std::cout << "IF THERE ARE NO CHANGES, YOU MIGHT ENTERED THE NODE THAT IS NOT IN THE TREE\n\n\n";
            tree.deleteNode(value);
            tree.display();
        }
        else if (choice == '3') {
            std::string path;
            std::cout << "\nPath of file: ";
            std::cin >> path;
            std::fstream outFile(path, std::ios::out);
            tree.writeToFile(outFile);
            tree.display();
        }
        else if (choice == '4') {
            std::string path;
            std::cout << "\nPath of file: ";
            std::cin >> path;
            std::fstream inFile(path, std::ios::in);
            tree.addFromFile(inFile);
            tree.display();
        }
        else if (choice == '5')
            break;
        else {
            std::cout << "Wrong choice, please choose again\n\n\n";
        }
    }
}