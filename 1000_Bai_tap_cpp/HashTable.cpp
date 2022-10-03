#include "HashTable.h"

HashTable::HashTable(int tableSize)
{
    this->tableSize = tableSize;
    entry = new HashTableEntry * [this->tableSize+1];

    for (int i = 0; i <= this->tableSize; i++) {
        entry[i] = NULL;
    }
}

HashTable::~HashTable() {
    delete[] entry;
}

int HashTable::hashFunc(std::string key)
{
    int result = 0;

    for (int i = 0; i < key.length(); i++)
        result += key[i];

    result = result % tableSize;

    return result;
}

void HashTable::insert(std::string key, int value)
{
    int hashValue = hashFunc(key);

    while (hashValue < this->tableSize-1 && entry[hashValue] != NULL && ((entry[hashValue]->key).compare(key))) {
        hashValue++;
    }

    if (entry[hashValue] != NULL)
        delete entry[hashValue];

    entry[hashValue] = new HashTableEntry(key, value);
    
}

int HashTable::searchByKey(std::string key)
{
    int hashValue = hashFunc(key);

    while (hashValue < this->tableSize - 1 && entry[hashValue] != NULL && ((entry[hashValue]->key).compare(key))) {
        hashValue++;
    }

    if (entry[hashValue] != NULL) {
        return entry[hashValue]->value;
    }
    else
        return -1;
}

void HashTable::remove(std::string key)
{
    int hashValue = hashFunc(key);

    while (hashValue < this->tableSize - 1 && entry[hashValue] != NULL && ((entry[hashValue]->key).compare(key))) {
        hashValue++;
    }

    if (entry[hashValue] != NULL) {
        delete entry[hashValue];
        entry[hashValue] = NULL;
        std::cout << "Element with key " << key  << " deleted" << std::endl;
    }
    else {
        std::cout << "No element found with key " << key << std::endl;
    }

    return;
}

void HashTable_h::execute() {
    std::string choice;

    HashTable myTable;

    std::cout << "-------------- HASH TABLE --------------\n\n\n";

    while (1) {
        std::cout << "Press 1 to insert element \n";
        std::cout << "Press 2 to delete element \n";
        std::cout << "Press 3 to search for element \n";
        std::cout << "Press 4 to exit \n\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        if (!choice.compare("1")) {
            std::string key;
            int value;

            std::cout << "Type in key (string): ";
            std::cin >> key;

            std::cout << "Type in value (positive value): ";
            std::cin >> value;

            myTable.insert(key, value);
        }
        else if (!choice.compare("2")) {
            std::string key;

            std::cout << "Type in key (string): ";
            std::cin >> key;

            myTable.remove(key);
        }
        else if (!choice.compare("3")) {
            int foundValue;

            std::string key;

            std::cout << "Type in key: ";
            std::cin >> key;

            foundValue = myTable.searchByKey(key);

            if (foundValue == -1)
                std::cout << "Can not find element with key " << key << std::endl;
            else
                std::cout << "Value of key " << key << ": " << foundValue << std::endl;
        }
        else if (!choice.compare("4"))
            break;

        std::cout << "\n\n\n";
    }
}
