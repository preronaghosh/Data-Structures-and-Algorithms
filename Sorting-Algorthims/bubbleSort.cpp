#include <iostream>
#include <vector>
// #include <algorithm>


void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
            }
        }
    }
}   

void printArray(std::vector<int>& arr) {
    for(auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> arr{8,5,7,3,2};

    bubbleSort(arr);
    printArray(arr);

    return 0;
}