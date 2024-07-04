
// Implement Shortest Path Dijkstra's Algorithm

#include<bits/stdc++.h>
using namespace std;

class CustomGenericHeap {
    vector<pair<int, int>> heap;

    // Member function for comparison
    bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

public:
    void insert(pair<int, int> data) {
        heap.push_back(data);
        push_heap(heap.begin(), heap.end(), [this](pair<int, int> a, pair<int, int> b) { return cmp(a, b); });
    }

    void remove() {
        pop_heap(heap.begin(), heap.end(), [this](pair<int, int> a, pair<int, int> b) { return cmp(a, b); });
        heap.pop_back();
    }

    pair<int, int> peek() {
        return heap.front();
    }

    int size() {
        return heap.size();
    }
};

pair<vector<int>, vector<int>> findShortestPathUsingDijkstra(int n, vector<vector<pair<int, int>>> &graph, int src){
    // using min-priority queue
    CustomGenericHeap pq;

    // to track already visited nodes, we will use visited set
    unordered_set<int> visited;

    // to track via path mapping 
    vector<int> via(n, -1);
    
    // to track distance (weight cost) for each node/vertex
    vector<int> distances(n, INT_MAX);

    // initially via path for src node is -1 and distance (weight cost) is 0
    distances[src] = 0;

    // we will insert pair of node and distance inside the min-priority queue
    pq.insert({src, 0});

    // traverse priority queue
    while(pq.size() > 0){
        // get the topmost root node
        auto [node, distance] = pq.peek();
        pq.remove();

        // if we have already visited this node then ignore it because it is stale entry
        if(visited.find(node) != visited.end()) continue;

        // mark the node as visited
        visited.insert(node);

        // traverse all the neighbors of current node
        // get neighbour's node and distance
        for(auto &[neighbourNode, neighbourDistance] : graph[node]){
            // if neighbour node is already visited then we skip it
            if(visited.find(neighbourNode) != visited.end()) continue;

            if(distances[neighbourNode] > distance + neighbourDistance){
                // previous found distance was greater than the current distance

                // update the via mapping
                via[neighbourNode]  = node;

                // update distance
                distances[neighbourNode] = distance + neighbourDistance;

                // insert updated distance and neighbour node into priority queue
                pq.insert({neighbourNode, distances[neighbourNode]});
            }
        }
    }
    // return distances and via arrays
    return {distances, via};
}

// utility method to create graph
vector<vector<pair<int, int>>> createGraph(){
    int n = 5;

    vector<vector<pair<int, int>>> graph(n);

    graph[0].push_back({1, 4});
    graph[0].push_back({2, 8});
    graph[1].push_back({0, 4});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 5});
    graph[2].push_back({0, 8});
    graph[2].push_back({1, 2});
    graph[2].push_back({3, 5});
    graph[3].push_back({1, 5});
    graph[3].push_back({2, 5});
    graph[3].push_back({4, 6});
    graph[4].push_back({3, 6});

    return graph;
}

int main(){
    int n = 5;

    // create graph and check above algorithm on it
    auto graph = createGraph();
    auto [distances, via] = findShortestPathUsingDijkstra(n, graph, 0);

    cout << "Distances are: ";
    for (int distance : distances) {
        cout << distance << " ";
    }
    cout << endl;

    cout << "Via array is: ";
    for (int v : via) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}