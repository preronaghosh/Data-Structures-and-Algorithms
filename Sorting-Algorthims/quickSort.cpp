#include <iostream>
#include <vector>


void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[low];
    int i = low-1;
}

void quickSort(std::vector<int>& arr, int low, int high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi-1);
    quickSort(arr, pi+1, high);
}

void printArray(std::vector<int>& arr) {
    for(auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr{8,5,7,3,2,1,10,12,9};

    std::cout << "Original array: ";
    printArray(arr);


    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}