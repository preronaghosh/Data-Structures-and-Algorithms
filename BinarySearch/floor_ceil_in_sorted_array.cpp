// ceil is same as lower bound
// floor = largest number in array which is <= target 
#include <vector>
#include <iostream>
using namespace std;

int floorOfTarget(vector<int> &nums, int target) {
    int low=0, high=nums.size()-1;
    int ans=high;

    while (low <= high) {
        int mid = low + (high-low)/2;
        if (nums[mid] <= target) {
            ans = mid;
            low = mid+1;
        } else high = mid-1;
    }
    return nums[ans];
}

int ceilOfTarget(vector<int> &nums, int target) {
    int low=0, high=nums.size()-1;
    int ans=high;
    while (low <= high) {
        int mid = low + (high-low)/2;
        if (nums[mid] >= target) {
            ans=mid;
            high=mid-1;
        } else low = mid+1;
    }
    return nums[ans];
}

int main() {
    vector<int> nums = {10, 20, 24, 30, 40, 50};
    int ans = floorOfTarget(nums, 25);
    cout << ans << endl;
    ans = ceilOfTarget(nums, 25);
    cout << ans << endl;
    return 0;
}