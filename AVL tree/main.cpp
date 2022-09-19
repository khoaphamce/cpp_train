#include <iostream>
#include "Avl.h"

int main() {
    Avl tree;

    tree.insertion(25);
    tree.insertion(22);
    tree.insertion(23);
    tree.insertion(24);
    tree.insertion(29);
    tree.insertion(26);
    tree.insertion(30);

    tree.display();

    return 0;
}