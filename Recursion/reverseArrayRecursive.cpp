#include <vector>
#include <algorithm>
#include <iostream>

void reverseArr(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    std::swap(arr[left], arr[right]);

    reverseArr(arr, ++left, --right);
}

void printArr(std::vector<int>& arr) {
    for (auto& val : arr) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::vector<int> arr = {1,2,3,4,6};
    int left = 0, right = arr.size()-1;

    printArr(arr);

    reverseArr(arr, left, right);

    printArr(arr);

}