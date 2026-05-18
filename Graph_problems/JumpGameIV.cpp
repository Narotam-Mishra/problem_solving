
// Problem link - https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18

#include<bits/stdc++.h>
using namespace std;

int minJumps(vector<int>& arr) {
    int n = arr.size();

    // edge case: already at the last index
    if(n == 1) return 0;

    // step 1 - precompute value -> list of indices map
    unordered_map<int, vector<int>> mp;
    for(int i=0; i<n; i++){
        mp[arr[i]].push_back(i);
    }

    // step 2 - using BFS Algorithm
    // kkep track of visited node
    vector<bool> visited(n, false);

    // using BFS queue to holds current index
    queue<int> q;
    q.push(0);
    visited[0] = true;

    // keep track of minimum steps
    int minSteps = 0;

    // step 3 - start performing BFS traversal
    while(!q.empty()){
        // each iteration of outer loop = 1 step/level
        minSteps++;

        // process all nodes at current level
        int levelSize = q.size();

        for(int k=0; k<levelSize; k++){
            int currNode = q.front();
            q.pop();

            // explore all neighbours
            int left = currNode - 1;
            int right = currNode + 1;

            // neighbor 1: Jump right
            if(right < n && !visited[right]){
                if(right == n-1) return minSteps;
                visited[right] = true;
                q.push(right);
            }

            // neighbor 2: Jump left
            if(left >= 0 && !visited[left]){
                if(left == n-1) return minSteps;
                visited[left] = true;
                q.push(left);
            }

            // neighbor 3: teleport to all indices with same value
            for(int &j : mp[arr[currNode]]){
                if(!visited[j]){
                    if(j == n-1) return minSteps;
                    visited[j] = true;
                    q.push(j);
                }
            }

            // clear this value group from the map
            // Once we process a group member via BFS, all others in the
            // group are already queued or visited.
            mp.erase(arr[currNode]);
        }
    }

    return -1;
}

int main(){
    // vector<int> arr = {100,-23,-23,404,100,23,23,23,3,404};

    vector<int> arr = {7};

    // vector<int> arr = {7,6,9,6,9,6,9,7};
    cout<<minJumps(arr);
    return 0;
}