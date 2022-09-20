#include <iostream>
#include "Avl.h"

int main() {
    Avl tree;
    char choice;

    std::cout << "-------------- AVL TREE VISUALIZE --------------\n\n\n";
    
    while (1) {
        std::cout << "Press 1 to insert node \n";
        std::cout << "Press 2 to delete node \n";
        std::cout << "Press 3 to search for node \n";
        std::cout << "Press 4 to exit \n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (choice == '1') {
            int value;
            std::cout << "\nValue of insert node (integer): ";
            std::cin >> value;
            tree.insertion(value);
            tree.display();
        }
        else if (choice == '2') {
            int value;
            std::cout << "\nValue of delete node (integer): ";
            std::cin >> value;
            std::cout << "IF THERE ARE NO CHANGES, YOU MIGHT ENTERED THE NODE THAT IS NOT IN THE TREE\n\n\n";
            tree.deletion(value);
            tree.display();
        }
        else if (choice == '3') {
            int value;
            std::cout << "\nValue of searching node (integer): ";
            std::cin >> value;
            Avl::Node * foundNode = tree.search(value);

            if (foundNode == NULL)
                std::cout << "Node is not in the tree\n\n\n";
            else
                std::cout << "Node found at address: " << foundNode << "\n\n\n";
        }
        else if (choice == '4')
            break;
        else {
            std::cout << "Wrong choice, please choose again\n\n\n";
        }
    }

    /*Avl tree;
    int node = 99;

    tree.insertion(50);
    tree.insertion(60);
    tree.insertion(65);
    tree.insertion(63);
    tree.insertion(72);
    tree.insertion(90);
    tree.insertion(20);
    tree.insertion(23);
    tree.insertion(10);
    tree.insertion(15);

    tree.deletion(65);
    tree.deletion(15);

    tree.display();

    std::cout << "Find node: " << node << std::endl;
    Avl::Node* foundNode = tree.search(node);
    std::cout << "Found node at address: " << foundNode << std::endl;*/

    return 0;
}