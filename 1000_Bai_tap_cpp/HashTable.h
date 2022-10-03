#pragma once

#include <iostream>
#include <string>


class HashTable{
private:
    struct HashTableEntry {
        std::string key;
        int value;

        HashTableEntry(std::string entryKey, int entryValue) : key(entryKey), value(entryValue) {};
    };

    int tableSize = 1000;
    
    HashTableEntry** entry;
    
public:

    /*
     * Constructor for hash table 
     */
    HashTable(int tableSize = 100);

    /*
     * Destructor for hash table
     */
    ~HashTable();

    /*
     * Hashing function
     */
    int hashFunc(std::string key);

    /*
     * Insert into hash_table
     */
    void insert(std::string key, int value);

    /*
     * Search by key in hash_table
     */
    int searchByKey(std::string key);

    /*
     * Remove by key in hash_table
     */
    void remove(std::string key);
};

namespace HashTable_h {
    void execute();
}

