
// Problem link - https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/description/?envType=daily-question&envId=2026-07-04

#include<bits/stdc++.h>
using namespace std;

int minScore(int n, vector<vector<int>>& roads) {
    // step 1 - build graph of adjacency list
    // (neighbour, weight)
    vector<vector<pair<int, int>>> adj(n+1);
    for(auto& r : roads){
        int u = r[0], v = r[1], w = r[2];
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    // keep track of visited nodes
    vector<bool> visited (n+1, false);

    // use queue to perform BFS traversal
    queue<int> q;

    // step 2 - start BFS from city 1
    q.push(1);
    visited[1] = true;

    // keep track of final answer, `ans`
    int ans = INT_MAX;

    // process queue
    while(!q.empty()){
        int u = q.front();
        q.pop();

        // step 3 - explore all neighbours
        for(auto& [v, w] : adj[u]){
            // update minimum score
            ans = min(ans, w);

            if(!visited[v]){
                visited[v] = true;
                q.push(v);
            }
        }
    }

    // step 4 - return final answer, `ans`
    return ans;
}

int main(){
    // int n = 4;
    // vector<vector<int>>roads = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};

    int n = 4;
    vector<vector<int>>roads = {{1,2,2},{1,3,4},{3,4,7}};
    cout<<minScore(n, roads);
    return 0;
}