
// Problem link - https://leetcode.com/problems/course-schedule/description/

#include<bits/stdc++.h>
using namespace std;

// we will topological sort using BFS traversal
bool topologicalSort(vector<vector<int>>& graph, int n, vector<int>& indegreeArr){
    // using queue to perform BFS traversal
    queue<int> q;

    // visited set to keep track of visited nodes/vertices
    unordered_set<int> visited;

    // traverse the graph
    for(int i=0; i<n; i++){
        if(indegreeArr[i] == 0){
            // add all those nodes as start whose indegree is 0
            q.push(i);
            visited.insert(i);
        }
    }

    // counter 'count' to keep track of number visited nodes/vertices
    int count = 0;

    // traverse the queue till it is empty
    while(!q.empty()){
        int curr = q.front();
        q.pop();
        count++;

        // traverse all the neighbours of the current node
        for(const int& neighbour : graph[curr]){
            if(visited.find(neighbour) == visited.end()){
                // neighbour is not visited already
                indegreeArr[neighbour]--;
                // decrement the indegree count

                // if all the indegree (dependency) is 0 then
                if(indegreeArr[neighbour] == 0){
                    // add it into the queue
                    q.push(neighbour);
                    // and mark it as visited also
                    visited.insert(neighbour);
                }
            }
        }
    }

    // return true if count is equal to the number of nodes/vertices in the graph
    return count == n;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // create graph
    vector<vector<int>> graph(numCourses);

    // indegree array for each node/vertex of the graph
    vector<int> indegreeArr(numCourses, 0);

    // read prerequisites to fill the graph
    for(const vector<int>& curr : prerequisites){
        int a = curr[0];
        int b = curr[1];

        // a is dependent on b i.e, b ------> a
        graph[b].push_back(a);

        // now there is an incoming edge on a
        indegreeArr[a]++;
    }

    return topologicalSort(graph, numCourses, indegreeArr);
}

int main(){
    int numCourses = 2;
    vector<vector<int>> prerequisites = {{1, 0}};

    // vector<vector<int>> prerequisites = {{1, 0}, {0, 1}};
    canFinish(numCourses, prerequisites) ?  cout<<"true" : cout<<"false"<<endl;
    return 0;
}