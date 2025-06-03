/* Write a program to print all subsets/subsequences of an array which meet the target sum k */

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

void generateSubsets(int index, vector<int>& arr, vector<int>& res, int& s) {
    if (index == arr.size()) {
        if (s == targetSum) {
            printArray(res);
        }
        return;
    }

    res.push_back(arr[index]);
    s += arr[index];
    generateSubsets(index+1, arr, res, s);
    res.pop_back();
    s -= arr[index];
    generateSubsets(index+1, arr, res, s);
}

int main() {
    vector<int> arr = {1,2,1};
    vector<int> res;

    int sum = 0;
    generateSubsets(0, arr, res, sum);
}