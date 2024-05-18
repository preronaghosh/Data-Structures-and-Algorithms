/** @brief Lower bound = smallest index in array where arr[index] >= target 
 * @brief Upper bound = smallest index in array where arr[index] > target
*/

#include <iostream>
#include <vector>
using namespace std;

int getLowerBound(vector<int>& nums, int target) {
    int low=0, high=nums.size()-1;
    int ans=nums.size(); // if there is no lower bound, we always have the size of the array as lower bound for the target

    while (low <= high) {
        int mid = low + (high-low)/2;
        if (nums[mid] >= target) {
            ans=mid;
            high=mid-1;
        } 
        else low=mid+1;
    }
    return ans;
}

int getUpperBound(vector<int>& nums, int target) {
    int low=0, high=nums.size()-1;
    int ans=nums.size(); // if there is no lower bound, we always have the size of the array as lower bound for the target

    while (low <= high) {
        int mid = low + (high-low)/2;
        if (nums[mid] > target) {
            ans=mid;
            high=mid-1;
        } 
        else low=mid+1;
    }
    return ans;
}

int main() {
    vector<int> nums = {3,5,8,15,19};
    int ans = getLowerBound(nums, 9);
    cout << "lower bound: " << ans << endl;
    nums = {2,3,6,7,8,8,11,11,11,12};
    ans = getUpperBound(nums, 9);
    cout << "Upper bound: " << ans << endl;
    return 0;
}