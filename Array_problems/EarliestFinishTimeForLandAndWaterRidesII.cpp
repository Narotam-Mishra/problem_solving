
// Problem link - https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/description/?envType=daily-question&envId=2026-06-03

#include<bits/stdc++.h>
using namespace std;

// helper function to compute the earliest time to finish one ride from the first category
int findFinishTime(vector<int> startTime1, vector<int> duration1, vector<int> startTime2, vector<int> duration2){

    // step 1 - choose the ride from the first category that finishes earliest.
    // each ride i can start no earlier than startTime1[i] and finishes at
    // startTime1[i] + duration1[i] if taken immediately.
    int finish1 = INT_MAX;
    for(int i=0; i<startTime1.size(); i++){
        finish1 = min(finish1, startTime1[i] + duration1[i]);
    }

    // step 2 - after finishing the first ride at finish1, choose the second ride
    // that can start no earlier than max(finish1, startTime2[i]) and finishes at
    // that start time plus duration2[i].
    int finish2 = INT_MAX;
    for(int i=0; i<startTime2.size(); i++){
        finish2 = min(finish2, max(finish1, startTime2[i]) + duration2[i]);
    }

    // return final finish time, `finish2`
    return finish2;
}

int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
    // step 1 - evaluate both possible orders: land first then water, or water first then land.
    int res1 = findFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    int res2 = findFinishTime(waterStartTime, waterDuration, landStartTime, landDuration);

    // step 2 - return the earliest overall finish time.
    return min(res1, res2);
}

int main(){
    // vector<int> landStartTime = {2,8}, landDuration = {4,1};
    // vector<int> waterStartTime = {6}, waterDuration = {3};

    vector<int> landStartTime = {5}, landDuration = {3};
    vector<int> waterStartTime = {1}, waterDuration = {10};
    cout<<earliestFinishTime(landStartTime, landDuration, waterStartTime, waterDuration);
    return 0;
}