
// Problem link - https://leetcode.com/problems/maximum-number-of-k-divisible-components/?envType=daily-question&envId=2025-11-28

package Graph_problems;

import java.util.*;

public class MaximumNumberOfKDIvisibleComponents {
    // keep track of component count
    public static int componentCount = 0;

    // utility method to perform DFS traversal
    private static int dfsHelper(int currNode, int parent, Map<Integer, List<Integer>> adj, int[] values, int k){
        // start with current node value
        int sum = values[currNode];

        // traverse all neighbour subtree
        for(int ngbr : adj.get(currNode)){
            // skip parent node to avoid loop
            if(ngbr != parent){
                // recursively get sum from children subtree
                int childSum = dfsHelper(ngbr, currNode, adj, values, k);
                sum += childSum;
                sum = sum % k;
            }
        }

        // take final modulo
        sum = sum % k;

        // check if subtree sum is divisible by k, we found a valid component
        if(sum == 0){
            // increment component count
            componentCount++;
        }

        return sum;
    }

    public static int maxKDivisibleComponents(int n, int[][] edges, int[] values, int k) {
        // reset component count value before each call
        componentCount = 0;

        // step 1 - make graph connection using adjacency list
        Map<Integer, List<Integer>> adjList = new HashMap<>();

        // intialize empty lists for all nodes
        for(int i=0; i<n; i++){
            adjList.put(i, new ArrayList<>());
        }

        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];

            adjList.get(u).add(v);
            adjList.get(v).add(u);
        }

        // step 2 - perform DFS traversal to visit each child subtree
        dfsHelper(0, -1, adjList, values, k);

        // step 3 - return each valid component count
        return componentCount;
    }

    public static void main(String[] args) {
        // int n = 5;
        // int[][] edges = {{0,2},{1,2},{1,3},{2,4}};
        // int[] values = {1,8,1,4,4};
        // int k = 6;

        int n = 7;
        int[][] edges = {{0,1},{0,2},{1,3},{1,4},{2,5},{2,6}};
        int[] values = {3,0,6,1,5,2,1};
        int k = 3;
        System.out.println(maxKDivisibleComponents(n, edges, values, k));
    }
}
