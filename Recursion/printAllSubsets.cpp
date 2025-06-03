/* Write a program to print all subsets/subsequences of an array */
#include <vector>
#include <iostream>
using namespace std;

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

void generateSubsets(int index, vector<int>& arr, vector<int>& res) {
    if (index == arr.size()) {
        printArray(res);
        return;
    }

    res.push_back(arr[index]);
    generateSubsets(index+1, arr, res);
    res.pop_back();
    generateSubsets(index+1, arr, res);
}

int main() {
    vector<int> arr = {1,2,3};
    vector<int> res;
    generateSubsets(0, arr, res);
}