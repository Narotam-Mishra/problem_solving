
// Problem link - https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

#include<bits/stdc++.h>
using namespace std;

// Optimal Approach
double mincostToHireWorkers(vector<int>& quality, vector<int>& minWage, int k) {
    int n = quality.size();
    double minCost = DBL_MAX;

    // create a vector to store the ratio of wage to quality for each worker
    vector<pair<double, int>> workerRatio(n);

    // calculate the workerRatio vector with (ratio, quality) pairs
    for(int worker = 0; worker < n; worker++){
        workerRatio[worker] = { (double) minWage[worker] / quality[worker], quality[worker]};
    }

    // sort the workers by their wage-to-quality ratio in ascending order
    sort(workerRatio.begin(), workerRatio.end());

    // Use a max-heap to keep track of the k smallest quality values
    priority_queue<int> pq;

    // add the first k workers to the heap and calculate the initial quality sum
    int qualitySum = 0;
    for(int i=0; i<k; i++){
        pq.push(workerRatio[i].second);
        qualitySum += workerRatio[i].second;
    }

    // get the ratio of the k-th worker (the manager)
    double managerRatio = workerRatio[k-1].first;
    
    // calculate the initial minimum cost using the k-th worker's ratio and the quality sum
    minCost = managerRatio * qualitySum;

    // iterate through the remaining workers
    for(int manager = k; manager < n; manager++){
        // update the manager ratio to the current worker's ratio
        managerRatio = workerRatio[manager].first;

        // add the current worker's quality to the heap and update the quality sum
        pq.push(workerRatio[manager].second);
        qualitySum += workerRatio[manager].second;

        // if the heap size exceeds k,
        if(pq.size() > k){
            // remove the largest quality value to maintain the smallest k qualities
            qualitySum -= pq.top();
            pq.pop();
        }

        // calculate the new minimum cost and update minCost if the new cost is lower
        minCost = min(minCost, managerRatio * qualitySum);
    }

    // return the minimum wage cost to hire k workers
    return minCost;
}

// Brute Force Approach (will give TLE on submission)
double mincostToHireWorkers1(vector<int>& quality, vector<int>& minWage, int k) {
    int n = quality.size();

    // Initialize the minimum cost to the largest possible number
    double minCost = numeric_limits<double>::max();

    // iterate over each worker to consider them as the manager
    for(int manager = 0; manager < n; manager++){
        // calculate the ratio of minWage to quality for the manager
        double managerRatio = (double)minWage[manager] / quality[manager];

        // vector to store actual (valid) wages for each worker
        vector<double> validWages;

        // check each worker's wage when hired by this manager
        for(int worker = 0; worker < n; worker++){
            double workerWage = managerRatio * quality[worker];

            if(workerWage >= minWage[worker]){
                // if the calculated worker's wage is greater than or equal to the worker's minimum wage
                // that will be only valid
                validWages.push_back(workerWage);
            }
        }

        if(validWages.size() < k){
            // if we don't have enough valid workers, 
            // continue to the next manager
            continue;
        }

        // sort the valid wages in ascending order
        // as we need to find the least amount of wage
        sort(validWages.begin(), validWages.end());
        
        // Sum the smallest k wages
        double totalWage = 0;
        for(int i=0; i<k; i++){
            totalWage += validWages[i];
        }

        // update the minimum cost if we found a cheaper combination
        minCost = min(minCost, totalWage);
    }
    // return minimum cost wage 'minCost'
    return minCost;
}

int main(){
    vector<int> quality = {10, 20, 5};
    vector<int> minWage = {70, 50, 30};
    int k = 2;

    // vector<int> quality = {3, 1, 10, 10, 1};
    // vector<int> minWage = {4, 8, 2, 2, 7};
    // int k = 3;

    cout<<mincostToHireWorkers(quality, minWage, k)<<endl;
    return 0;
}