
// Problem link - https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2025-09-01

#include<bits/stdc++.h>
using namespace std;

// Using Brute Force Approach 
double maxAverageRatio1(vector<vector<int>>& classes, int extraStudents) {
    int n = classes.size();

    // step 1 - calculate initial pass ratios for all classes
    vector<double> pr(n);
    for (int i = 0; i < n; i++) {
        double ratio = (double)classes[i][0] / classes[i][1];
        pr[i] = ratio;
    }

    // step 2 - assign each extra student one by one
    while (extraStudents--) {
        
          // step 3 - calculate what the new ratio would be for each class if we add 1 student
        vector<double> updatedPr(n);
        for (int i = 0; i < n; i++) {
            double newRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
            updatedPr[i] = newRatio;
        }

        int bestClassIdx = 0;
        double bestDelta = 0.0;

        for (int i = 0; i < n; i++) {
            // step 4 - calculate improvement: new_ratio - current_ratio
            double delta = updatedPr[i] - pr[i];
            
            // step 5 - keep track of class with maximum improvement
            if (delta > bestDelta) {
                bestDelta = delta;
                bestClassIdx = i;
            }
        }

        // step 6 - update the best class: add 1 student (both pass and total increase)
        pr[bestClassIdx] = updatedPr[bestClassIdx];
        classes[bestClassIdx][0]++;
        classes[bestClassIdx][1]++;
    }

    // step 7 - calculate final average pass ratio
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += pr[i];
    }

    // step 8 - return average = sum_of_ratios / number_of_classes
    return res / n;
}

double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
    // find size of class
    int n = classes.size();

    // step 1 - create a max-heap (priority queue) to store gain and class index
    // In Cpp, priority_queue is max-heap by default, so highest gain will be at top
    priority_queue<pair<double, int>> pq;

    // step 2 - calculate initial gain for each class and add to priority queue
    for (int i = 0; i < n; i++) {
        // calculate current pass ratio for class i
        double curr_pr = (double)classes[i][0] / classes[i][1];
        
        // calculate what the pass ratio would be if we add 1 extra student
        double newPr = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        
        // calculate the improvement (delta/gain) we get by adding 1 student
        double gain = newPr - curr_pr;
        
        // add to max-heap: {gain, class_index}
        pq.push({gain, i});
    }

    // step 3 - greedily assign each extra student to the class with maximum gain
    while (extraStudents--) {
        // get the class that currently offers maximum gain
        auto curr = pq.top();
        pq.pop();

        // gain value (not used after popping)
        double gain = curr.first;
        int idx = curr.second;

        // step 4 - add one extra student to the selected class
        // increment passing students
        classes[idx][0]++;
        // increment total students
        classes[idx][1]++;

        // step 6 - recalculate the gain for this class after adding the student
        double curr_pr = (double)classes[idx][0] / classes[idx][1];
        double newPr = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
        
        // calculate updated gain for this class
        gain = newPr - curr_pr;
        
        // step 7 - put the class back into priority queue with its new gain
        pq.push({gain, idx});
    }

    // step 8 - calculate the final average pass ratio across all classes
    double res = 0.0;
    for (int i = 0; i < n; i++) {
        res += (double)classes[i][0] / classes[i][1];
    }

    // step 9 - return average = total_sum_of_ratios / number_of_classes
    return res / n;
}

int main(){
    vector<vector<int>> classes = {{1,2},{3,5},{2,2}};
    int extraStudents = 2;

    // vector<vector<int>> classes = {{2,4},{3,9},{4,5},{2,10}};
    // int extraStudents = 4;
    cout<<maxAverageRatio(classes, extraStudents);
    return 0;
}