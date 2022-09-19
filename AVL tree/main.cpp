#include <iostream>
#include "Avl.h"

int main() {
    Avl tree;

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
    

    tree.display();

    return 0;
}