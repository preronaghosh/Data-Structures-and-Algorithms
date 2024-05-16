/* Finding the first or last occurence of an element in a sorted array using Binary Search 
   Then find the count of that element in the array.
   Using Binary search, this is O(log n)
*/

#include <vector>
#include <iostream>
using namespace std;

int getFirstOccurence(vector<int>& nums, int x) {
    int low = 0;
    int high = nums.size()-1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high)/2;
        if (nums[mid] == x) {
            result = mid;
            high = mid-1;
        }
        else if (x < nums[mid]) high = mid-1;
        else if (x > nums[mid]) low = mid+1;
    }
    return result;
}

int getLastOccurence(vector<int>& nums, int x) {
    int low = 0;
    int high = nums.size()-1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high)/2;
        if (nums[mid] == x) {
            result = mid;
            low = mid+1;
        }
        else if (x < nums[mid]) high = mid-1;
        else if (x > nums[mid]) low = mid+1;
    }
    return result;
}

int main() {
    vector<int> nums = {1,1,1,2,2,2,2,3,3,4,5,5,5,5,6,6,6,6,6,7};
    int first = getFirstOccurence(nums, 5);
    int last = getLastOccurence(nums, 5);
    cout << "First = " << first << endl; 
    cout << "Last = " << last << endl;
    cout << "Number of occurences: " << last - first + 1 << endl; 
}