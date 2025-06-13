/* Job Sequencing with deadlines - Greedy Algorithm */

/* 
Problem Statement: You're given n jobs, where each job has:
- id: Unique identifier
- deadline: The last time slot before which it should be completed
- profit: Profit if the job is completed before or on its deadline

Each job takes 1 unit of time. Goal: Schedule the jobs to maximize total profit and number of jobs done
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Job {
    int id;
    int deadline; 
    int profit;
    Job(int i, int d, int prof) : id{i}, deadline{d}, profit{prof} {}
};

pair<int, int> jobSequencing(vector<Job>& jobs) {
    // 1. Sort jobs by profit in descending order
    sort(jobs.begin(), jobs.end(), [](Job& j1, Job& j2){
        return j2.profit < j1.profit;
    });

    // 2: Find maximum deadline
    int maxDeadline = 0;
    for (auto& j : jobs) {
        maxDeadline = max(maxDeadline, j.deadline);
    }

    // 3: Create a time slot array and initialize all to -1 (empty)
    vector<int> slot(maxDeadline + 1, -1);
    int countJobs = 0;
    int maxProfit = 0;

    // 4. Assign jobs to slots
    for (const auto& job : jobs) {
        // Find a free slot for this job (latest possible before deadline)
        // can use a free earlier slot too so keep searching left of deadline too
        for (int t = job.deadline; t > 0; t--) {
            if (slot[t] == -1) {
                slot[t] = job.id;
                countJobs++;
                maxProfit += job.profit;
                break;
            }
        }
    }
    return {countJobs, maxProfit};
}

int main() {
    vector<Job> jobs = {
        Job(1,2,20),
        Job(2,2,15),
        Job(3,1,10),
        Job(4,3,5),
        Job(5,3,1)
    };

    auto result = jobSequencing(jobs);
    cout << "Total Jobs Done: " << result.first << endl;
    cout << "Total Profit: " << result.second << endl;

    return 0;
}

