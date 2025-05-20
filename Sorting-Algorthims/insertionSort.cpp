#include <vector>
#include <iostream>

void insertionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i=1; i<n; i++) {
        int val = arr[i];
        int j = i-1;
        while (j>=0 && arr[j] > val) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]= val;
    }
}

void printArray(std::vector<int>& arr) {
    for(auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> arr{8,5,7,3,2,1,10,12,9};
    insertionSort(arr);
    printArray(arr);

    return 0;
}