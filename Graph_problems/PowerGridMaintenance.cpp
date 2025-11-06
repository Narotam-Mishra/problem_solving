
// Problem link - https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06

#include<bits/stdc++.h>
using namespace std;

// utility function to perform DFS
void dfs(int node, unordered_map<int, vector<int>>& adjList, int id, vector<int>& nodeToComponent, unordered_map<int, set<int>>& componentToOnlineNodes, vector<bool>& visited){
    // mark current node visited
    visited[node] = true;

    // assign component Id to visited node
    componentToOnlineNodes[id].insert(node);

    // add this node to the set of online nodes in this component
    nodeToComponent[node] = id;

    // recursively visit all unvisited nodes
    for(int ngbr : adjList[node]){
        if(!visited[ngbr]){
            dfs(ngbr, adjList, id, nodeToComponent, componentToOnlineNodes, visited);
        }
    }
}

vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
    unordered_map<int, vector<int>> adjList;

    // step 1 - make graph connection using adjacency list
    for(auto& edge : connections){
        int u = edge[0];
        int v = edge[1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // maps each component ID to set of online nodes in that component
    // using set to maintain sorted order (smallest ID first)
    // id -> {}
    unordered_map<int, set<int>> componentToOnlineNodes;

    // step 2 - find connected components using DFS
    vector<bool> visited(c+1, false);
    vector<int> nodeToComponent(c+1);
    for(int node=1; node<=c; node++){
        if(!visited[node]){
            int id = node;
            dfs(node, adjList, id, nodeToComponent, componentToOnlineNodes, visited);
        }
    }

    // step 3 - process each query and form result
    vector<int> res;
    for(auto& query : queries){
        int type = query[0];
        int node = query[1];

        // type-1 : maintenance check query
        if(type == 1){
            int compId = nodeToComponent[node];

            // check if station itself is online
            if(componentToOnlineNodes[compId].count(node)){
                res.push_back(node);
            }
            // find smallest online station in same component
            else if(!componentToOnlineNodes[compId].empty()){
                int smallest = *componentToOnlineNodes[compId].begin();
                res.push_back(smallest);
            }
            // no online station in this component
            else{
                res.push_back(-1);
            }
        }else{
            // type-2 query: take stattion offline
            int id = nodeToComponent[node];
            componentToOnlineNodes[id].erase(node);
        }
    }

    // step 4 - return final result ~res~
    return res;
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
    // int c = 5;
    // vector<vector<int>> connections = {{1,2},{2,3},{3,4},{4,5}};
    // vector<vector<int>> queries = {{1,3},{2,1},{1,1},{2,2},{1,2}};

    int c = 3;
    vector<vector<int>> connections = {};
    vector<vector<int>> queries = {{1,1},{2,1},{1,1}};
    vector<int> res = processQueries(c, connections, queries);
    printVector(res);
    return 0;
}