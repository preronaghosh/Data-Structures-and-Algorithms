/* Write a program to show chaining in Hash table to reduce collision */

/* Notes:
- Type of Open hashing (because we keep pushing new values into lists at different indices in the hash table)

- Using modulus hash function, we can get collisions for key values that return the same remainder. Hence, we keep appending 
    key values (with same remainder) as linked list elements at the same index.
    This will use extra space as and when we find new keys ((with same remainder)). Hence, this is an open hashing type

- Loading factor is number of keys (N) divided by size of table (ht) = N / ht.size()
- This is used to analyse TC and SC in hash tables

- Still costly if hash function is (x % 10) (where x = value from array)
- Benefit of modulus is that size of the hash table is limited.

- Hash function should be selected (by developer) such that loading factor shows that the array values have been
  uniformly spread out within the hash table
- Need to know the array data to be able to decide a good hash function

*/

#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    static const int size = 10; // Size of the hash table
    list<int> table[size];      // Array of lists for chaining

    // Simple hash function using modulus
    int hashFunction(int arrVal) {
        return arrVal % size;
    }

public:
    // Insert key into hash table
    void insert(int arrVal) {
        int index = hashFunction(arrVal);
        table[index].push_back(arrVal);
    }

    // Delete key from hash table
    void remove(int arrVal) {
        int index = hashFunction(arrVal);
        table[index].remove(arrVal);
    }

    // Display hash table
    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << " --> ";
            for (int key : table[i]) {
                cout << key << " --> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable ht;

    // Insert keys with potential collisions
    ht.insert(10);
    ht.insert(20); // same bucket as 10 (10 % 10 == 0, 20 % 10 == 0)
    ht.insert(15); // 15 % 10 == 5
    ht.insert(25); // 25 % 10 == 5 (collision with 15)
    ht.insert(30); // 30 % 10 == 0 (collision with 10, 20)

    cout << "Hash Table after insertion:\n";
    ht.display();

    ht.remove(20);
    cout << "\nHash Table after deleting key 20:\n";
    ht.display();

    return 0;
}
