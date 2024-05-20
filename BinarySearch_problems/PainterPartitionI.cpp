
// Problem Link - https://www.interviewbit.com/problems/painters-partition-problem/

#include<bits/stdc++.h>
using namespace std;

bool isPossibleToPaintWithMidTimeLimit(int A, int B, vector<int> &C, long long mid){
    // start with one pointer
    int totalPainters = 1;
    // Initialize current time to 0 (time taken by the current painter)
    long long currentTime = 0;

    // Loop through each board length in the array C
    for (long long len : C){
        // if adding time to paint this board exceed the mid time limit
        if (currentTime + (len * B) > mid){
            // then increment total painter as new painter is needed
            totalPainters++;
            // reset the current time
            currentTime = 0;

            // if total painters exceed the no of avaialable painter(A) then return false
            if (totalPainters > A){
                return false;
            }
        }
        // Add the time taken to paint this board by the current painter
        currentTime += len * B;
    }

    // If all boards can be painted within the given 'mid' time limit, return true
    return true;
}

int paint(int A, int B, vector<int> &C) {
    // Minimum time (when one painter paints all boards)
    long long maxSum = *max_element(C.begin(), C.end());
    // Maximum time (when each board is painted by a separate painter)
    long long totalSum = accumulate(C.begin(), C.end(), 0);

    long long low = maxSum * B, high = totalSum * B;
    long long ans = -1;

    while (low <= high){
        long long mid = low + (high - low) / 2;
        if (isPossibleToPaintWithMidTimeLimit(A, B, C, mid)){
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
    return ans % 10000003;
}


int main(){
    // int A = 2;
    // int B = 5;
    // vector<int> C = {1,10};

    int A = 1;
    int B = 1000000;
    vector<int> C = {1000000, 1000000};
    int ans = paint(A, B, C);
    cout<<ans<<endl;
    return 0;
}