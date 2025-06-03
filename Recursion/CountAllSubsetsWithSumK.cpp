/* Write a program to count the total number of subsets/subsequences of an array with a target sum K */

#include <vector>
#include <iostream>
using namespace std;

constexpr int targetSum = 2;

void printArray(vector<int>& vec) {
    if (vec.size()==0) {
        cout << "Null" << endl;
        return;
    }
    
    for (auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;
}

int countSubsets(int index, vector<int>& arr, int& sum) {
    if (index == arr.size()) {
        if (sum == targetSum) return 1;
        return 0;
    }

    // Take current index and add to sum, recall for next value in left subtree
    sum += arr[index];
    int left = countSubsets(index+1, arr, sum);
    
    // Remove the current index sum and recall to add next sum in right subtree
    sum -= arr[index];
    int right = countSubsets(index+1, arr, sum);

    return left + right;
}

int main() {
    vector<int> arr = {1,2,1,2,3,-1};

    int sum = 0;
    cout << countSubsets(0, arr, sum) << endl;
}