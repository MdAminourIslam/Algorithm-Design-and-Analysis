#include <bits/stdc++.h>
using namespace std;

// Structure to represent a job
struct Job {
    int id;      // Job ID
    int profit;  // Profit if job is completed
    int deadline; // Deadline of job
};

// Comparator function to sort jobs by profit in descending order
bool compare(Job a, Job b) {
    return a.profit > b.profit;
}

void jobScheduling(vector<Job>& jobs, int n) {
    // Sort jobs by descending profit
    sort(jobs.begin(), jobs.end(), compare);

//    for (int i = 0; i < n; i++) {
//        cout << jobs[i].id << " " << jobs[i].profit << " " << jobs[i].deadline << "\n";
//    }

    // Find the maximum deadline to determine the size of the schedule
    int maxDeadline = 0;
    for (auto job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Array to keep track of free time slots
    vector<int> schedule(maxDeadline + 1, -1); // -1 means slot is free
    int totalProfit = 0;
    int jobsDone = 0;

    // Assign jobs to free slots
    for (auto job : jobs) {
        for (int slot = job.deadline; slot > 0; slot--) {
            if (schedule[slot] == -1) {
                schedule[slot] = job.id;
                totalProfit += job.profit;
                jobsDone++;
                break;
            }
        }
    }

    // Output results
    cout << "Jobs selected: ";
    for (int i = 1; i <= maxDeadline; i++) {
        if (schedule[i] != -1) {
            cout << schedule[i] << " ";
        }
    }
    cout << "\nTotal Profit: " << totalProfit << endl;
}

int main() {
    int n;
    cout << "Enter the number of jobs: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "Enter job ID, profit, and deadline for each job:\n";
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].id >> jobs[i].profit >> jobs[i].deadline;
    }

    jobScheduling(jobs, n);

    return 0;
}

