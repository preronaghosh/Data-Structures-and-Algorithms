#include <iostream>
#include <vector>
using namespace std;

/* n = index of last element in heap */
void insertIntoHeap(vector<int>& arr, int n) {
    int temp = arr[n];
    int i = n;

    while(i > 1 && temp > arr[i/2]) {
        arr[i] = arr[i/2];
        i = i/2;
    }
    arr[i] = temp;
}

int main() {
    vector<int> arr = {0, 3, 1, 6, 5, 2, 4};
    
    for (int i=1; i<arr.size(); i++) {
        insertIntoHeap(arr, i);
    }

    cout << "Max Heap: ";
    for (int i=1; i<arr.size(); i++) cout << arr[i] << " ";

    return 0;
}