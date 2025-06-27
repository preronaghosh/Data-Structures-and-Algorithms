/** @brief Lower bound = smallest index in array where arr[index] >= target (Either greater or equal to target)
 * @brief Upper bound = smallest index in array where arr[index] > target (Strictly greater than target)
*/

#include <iostream>
#include <vector>
using namespace std;

int getLowerBound(vector<int>& nums, int target) {
    int left=0, right = nums.size()-1;
    // if no lower bound found for the target, return nums.size() which would mean the same
    int idx = nums.size();

    while (left <= right) {
        int mid = (left + right)/2;
        
        // lower bound means the first value that is >= the target
        // this may not be the first occurence of target in the array
        // so go left even if nums[mid] == target, but store this index because
        // we may not find another one on the left side of the array
        if (nums[mid] >= target) {
            idx = mid;
            right = mid - 1;
        } else {
            left = mid+1;
        }
    }
    return idx;
}

int getUpperBound(vector<int>& nums, int target) {
    int left = 0, right = nums.size() - 1;
    int idx = nums.size(); // if no upper bound found for the target, return nums.size() which would mean the same

    while (left <= right) {
        int mid = (left + right)/2;

        // if the value here is equal to target, go right because we want a strictly higher value (first one that is > than target) 
        if (nums[mid] <= target) {
            left = mid + 1;
        } else {
            // if nums[mid] is > target, then this is a possible index -> store it
            // then go left because there could be a LESSER HIGHER value than the target on the left side of array
            idx = mid;
            right = mid-1;
        }
    }
    return idx;
}

int main() {
    vector<int> nums = {3,5,8,15,19};
    int ans = getLowerBound(nums, 9); // should print 15
    cout << "lower bound: " << nums[ans] << endl; 
    ans = getLowerBound(nums, 8); // should print 8
    cout << "lower bound: " << nums[ans] << endl;

    nums = {2,3,6,7,8,8,11,11,11,12};
    ans = getUpperBound(nums, 6); // should print 7
    cout << "Upper bound: " << nums[ans] << endl;
    ans = getUpperBound(nums, 9); // should print 11
    cout << "Upper bound: " << nums[ans] << endl;
    return 0;
}