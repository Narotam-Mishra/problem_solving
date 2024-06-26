
// Problem link - https://leetcode.com/problems/find-if-path-exists-in-graph/description/

package Graph_problems;

import java.util.*;

public class PathExistInGraph {

    // utility method to perfrom DFS graph traversal recursively
    public static boolean dfs(int src, int dest, List<List<Integer>> g, Set<Integer> visited){
        // base case: if src is dest only
        if(src == dest) return true;

        // add the source, 'src' node to visted set as we have visited it 
        // and now we will go to nearest neighbour
        visited.add(src);

        // traverse each neighbour one by one
        boolean ans = false;
        for(int neighbour : g.get(src)){
            if(!visited.contains(neighbour)){
                // if we have not already visited the neighbour then go to that neighbour
                ans = ans || dfs(neighbour, dest, g, visited);
            }
        }

        // return answer'ans'
        return ans;
    }
    public static boolean validPath(int n, int[][] edges, int source, int destination) {
        // graph creation using array list
        List<List<Integer>> g = new ArrayList<>();

        // convert edge list into adjacency list
        for(int i=0; i<n; i++){
            g.add(new ArrayList<>());
        }

        // populate the graph's edges
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];

            // bidirectional edges
            g.get(u).add(v);
            g.get(v).add(u);
        }

        // call to dfs method and perform graph traversal recursively
        return dfs(source, destination, g, new HashSet<>());
    }

    public static void main(String[] args) {
        // int n = 6;
        // int [][] edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
        // int source = 0;
        // int destination = 5;

        int n = 3;
        int [][] edges = {{0, 1}, {1, 2}, {2, 0}};
        int source = 0;
        int destination = 2;

        boolean res = validPath(n, edges, source, destination);
        System.out.println("Path from " + source + " to " + destination + " exists: " + res);
    }
}