
// Problem link - https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/description/?envType=daily-question&envId=2026-01-27

package Graph_problems;

import java.util.*;

public class MinimumCostPathWithEdgeReversals {
    public static int minCost(int n, int[][] edges) {
        Map<Integer, List<int[]>> adj = new HashMap<>();
        // Build adjacency list
        for (int[] e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj.computeIfAbsent(u, k -> new ArrayList<>()).add(new int[] { v, w });
            adj.computeIfAbsent(v, k -> new ArrayList<>()).add(new int[] { u, w * 2 });
        }

        int[] dist = new int[n];
        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[0] = 0;

        // Min-heap: {distance, node}
        PriorityQueue<int[]> pq = new PriorityQueue<>(Comparator.comparingInt(a -> a[0]));
        pq.offer(new int[] { 0, 0 });

        while (!pq.isEmpty()) {
            int[] cur = pq.poll();
            int d = cur[0], node = cur[1];

            if (node == n - 1)
                return dist[n - 1];
            if (d != dist[node])
                continue; // skip stale entry

            List<int[]> neighbors = adj.getOrDefault(node, Collections.emptyList());
            for (int[] p : neighbors) {
                int adjNode = p[0], w = p[1];
                if (d + w < dist[adjNode]) {
                    dist[adjNode] = d + w;
                    pq.offer(new int[] { dist[adjNode], adjNode });
                }
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        // int n = 4;
        // int[][] edges = {{0,1,3},{3,1,1},{2,3,4},{0,2,2}};

        int n = 4;
        int[][] edges = {{0,2,1},{2,1,1},{1,3,1},{2,3,3}};
        System.out.println(minCost(n, edges));
    }
}
