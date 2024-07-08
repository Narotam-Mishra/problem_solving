
// Implement Kruskal's algorithm to find MST

package Graph_problems;

import java.util.*;

public class KruskalAlgorithm {

    // DSU Implementation
    // utility method for find operation
    private static int findDSU(int x, int [] parent){
        if(parent[x] != x){
            // if x is not parent of itself

            // then find the parent of x and attach it to parent
            parent[x] = findDSU(parent[x], parent);  // path compression
        }
        return parent[x];
    }

    // utility method for union operation
    private static void unionDSU(int x, int y, int[] parent, int[] size){
        int xRoot = findDSU(x, parent);
        int yRoot = findDSU(y, parent);

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
    
    public static int kruskalAlgoToFindMST(int[][] edgeList, int numOfVertices){
        // sort edges by weight
        Arrays.sort(edgeList, Comparator.comparingInt(e -> e[2]));

        // to track minimum spanning tree sum
        int spanningTreeSum = 0;

        // to track parent element while perfroming DSU operation
        int[] parent = new int[numOfVertices];

        // size array to keep track of size of grouping
        int[] size = new int[numOfVertices];

        // Initialize parent and size arrays
        for (int i = 0; i < numOfVertices; i++) {
            parent[i] = i;
            size[i] = 1;
        }

        // traverse each edge from edgeList
        for(int[] edge : edgeList){
            // get edges and its correponding weights
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            // find operation to check if both edges belong to same set or not
            if(findDSU(u, parent) != findDSU(v, parent)){
                // if u and v are not in same set or same component
            // it means adding this edge will not form a cycle
                unionDSU(u, v, parent, size);

                // picking the edge and add its weight to spanning tree sum
                spanningTreeSum += weight;
            }
        }
        // return minimum cost to traverse spanning tree
        return spanningTreeSum;
    }

    public static void main(String[] args) {
        int[][] edgeList = {
            {0, 1, 10},
            {0, 2, 6},
            {0, 3, 5},
            {1, 3, 15},
            {2, 3, 4},
        };

        int numOfVertices = 4;
        System.out.println(kruskalAlgoToFindMST(edgeList, numOfVertices));
    }
}