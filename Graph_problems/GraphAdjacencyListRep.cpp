
// Graph representation using Adjacency List (using Linked List)

#include<bits/stdc++.h>
using namespace std;

class Graph {
    int v;  // number of vertices
    vector<list<int>> adjList; // adjacency list

public:
    // constructor
    Graph(int numOfVertices){
        this->v = numOfVertices;
        adjList.resize(numOfVertices);
    }

    // method to add an edge into the graph
    void addEdge(int v1, int v2, bool biDir){
        adjList[v1].push_back(v2);

        if(biDir){
            // graph is bidirectional
            adjList[v2].push_back(v1);
        }
    }

    // method to display the graph
    void displayGraph(){
        for(int i=0; i<adjList.size(); i++){
            cout<<"Vertex "<<i<<": ";
            for(auto vertex : adjList[i]){
                cout<<vertex<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1, true);
    g.addEdge(0, 6, true);
    g.addEdge(6, 5, true);
    g.addEdge(1, 5, true);
    g.addEdge(1, 2, true);
    g.addEdge(2, 4, true);
    g.addEdge(2, 3, true);
    g.addEdge(4, 3, true);

    g.displayGraph();
}