
// Problem link - https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2025-11-28

#include<bits/stdc++.h>
using namespace std;

// track count of each component that satisfy the condition
int c = 0;

// utility function to perfrom DFS traversal
int dfsHelper(int currNode, int parent, unordered_map<int, vector<int>>& adj, vector<int>& values, int k){
    int sum = values[currNode];

    for(int &ngbr : adj[currNode]){
        if(ngbr != parent){
            sum += dfsHelper(ngbr, currNode, adj, values, k);
            sum = sum % k;
        }
    }

    sum = sum % k;

    if(sum == 0){
        c++;
    }

    return sum;
}

int maxKDivisibleComponents1(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    // step 1 - make adjacency list to establish graph connection 
    // using map for adjacency list
    unordered_map<int, vector<int>> adj;
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // step 2 - starting graph traversal using DFS(0, values, k)
    dfsHelper(0, -1, adj, values, k);

    // step 3 - return count of each component
    return c;
}

int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    // step 1 - make adjacency list to establish graph connection 
    // using map for adjacency list
    unordered_map<int, vector<int>> adj;
    for(auto &edge : edges){
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // keep track of component count
    int componentCount = 0;

    // utility lambda function to perform DFS traversal
    function<int(int, int)> dfs = [&](int currNode, int parent) -> int {
        // start with current node value
        int sum = values[currNode];

        // step 2 - traverse all neighbours
        for(int ngbr : adj[currNode]){
            // skip parent node to avoid loop
            if(ngbr != parent){
                // recursively get sum from children subtree
                int childSum = dfs(ngbr, currNode);
                sum += childSum;
                sum = sum % k;
            }
        }

        // take final modulo
        sum = sum % k;

        // step 3 - check if subtree sum is divisible by k, we found a valid component
        if(sum == 0){
            // increment component count
            componentCount++;
        }

        return sum;
    };

    // step 4 - starting graph traversal using DFS(0, values, k)
    dfs(0, -1);

    // step 5 - return count of each component
    return componentCount;
}

int main(){
    int n = 5;
    vector<vector<int>> edges = {{0,2},{1,2},{1,3},{2,4}};
    vector<int> values = {1,8,1,4,4};
    int k = 6;

    // int n = 7;
    // vector<vector<int>> edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
    // vector<int> values = {3,0,6,1,5,2,1};
    // int k = 3;
    cout<<maxKDivisibleComponents(n, edges, values, k);
}