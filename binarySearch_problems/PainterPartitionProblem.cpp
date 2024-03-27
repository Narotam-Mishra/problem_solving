
// Problem link - https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM

#include<bits/stdc++.h>
using namespace std;

bool isPossibleToPaintWithMidTimeLimit(vector<int> &C, int k, long long mid){
    // start with one pointer
    int totalPainters = 1;
    // Initialize current time to 0 (time taken by the current painter)
    long long currentTime = 0;

    // Loop through each board length in the array C
    for (long long len : C){
        // if adding time to paint this board exceed the mid time limit
        if (currentTime + len > mid){
            // then increment total painter as new painter is needed
            totalPainters++;
            // reset the current time
            currentTime = 0;

            // if total painters exceed the no of avaialable painter(A) then return false
            if (totalPainters > k){
                return false;
            }
        }
        // Add the time taken to paint this board by the current painter
        currentTime += len;
    }

    // If all boards can be painted within the given 'mid' time limit, return true
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    // Minimum time (when one painter paints all boards)
    long long maxSum = *max_element(boards.begin(), boards.end());
    // Maximum time (when each board is painted by a separate painter)
    long long totalSum = accumulate(boards.begin(), boards.end(), 0);

    long long low = maxSum, high = totalSum;
    int ans = -1;

    while (low <= high){
        long long mid = low + (high - low) / 2;
        if (isPossibleToPaintWithMidTimeLimit(boards, k, mid)){
            // find first probable answer as mid
            ans = mid ;
            // since we have to find minimum time required to paint all boards
            // hence discard right half of array
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 1, 5, 6, 2, 3};
    int k = 2;
    int ans = findLargestMinDistance(arr, k);
    cout<<ans<<endl;
}