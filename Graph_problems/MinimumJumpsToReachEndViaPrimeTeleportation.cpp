
// Problem link - https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/?envType=daily-question&envId=2026-05-08

#include<bits/stdc++.h>
using namespace std;

// keep track of prime number
vector<bool> isPrime;

// utility function to build prime sieve
void buildPrimeSieve(int maxNum){
    // fill prime numbers
    isPrime.resize(maxNum+1, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for(int num=2; num*num <= maxNum; num++){
        if(isPrime[num]){
            for(int mul = num*num; mul <= maxNum; mul += num){
                isPrime[mul] = false;
            }
        }
    }
}

int minJumps(vector<int>& nums) {
    int n = nums.size();

    // map to track number and their indices occurence
    unordered_map<int, vector<int>> mp;

    // step 1 - find occurence and max element in nums
    int maxNum = 0;
    for(int i=0; i<n; i++){
        mp[nums[i]].push_back(i);
        maxNum = max(maxNum, nums[i]);
    }

    // step 2 - build prime sieve
    buildPrimeSieve(maxNum);

    // keep track of visited node
    vector<bool> visited(n, false);

    // step 3 - apply BFS traversal
    queue<int> q;
    q.push(0);
    visited[0] = true;

    // keep track of already visited prime numbers
    unordered_set<int> seen;

    int steps = 0;
    while (!q.empty()){
        int qSize = q.size();

        while(qSize--){
            int i = q.front();
            q.pop();

            // early exit
            if(i == n-1){
                // check if we have reached destination
                return steps;
            }

            // visit left and right neighbours
            if(i-1 >= 0 && !visited[i-1]){
                q.push(i-1);
                visited[i-1] = true;
            }

            if(i+1 >= 0 && !visited[i+1]){
                q.push(i+1);
                visited[i+1] = true;
            }

            // skip non prime and already visited prime
            if(!isPrime[nums[i]] || seen.count(nums[i])){
                continue;
            }

            // step 4 - find multiples of prime for teleportation
            for(int mul=nums[i]; mul<=maxNum; mul += nums[i]){
                if(!mp.count(mul)){
                    continue;
                }

                for(int &j : mp[mul]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j] = true;
                    }
                }
            }

            seen.insert(nums[i]);
        }

        // increment minimum jump
        steps++;
    }

    // step 5 - return minimum jumps
    return steps;
}

int main(){
    // vector<int> nums = {1,2,4,6};

    // vector<int> nums = {2,3,4,7,9};

    vector<int> nums = {4,6,5,8};
    cout<<minJumps(nums);
    return 0;
}