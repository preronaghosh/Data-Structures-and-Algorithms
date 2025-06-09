/* Write a program to show Double Hashing in a Hash table */

/* Notes: 
- If h2(key) == 0, the probe sequence will never advance
- Loading factor should be less than 0.5 else, insertion times will gradually increase
*/

#include <iostream>
using namespace std;

class HashTable {
    static const int size = 10;
    int hashTable[size];
    const int R = 7; // A prime less than size, used in second hash
    
public:
    HashTable() {
        for (int i = 0; i < size; i++)
            hashTable[i] = -1; // -1 for empty
    }

    int h1(int val) {
        return val % size;
    }

    int h2(int val) {
        return R - (val % R); // Should not be zero
    }

    int hashFunction(int val, int i) {
        return (h1(val) + i * h2(val)) % size;
    }

    bool insert(int key) {
        for (int i = 0; i < size; i++) {
            int index = hashFunction(key, i);
            if (hashTable[index] == -1 || hashTable[index] == -2) {
                hashTable[index] = key;
                return true;
            }
        }
        cout << "Hash table is full. Could not insert " << key << endl;
        return false;
    }

    bool search(int val) {
        for (int i=0; i<size; i++) {
            int index = hashFunction(val, i);
            if (hashTable[index] == -1) return false; // reached an empty slot, this value is not present in the table

            else if (hashTable[index] == val) {
                return true;
            }
        }
        return false;
    }

    void remove(int val) {
        for(int i=0; i<size; i++) {
            int index = hashFunction(val, i);
            if (hashTable[index] == val) { 
                // found the value we need to delete
                hashTable[index] = -2;
                cout << "Deletion successful!" << endl;
                return;
            } else if (hashTable[index] == -1) {
                // this element will not be available further down anyway
                break; 
            }
        }
        cout << "Value not found, deletion failed!" << endl;
    }
};