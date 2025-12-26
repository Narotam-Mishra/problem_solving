
// Problem link - https://leetcode.com/problems/minimum-penalty-for-a-shop/?envType=daily-question&envId=2025-12-26

#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Brute Force Approach
int bestClosingTime1(string customers) {
    int n = customers.size();

    // keep tack of minimum penalty and earliest hour
    int minPenalty = INT_MAX;
    int minHour = INT_MAX;

    // step 1 - iterate on each ith hour
    for(int i=0; i<n; i++){
        // step 2 - calculate minimum penalty for 2 cases
        // case 1 - when shop is open
        int j = i-1;
        int currPenalty = 0;
        while(j >= 0){
            if(customers[j] == 'N'){
                currPenalty++;
            }
            j--;
        }

        // case 2 - when shop is closed
        j = i;
        while(j<n){
            if(customers[j] == 'Y'){
                currPenalty++;
            }
            j++;
        }

        // update minimum penalty
        if(currPenalty < minPenalty){
            minPenalty = currPenalty;
            minHour = i;
        }
    }

    // step 3 - closing shop the nth hour
    // from o to n-1 shop -> open 
    int nthHourPenalty = count(begin(customers), end(customers), 'N');
    if(nthHourPenalty < minPenalty){
        minHour = n;
    }

    // step 4 - return the earliest hour where penalty is minimum
    return minHour;
}

// Approach 2 - Optimal Approach
int bestClosingTime2(string customers) {
    int n = customers.size();

    // keep track of penalty when shop is opened
    vector<int> prefixN(n+1, 0);
    prefixN[0] = 0;

    // keep track of penalty when shop is closed
    vector<int> suffixY(n+1, 0);
    suffixY[n] = 0;

    // step 1 - fill prefix when shop is opened
    for(int i=1; i<=n; i++){
        if(customers[i-1] == 'N'){
            prefixN[i] = prefixN[i-1] + 1;
        }else{
            prefixN[i] = prefixN[i-1];
        }
    }

    // step 2 - fill suffix when shop is closed
    for(int i=n-1; i>=0; i--){
        if(customers[i] == 'Y'){
            suffixY[i] = suffixY[i+1] + 1;
        }else{
            suffixY[i] = suffixY[i+1];
        }
    }

    // step 3 - calculate minimum penalty in earliest hour
    int minPenalty = INT_MAX;
    int minHour = INT_MAX;
    for(int i=0; i<=n; i++){
        int currPenalty = prefixN[i] + suffixY[i];
        if(currPenalty < minPenalty){
            minPenalty = currPenalty;
            minHour = i;
        }
    }

    // step 4 - return earliest hour
    return minHour;
}

// Approach 3 -  Most Optimal Approach
int bestClosingTime(string customers) {
    int n = customers.size();

    // initially all shops will be closed,
    // so current penalty will be count of `Y`
    int currPenalty = count(begin(customers), end(customers), 'Y');

    // keep track of minimum penalty and earlier hour
    int minPenalty = currPenalty;
    int minHour = 0;

    // step 1 - iterate on i-th hour 
    for(int i=0; i<n; i++){
        // step 2 - calculate penalty for each hour
        if(customers[i] == 'Y'){
            currPenalty--;
        }else{
            currPenalty++;
        }

        // step 3 - update minimum penalty
        if(currPenalty < minPenalty){
            minPenalty = currPenalty;
            
            // update earlier-hour
            minHour = i+1;
        }
    }

    // step 4 - return the earliest hour at which the shop must be closed
    return minHour;
}

int main(){
    // string customers = "YYNY";

    // string customers = "NNNNN";

    string customers = "YYYY";
    cout<<bestClosingTime(customers);
    return 0;
}