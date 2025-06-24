/* Leetcode 703. Kth Largest Element in a Stream */

#include <vector>
#include <queue>
using namespace std;

class KthLargest {
    // By default, priority queues are max-heaps
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int K;
    
public:
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for (int n : nums) {
            add(n);
        }
    }
    
    int add(int val) {
        if (minHeap.size() < K) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            // size of minHeap has crossed K elements
            // so, remove smallest element from min-heap
            // because we always only delete the root of the min heap
            minHeap.pop();
            // add the new element 
            minHeap.push(val);
        }

        return minHeap.top();
    }
};