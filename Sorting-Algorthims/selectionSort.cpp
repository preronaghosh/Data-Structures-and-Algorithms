#include <iostream>
#include <vector>

/*
    Time Complexity = O(N x N)
    Space Complexity - O(1)
*/
void selectionSort(std::vector<int> &arr) {
    int n = arr.size();
    for(int i=0; i<n-1; i++) {
        int minPos=i;
        for(int j=i+1; j<n; j++) {
            if (arr[j] < arr[minPos]) {
                minPos = j;
            }
        }
        std::swap(arr[i], arr[minPos]);
    }
}

void printArray(const std::vector<int> &arr)
{
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr{8,5,7,3,2,1,10,12,9};

    std::cout << "Original array: ";
    printArray(arr);

    selectionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}