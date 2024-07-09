
// Implement Prim's algorithm to find MST

#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    int numOfVertices;
    vector<pair<int, int>>* adjList;

public:
    Graph(int n){
        this->numOfVertices = n;
        adjList = new vector<pair<int, int>>[n];
    }

    // utility method to add edges in graph
    void addEdges(int u, int v, int weight){
        adjList[u].push_back(make_pair(v, weight));
        adjList[v].push_back(make_pair(u, weight));
    }

    // utility method to use Prim's algorithm
    void findMSTUsingPrimAlgo(){
        // visited array to keep track to already visited node/vertices
        vector<bool> visited(numOfVertices, false);

        // using min-heap of vector of pair(min priority queue) to keep track of minimum weight
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // assume start node as 0
        int startNode = 0;

        // keep track of MST cost
        int totalMSTCost = 0;

        // to store the MST edges
        vector<pair<int, int>> mst;

        // mark the start node as visited and push its edges into the priority queue
        visited[startNode] = true;
        for(auto edge : adjList[startNode]){
            // (weight, vertex)
            pq.push(make_pair(edge.second, edge.first));
        }

        // traverse min-heap to calculate minimum cost of MST
        while(!pq.empty()){
            pair<int, int> minEdge = pq.top();
            pq.pop();

            // get weight and vertex
            int weight = minEdge.first;
            int v = minEdge.second;

            // check if the destination node is already visited, skip
            if(visited[v]) continue;

            // mark the destination node as visited and add the edge to the MST
            visited[v] = true;

            // add this node/vertex into mst list
            mst.push_back(minEdge);

            // calculate MST's cost
            totalMSTCost += weight;

            // push all edges from the newly visited node to the heap
            for(auto edge : adjList[v]){
                if(!visited[edge.first]){
                    pq.push(make_pair(edge.second, edge.first));
                }
            }
        }

        // output the total cost of the MST
        cout << "Total cost of MST: " << totalMSTCost << endl;
        cout << "Edges in the MST:" << endl;
        for (auto edge : mst) {
            cout << edge.second << " with weight " << edge.first << endl;
        }
    }
};

int main(){
    Graph g(5);
    g.addEdges(0, 1, 2);
    g.addEdges(0, 3, 6);
    g.addEdges(1, 2, 3);
    g.addEdges(1, 3, 8);
    g.addEdges(1, 4, 5);
    g.addEdges(2, 4, 7);
    g.addEdges(3, 4, 9);

    g.findMSTUsingPrimAlgo();

    return 0;
}