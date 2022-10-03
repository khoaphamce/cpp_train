#include <iostream>
#include <string>
#include <thread>

// Basic programming
#include "b1.h"
#include "b39.h"

// Function and code structure
#include "b115.h"
#include "b117.h"

// Recursion
#include "b703.h"
#include "b707.h"

// Array
#include "b158.h"
#include "b166.h"

// Pointer
#include "b776.h"
#include "b777.h"

// String and OOP
#include "b593_606.h"

// Tree, file and struct
#include "b927.h"

// Search, Dynamic programming
#include "b306.h"

// Linked list
#include "b824.h"

// Sort 
#include "b255.h"

// Hash table
#include "HashTable.h"

int main() {
    std::vector<void (*) ()> executeList = {
        (b1::execute),
        (b39::execute),

        (b115::execute),
        (b117::execute),

        (b703::execute),
        (b707::execute),

        (b158::execute),
        (b166::execute),

        (b776::execute),
        (b777::execute),

        (b593_606::execute),

        (b927::execute),

        (b306::execute),

        (b824::execute),

        (b255::execute),

        (HashTable_h::execute)
    };

    std::vector<std::string> nameList = {
        "Basic programming - b1",
        "Basic programming - b39",

        "Function and code structure - 115",
        "Function and code structure - 117",

        "Recursion - 703",
        "Recursion - 707",

        "Array - 158",
        "Array - 166",

        "Pointer - 776",
        "Pointer - 777",

        "String and OOP - 593 -> 606",

        "Tree, file, struct - 927",

        "Search, Dynamic programming - 306",

        "Linked list - 824",

        "Sort - 255",

        "Hash table"
    };

    int choice;

    while (1) {
        for (int i = 0; i < nameList.size(); i++) {
            std::cout << i << ": " << nameList[i] << std::endl;
        }
        std::cout << nameList.size() << ": " << "EXIT" << std::endl;

        std::cout << "\nYour choice: ";
        std::cin >> choice;

        if (choice == nameList.size()) break;

        while (choice < 0 || choice > executeList.size()) {
            std::cout << "Please choose again, you chose wrong: ";
            std::cin >> choice;
        }


        /*void (*function_ptr)();
        function_ptr = executeList[choice];
        function_ptr();*/

        executeList[choice]();
    }

    return 0;
}