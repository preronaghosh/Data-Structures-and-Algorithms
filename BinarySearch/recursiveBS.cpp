#include <iostream>
#include <vector>
#include <algorithm> // for sort

using namespace std;

int binarySearch(vector<int>& nums, int low, int high, int x) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2; // Correct midpoint calculation
    if (x == nums[mid]) {
        return mid;
    } else if (x > nums[mid]) { // search right half
        return binarySearch(nums, mid + 1, high, x);
    }
    return binarySearch(nums, low, mid - 1, x); // search left half
}

int main() {
    vector<int> nums = {3, 5, 10, 7, 1, 4, 65, 78, 23, 45, 91, 100, 37, 51};
    sort(nums.begin(), nums.end());
    cout << "Sorted array: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    
    int index = binarySearch(nums, 0, nums.size() - 1, 65);
    cout << index << endl;
    return 0;
}
