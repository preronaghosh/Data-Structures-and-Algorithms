#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int binarySearch(vector<int>& nums, int x) {
    int low = 0;
    int high = nums.size()-1;
    while(low <= high) {
        int mid = (low + high)/2;
        if (nums[mid] == x) return mid;
        else if (x < nums[mid]) high = mid-1;
        else if (x > nums[mid]) low = mid+1;
    }
    return -1;
}

int main() {
    vector<int> nums = {3,5,10,7,1,4,65,78,23,45,91,100,37,51};
    sort(nums.begin(), nums.end());
    int index = binarySearch(nums, 99);
    cout << index << endl;
    return 0;
}