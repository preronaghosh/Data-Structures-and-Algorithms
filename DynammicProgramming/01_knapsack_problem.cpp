/* Using recursion */

#include <iostream>
#include <vector>
using namespace std;

// n is 0-based indexed
int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    // if we have reached last object OR capacity over
    if (n==0 || W == 0) return 0;

    // do not check <= 0 because going to 0 is fine here
    // it just means that including this object will make it the last one being added to the sack
    if (W - wt[n-1] < 0) { 
        // prevent recursive calls for when capacity has been exhausted
        return knapsack(n-1, W, wt, val);
    }

    // include this object and later add the profit of taking this one
    int include = knapsack(n-1, W - wt[n-1], wt, val) + val[n-1];
    // exclude this object
    int exclude = knapsack(n-1, W, wt, val);

    return max(include, exclude);    
}

int main() {
    vector<int> weights = {1,2,1,2};
    vector<int> values = {6,5,3,8};
    int W = 5;
    int n = weights.size();

    int maxValue = knapsack(n, W, weights, values);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}
