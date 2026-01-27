
// Problem link - https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
int minCost(int n, vector<vector<int>>& edges) {
    // step 1 - make adjacency list for graph
    unordered_map<int, vector<P>> adjList;

    // step 2 - traverse on each edge
    for (auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        // step 3 - make connection
        adjList[u].push_back({ v,wt });
        adjList[v].push_back({ u,wt * 2 });
    }

    // max-heap for Dijkstra's Algorithm
    priority_queue<P, vector<P>, greater<P>> pq;

    // store distance of all other nodes from source
    vector<int> res(n, INT_MAX);
    res[0] = 0;
    pq.push({ 0, 0 });

    // step 4 - explore all neighbour
    while (!pq.empty()) {
        int d = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if (node == n - 1) {
            return res[n - 1];
        }

        // step 5 - visit neighbouring nodes
        for (auto& p : adjList[node]) {
            int adjNode = p.first;
            int dist = p.second;

            // step 6 - find minimum cost
            if (d + dist < res[adjNode]) {
                res[adjNode] = d + dist;
                pq.push({ d + dist, adjNode });
            }
        }
    }

    // step 7 - return
    return -1;
}

int main(){
    // int n = 4;
    // vector<vector<int>> edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};

    int n = 4;
    vector<vector<int>> edges = {{0,2,1},{2,1,1},{1,3,1},{2,3,3}};
    cout<<minCost(n, edges);
    return 0;
}
