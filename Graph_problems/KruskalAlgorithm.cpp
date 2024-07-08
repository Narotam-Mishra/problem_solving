
// Implement Kruskal's algorithm to find MST

#include<bits/stdc++.h>
using namespace std;

// DSU utility method for find operation with path compression
int find(int x, vector<int>& parent) {
    if (parent[x] != x) {
        parent[x] = find(parent[x], parent);  // path compression
    }
    return parent[x];
}

// DSU utility method for union operation with union by size
void unionSets(int x, int y, vector<int>& parent, vector<int>& size) {
    int xRoot = find(x, parent);
    int yRoot = find(y, parent);

    if (xRoot == yRoot) return;
    // x and y are always in same set

    if (size[xRoot] < size[yRoot]) {
        // x is smaller than y
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    } else {
        // y is smaller than x
        parent[yRoot] = xRoot;
        size[xRoot] += size[yRoot];
    }
}

// Kruskal's algorithm to find the minimum spanning tree
int kruskalAlgoToFindMST(vector<vector<int>>& edgeList, int numOfVertices){
    // Sort edges by weight
    sort(edgeList.begin(), edgeList.end(), [](const vector<int>& e1, const vector<int>& e2) {
        return e1[2] < e2[2];
    });

    // to track minimum spanning tree sum
    int spanningTreeSum = 0;

    // to track parent element while perfroming DSU operation
    vector<int> parent(numOfVertices);

    // size vector to keep track of size of grouping
    vector<int> size(numOfVertices, 1);

    // Initialize parent and size arrays
    for (int i = 0; i < numOfVertices; i++) {
        parent[i] = i;
    }

    // traverse each edge from edgeList
    for(const auto& edge : edgeList){
        // get edges and its correponding weights
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];

        // find operation to check if both edges belong to same set or not
        if(find(u, parent) != find(v, parent)){
            // if u and v are not in same set or same component
            // it means adding this edge will not form a cycle
            unionSets(u, v, parent, size);

            // picking the edge and add its weight to spanning tree sum
            spanningTreeSum += weight;
        }        
    }
    // return minimum cost to traverse spanning tree
    return spanningTreeSum;
}

int main() {
    vector<vector<int>> edgeList = {
       {0, 1, 10},
       {0, 2, 6},
       {0, 3, 5},
       {1, 3, 15},
       {2, 3, 4},
    };

    int numOfVertices = 4;
    cout << kruskalAlgoToFindMST(edgeList, numOfVertices) << endl;

    return 0;
}