
// Problem link - https://leetcode.com/problems/sum-of-subarray-minimums/

#include<bits/stdc++.h>
using namespace std;

int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    // two vector arrays to maintain left and right sub-arrays count where arr[i] is minimum
    vector<int> leftSubArrCnt(n), rightSubArrCnt(n);
    // two stacks of pairs to maintain the elements along with their sub-array counts
    stack<pair<int, int>> st1, st2;

    // find left sub-arrays count where arr[i] is minimum
    for(int i=0; i<n; i++){
        // intial sub-array count will be 1 because there will be atleast one sub-array where arr[i] will be minimum
        int cnt = 1;
        // calculate sub-arrays count from stack until element greater than arr[i]
        while (!st1.empty() && st1.top().first > arr[i]){
            cnt += st1.top().second;
            st1.pop();
        }
        st1.push({arr[i], cnt});
        leftSubArrCnt[i] = cnt;
    }

    // find right sub-arrays count where arr[i] is minimum
    for(int i=n-1; i>=0; i--){
        int cnt = 1;
        // calculate sub-arrays count from stack until element greater than arr[i]
        while (!st2.empty() && st2.top().first >= arr[i]){
            cnt += st2.top().second;
            st2.pop();
        }
        st2.push({arr[i], cnt});
        rightSubArrCnt[i] = cnt;
    }

    // calculate the required sub-arrays sum using formula --> arr[i] * leftSubArrCnt[i] * rightSubArrCnt[i] 
    long long ans = 0;
    int modNum = 1000000007;
    for(int i=0; i<n; i++){
        ans = (ans + (static_cast<long long int>(arr[i]) * leftSubArrCnt[i] * rightSubArrCnt[i]) % modNum) % modNum;
    }
    // return answer
    return static_cast<int>(ans);
}

int main(){
    // vector<int> arr = {3,1,2,4};

    vector<int> arr = {11,81,94,43,3};
    cout<<sumSubarrayMins(arr)<<endl;
}