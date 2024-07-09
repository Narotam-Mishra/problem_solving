
// Implement Prim's algorithm to find MST

package Graph_problems;

import java.util.*;

class Edge {
    int target, weight;

    public Edge(int target, int weight){
        this.target = target;
        this.weight = weight;
    }
}

class GraphUtils {
    private int numOfVertices;
    private LinkedList<Edge>[] adjList;

    @SuppressWarnings("unchecked")
    public GraphUtils(int n){
        numOfVertices = n;
        adjList = new LinkedList[n];
        for(int i=0; i<n; i++){
            adjList[i] = new LinkedList<>();
        }
    }

    // utility method to add edges in graph
    public void addEdges(int u, int v, int weight){
        adjList[u].add(new Edge(v, weight));
        adjList[v].add(new Edge(u, weight));
    }

    // utility method to use Prim's algorithm
    public void findMSTUsingPrimAlgo(){
        // visited array to keep track to already visited node/vertices
        boolean[] visited = new boolean[numOfVertices];

        // using min-heap (min priority queue) to keep track of minimum weight
        PriorityQueue<Edge> pq = new PriorityQueue<>(Comparator.comparingInt(e -> e.weight));

        // assume start node as 0
        int startNode = 0;

        // keep track of MST cost
        int totalMSTCost = 0;

        // mst array to keep track to nodes/vertices
        List<Edge> mst = new ArrayList<>();

        // start with the first node, pushing all its edges into the heap
        visited[startNode] = true;
        for(Edge edge : adjList[startNode]){
            pq.add(new Edge(edge.target, edge.weight));
        }

        // traverse min-heap to calculate minimum cost of MST
        while(!pq.isEmpty()){
            Edge minEdge = pq.poll();

            // check if the destination node is already visited, skip
            if(visited[minEdge.target]) continue;

            // mark the destination node as visited and add the edge to the MST
            visited[minEdge.target] = true;
            
            // add this node/vertex into mst list
            mst.add(minEdge);

            // calculate MST's cost
            totalMSTCost += minEdge.weight;

            // push all edges from the newly visited node to the heap
            for(Edge edge : adjList[minEdge.target]){
                if(!visited[edge.target]){
                    pq.add(new Edge(edge.target, edge.weight));
                }
            }
        }

        System.out.println("Total cost of MST: " + totalMSTCost);
        System.out.println("Edges in the MST:");
        for (Edge edge : mst) {
            System.out.println(edge.target + " with weight " + edge.weight);
        }
    }
}

public class PrimAlgorithm {
    public static void main(String[] args) {
        GraphUtils g = new GraphUtils(5);
        g.addEdges(0, 1, 2);
        g.addEdges(0, 3, 6);
        g.addEdges(1, 2, 3);
        g.addEdges(1, 3, 8);
        g.addEdges(1, 4, 5);
        g.addEdges(2, 4, 7);
        g.addEdges(3, 4, 9);

        g.findMSTUsingPrimAlgo();
    }
}
