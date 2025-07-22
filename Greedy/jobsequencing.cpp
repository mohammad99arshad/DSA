#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparison function to sort jobs by profit in descending order
bool static camparison(Job a, Job b) {
    return (a.profit > b.profit);  // Sort jobs by profit in descending order
}

// Function to schedule jobs and calculate maximum profit and number of jobs completed
pair<int, int> jobScheduling(Job arr[], int n) {
    // Sort jobs by profit in descending order
    sort(arr, arr + n, camparison);
    
    // Find the maximum deadline
    int maxi = arr[0].deadline;
    for (int i = 1; i < n; i++) {  // Corrected loop
        maxi = max(maxi, arr[i].deadline);
    }

    // Initialize the slots to keep track of which time slots are used
    int slot[maxi + 1];
    for (int i = 0; i <= maxi; i++) {
        slot[i] = -1;  // -1 indicates the slot is empty
    }

    int countJob = 0, jobProfit = 0;

    // Iterate over the jobs and schedule them
    for (int i = 0; i < n; i++) {
        // Try to find a slot for the job (starting from its deadline)
        for (int j = arr[i].deadline; j > 0; j--) {
            if (slot[j] == -1) {  // If slot is empty, schedule the job
                slot[j] = i;
                countJob++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }

    return make_pair(countJob, jobProfit);  // Return number of jobs scheduled and total profit
}

int main() {
    int n = 4;
    Job arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};
    
    // Get the result of job scheduling
    pair<int, int> ans = jobScheduling(arr, n);

    // Output the result: number of jobs done and total profit
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
