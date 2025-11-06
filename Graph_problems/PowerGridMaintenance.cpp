
// Problem link - https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06

#include<bits/stdc++.h>
using namespace std;

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> adjList;

    // step 1 - make graph connection using adjacency list
    for(auto& edge : connections){
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // step 2 - pre-processing of nodes using DFS
    vector<bool> visited(c+1, false);
    for(int node=1; node<=c; node++){
        int component_id = node;
    }
}

void printVector(vector<int>& vec){
    cout << "[";
    for (size_t i = 0; i < vec.size(); ++i) {
        cout<<vec[i];
        if (i < vec.size() - 1) {
            cout<<",";
        }
    }
    cout<< "]" <<endl;
}

int main(){
    int c = 5;
    vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};
    vector<int> res = processQueries(c, connections, queries);
    printVector(res);
    return 0;
}