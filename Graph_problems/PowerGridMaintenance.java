
// Problem link - https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06

package Graph_problems;

import java.util.*;

public class PowerGridMaintenance {
    // utility method to perform DFS traversal
    private static void dfs(int currentNode,
            Map<Integer, List<Integer>> graph,
            int componentId,
            int[] nodeToComponentId,
            Map<Integer, TreeSet<Integer>> componentToOnlineNodes,
            boolean[] visited) {
        // mark current node as visited
        visited[currentNode] = true;

        // assign component ID to this node
        nodeToComponentId[currentNode] = componentId;

        // add this node to the set of online nodes in this component
        componentToOnlineNodes.computeIfAbsent(componentId, k -> new TreeSet<>()).add(currentNode);

        // recursively visit all unvisited neighbors
        if (graph.containsKey(currentNode)) {
            for (int neighbor : graph.get(currentNode)) {
                if (!visited[neighbor]) {
                    dfs(neighbor, graph, componentId, nodeToComponentId, componentToOnlineNodes, visited);
                }
            }
        }
    }

    public static int[] processQueries(int c, int[][] connections, int[][] queries) {
        // step 1 - build adjacency list representation of the graph
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int[] connection : connections) {
            int station1 = connection[0];
            int station2 = connection[1];

            graph.computeIfAbsent(station1, k -> new ArrayList<>()).add(station2);
            graph.computeIfAbsent(station2, k -> new ArrayList<>()).add(station1);
        }

        // maps each component ID to TreeSet of online nodes in that component
        // TreeSet maintains sorted order (smallest ID first)
        Map<Integer, TreeSet<Integer>> componentToOnlineNodes = new HashMap<>();

        // step 2 - find connected components using DFS
        boolean[] visited = new boolean[c + 1];
        int[] nodeToComponentId = new int[c + 1];

        for (int station = 1; station <= c; station++) {
            if (!visited[station]) {
                // use the first node in component as component ID
                int componentId = station;
                dfs(station, graph, componentId, nodeToComponentId, componentToOnlineNodes, visited);
            }
        }

        // step 3 - process queries and build result
        List<Integer> resultList = new ArrayList<>();
        for (int[] query : queries) {
            int queryType = query[0];
            int station = query[1];

            if (queryType == 1) {
                // type 1: maintenance check query
                int componentId = nodeToComponentId[station];
                TreeSet<Integer> onlineNodes = componentToOnlineNodes.get(componentId);

                // check if station itself is online
                if (onlineNodes != null && onlineNodes.contains(station)) {
                    resultList.add(station);
                }
                // find smallest online station in same component
                else if (onlineNodes != null && !onlineNodes.isEmpty()) {
                    int smallestOnlineStation = onlineNodes.first();
                    resultList.add(smallestOnlineStation);
                }
                // no online station in this component
                else {
                    resultList.add(-1);
                }
            } else {
                // type 2: Take station offline
                int componentId = nodeToComponentId[station];
                TreeSet<Integer> onlineNodes = componentToOnlineNodes.get(componentId);
                if (onlineNodes != null) {
                    onlineNodes.remove(station);
                }
            }
        }

        // step 4 - convert List<Integer> to int[]
        int[] res = new int[resultList.size()];
        for (int i = 0; i < resultList.size(); i++) {
            res[i] = resultList.get(i);
        }

        // step 5 - return final result, res
        return res;
    }

    public static void main(String[] args) {
        int c = 5;
        int[][] connections = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 5 } };
        int[][] queries = { { 1, 3 }, { 2, 1 }, { 1, 1 }, { 2, 2 }, { 1, 2 } };
        int[] res = processQueries(c, connections, queries);
        System.out.println(Arrays.toString(res));
    }
}
