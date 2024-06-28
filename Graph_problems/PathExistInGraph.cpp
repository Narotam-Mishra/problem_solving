
// Problem link - https://leetcode.com/problems/find-if-path-exists-in-graph/description/

#include<bits/stdc++.h>
using namespace std;

// utility function to perfrom DFS graph traversal iteratively
bool bfs(int src, int dest, vector<vector<int>>& g, unordered_set<int>& visited){
    // base case 1: if src is dest
    if(src == dest) return true;

    // using queue to perform BFS
    queue<int> q;

    // add the source node to visited set
    q.push(src);
    visited.insert(src);

    // while queue is not empty
    while(!q.empty()){
        // remove from the start of the queue
        int curVer = q.front();
        q.pop();

        // traverse each neighbour one by one
        for(int neighbour : g[curVer]){
            // base case 2: if neighbour is destination
            if(neighbour == dest) return true;

            if(visited.find(neighbour) == visited.end()){
                // if we have not already visited the neighbour, visit it
                visited.insert(neighbour);
                // add the neighbour to the queue
                q.push(neighbour);
            }
        }
    }
    return false;
}

// utility function to perfrom DFS graph traversal recursively
bool dfs(int src, int dest, vector<vector<int>>& g, unordered_set<int>& visited){
    // base case: if src is dest only
    if(src == dest) return true;

    // add the source, 'src' node to visted set as we have visited it 
    // and now we will go to nearest neighbour
    visited.insert(src);

    // traverse each neighbour one by one
    bool ans = false;
    for(int neighbour : g[src]){
        if(visited.find(neighbour) == visited.end()){
            // if we have not already visited the neighbour then go to that neighbour
            ans = ans || dfs(neighbour, dest, g, visited);
        }
    }

    // return answer'ans'
    return ans;
}

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    // graph creation using vector of vector
    vector<vector<int>> g(n);

    // convert edge list into adjacency list
    // and populate the graph's edges
    for (vector<int>& edge : edges){
        int u = edge[0];
        int v = edge[1];

        // bidirectional edges
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // created set to store nodes once that will be visited
    unordered_set<int> visited;

    // call to dfs method and perform graph traversal recursively
    // return dfs(source, destination, g, visited);

    // call to bfs method and perform graph traversal recursively
    return bfs(source, destination, g, visited);
}

int main(){
    // int n = 6;
    // vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    // int source = 0;
    // int destination = 5;

    int n = 3;
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int source = 0;
    int destination = 2;
    
    bool res = validPath(n, edges, source, destination);
    cout <<"Path from "<<source<<" to "<<destination<<" exists: "<<(res ? "true" : "false")<<endl;
    return 0;
}