
// Graph representation using Adjacency List (using Linked List)

package Graph_problems;

import java.util.*;

class Graph {
    private List<List<Integer>> adjList; // Adjacency list

    // constructor
    public Graph(int numOfVertices){
        adjList = new ArrayList<>(numOfVertices);
        for(int i = 0; i < numOfVertices; i++){
            adjList.add(new LinkedList<>());
        }
    }

    // utility method to add an edge into the graph
    public void addEdge(int v1, int v2, boolean biDir){
        adjList.get(v1).add(v2);

        // if graph is bi-directional
        if(biDir){
            adjList.get(v2).add(v1);
        }
    }

    // utility method to display the graph
    public void displayGraph(){
        for(int i=0;  i<adjList.size(); i++){
            System.out.println("Vertex "+ i +": "+ adjList.get(i));
        }
    }
}

public class GraphAdjacencyListRep {
    public static void main(String[] args) {
        Graph g = new Graph(7);
        g.addEdge(0, 1, true);
        g.addEdge(0, 6, true);
        g.addEdge(6, 5, true);
        g.addEdge(1, 5, true);
        g.addEdge(1, 2, true);
        g.addEdge(2, 4, true);
        g.addEdge(2, 3, true);
        g.addEdge(4, 3, true);

        // display graph
        g.displayGraph();
    }
}
