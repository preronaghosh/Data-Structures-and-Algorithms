#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int x) {
    if (low > high) return -1;
    int mid = (low + high)/2;
    if (x == nums[mid]) return mid;
    else if (x < nums[mid]) binarySearch(nums, low, mid-1, x);
    else if (x> nums[mid]) binarySearch(nums, mid+1, high, x);
}

int main() {
    vector<int> nums = {3,5,10,7,1,4,65,78,23,45,91,100,37,51};
    sort(nums.begin(), nums.end());
    int index = binarySearch(nums, 0, nums.size()-1, 65);
    cout << index << endl;
    return 0;
}