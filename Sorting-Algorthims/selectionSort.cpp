#include <iostream>
#include <vector>

/*
    Time Complexity = O(N x N)
    Space Complexity - O(N)
*/
void selectionSort(std::vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i <= n - 2; i++)
    {
        int minPos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minPos])
            {
                minPos = j;
            }
        }
        // swap arr[i] and arr[minPos]
        if (minPos != i)
        {
            int temp = arr[i];
            arr[i] = arr[minPos];
            arr[minPos] = temp;
        }
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
    std::vector<int> arr = {64, 25, 12, 22, 11};

    std::cout << "Original array: ";
    printArray(arr);

    selectionSort(arr);

    std::cout << "Sorted array: ";
    printArray(arr);

    return 0;
}