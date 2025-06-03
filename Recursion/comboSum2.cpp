/* Combination Sum II */

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    vector<vector<int>> combos; 
    vector<int> res;
    
    void backtrack(vector<int>& candidates, int target, int& sum, int index) {
        // if res sum is equal to target, then save it
        if (sum == target) {
            combos.push_back(res);
            return;
        }
        
        for (int i=index; i<candidates.size(); i++) {
            // skip taking this index since it is a duplicate
            // i = starting index
            // so if i is the starting index, make sure next starting index that is the same
            // is not picked
            if (i > index && candidates[i] == candidates[i-1]) continue; 

            /* if the sum becomes higher than target when adding the current value,
            skip it and don't consider the next elements since they are definitely
            higher in value in candidates[] */
            if (sum + candidates[i] > target) break;


            // Take the current value from candidates[]
            sum += candidates[i];
            res.push_back(candidates[i]);

            // Pick a value from the next index
            backtrack(candidates, target, sum, i+1);

            // Done checking the next indices in candidates[], 
            // so remove this current one and check all of the combos
            // with the next indices again 
            sum -= candidates[i];
            res.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // sort so that all dups are next to each other
        sort(candidates.begin(), candidates.end());
        int sum = 0;
        backtrack(candidates, target, sum, 0);
        return combos;
    }

};


int main() {
    Solution sol;
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    for (const auto& combo : result) {
        for (int num : combo) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
