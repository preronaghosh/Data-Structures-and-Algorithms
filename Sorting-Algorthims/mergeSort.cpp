#include <iostream>
#include <vector>

// Function to merge two sorted halves of an array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i]);
        i++;
    }

    while (j <= right) {
        temp.push_back(arr[j]);
        j++;
    }
    
    int pTemp = 0;
    for (int k = left; k <= right; k++) {
        arr[k] = temp[pTemp]; // index offset since temp starts from 0 always
        pTemp++; 
    }
}


void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left >= right) return;

    int mid = (left+right)/2; // 7 --> 3

    mergeSort(arr, left, mid); // arr, 0 , 7 --> arr, 0, 3
    mergeSort(arr, mid+1, right); // arr, 8, 14 --> arr, 4, 7
    merge(arr, left, mid, right); 
}

void printArray(std::vector<int>& arr) {
    for(auto& x : arr) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> arr{10,3,1,11,5,6,14,2,8,13,4,7,9,12,15};

    mergeSort(arr, 0, arr.size()-1);
    printArray(arr);
    
    return 0;
}