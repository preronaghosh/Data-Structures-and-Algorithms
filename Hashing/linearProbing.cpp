/* Write a program to show linear probing in Hash table */

#include <iostream>
using namespace std;

class HashTable {
    static const int size = 10;
    int hashTable[size]; 
public:
    HashTable() {
        // init the hash table to store -1 indicating empty slot
        for (int i=0; i<size; i++) hashTable[i] = -1;
    }

    // linear probing hash function
    int hashFunction(int key, int i) {
        return (key + i) % size;
    }
    
    bool insert(int val) {
        for (int i=0; i<size; i++) {
            int index = hashFunction(val, i);
            if (hashTable[index] == -1 || hashTable[index] == -2) {
                // empty space
                hashTable[index] = val;
                return true;
            }
        }
        cout << "Hash table is full!" << endl;
        return false;
    }


    bool search(int val) {
        for (int i=0; i<size; i++) {
            int index = hashFunction(val, i);
            if (hashTable[index] == val) return true; 
            else if (hashTable[index] == -1) return false; // empty slot, value not found
        }
        return false; // never found, but hash table is full with other values
    }

    void remove(int val) {
        for (int i=0; i<size; i++) {
            int index = hashFunction(val, i);
            if (hashTable[index] == val) {
                hashTable[index] = -2; // mark it as deleted slot
                cout << "Deleted!" << endl;
                return;
            } else if (hashTable[index] == -1) {
                break;  // empty slot, will not find this val further down in this hash table
            }
        }
        cout << "Could not find the value in hashTable!" << endl;
    }
};