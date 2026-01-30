
// Problem link - https://leetcode.com/problems/minimum-cost-to-convert-string-ii/description/?envType=daily-question&envId=2026-01-30

package Graph_problems;

import java.util.*;

public class MinimumCostToConvertStringII {
    static class Pair {
        long cost;
        String node;

        Pair(long cost, String node) {
            this.cost = cost;
            this.node = node;
        }
    }

    long BIG_VALUE = (long) 1e10;

    Map<String, List<Pair>> adj = new HashMap<>();

    // start -> end -> shortest cost
    Map<String, Map<String, Long>> dijkstraMemo = new HashMap<>();

    long[] dpMemo;

    String sourceStr, targetStr;
    TreeSet<Integer> validLengths = new TreeSet<>();

    long dijkstra(String start, String end) {

        if (dijkstraMemo.containsKey(start) &&
                dijkstraMemo.get(start).containsKey(end)) {
            return dijkstraMemo.get(start).get(end);
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>(Comparator.comparingLong(p -> p.cost));

        Map<String, Long> result = new HashMap<>();
        result.put(start, 0L);
        pq.offer(new Pair(0, start));

        while (!pq.isEmpty()) {

            Pair curr = pq.poll();
            long currCost = curr.cost;
            String node = curr.node;

            if (node.equals(end))
                break;

            if (!adj.containsKey(node))
                continue;

            for (Pair edge : adj.get(node)) {
                String adjNode = edge.node;
                long edgeCost = edge.cost;

                long newCost = currCost + edgeCost;
                if (!result.containsKey(adjNode) || newCost < result.get(adjNode)) {
                    result.put(adjNode, newCost);
                    pq.offer(new Pair(newCost, adjNode));
                }
            }
        }

        long finalCost = result.getOrDefault(end, BIG_VALUE);

        dijkstraMemo
                .computeIfAbsent(start, k -> new HashMap<>())
                .put(end, finalCost);

        return finalCost;
    }

    long solve(int idx) {
        if (idx >= sourceStr.length())
            return 0;

        if (dpMemo[idx] != -1)
            return dpMemo[idx];

        long minCost = BIG_VALUE;

        if (sourceStr.charAt(idx) == targetStr.charAt(idx)) {
            minCost = solve(idx + 1);
        }

        for (int len : validLengths) {

            if (idx + len > sourceStr.length())
                break;

            String srcSub = sourceStr.substring(idx, idx + len);
            String tgtSub = targetStr.substring(idx, idx + len);

            if (!adj.containsKey(srcSub))
                continue;

            long pathCost = dijkstra(srcSub, tgtSub);
            if (pathCost == BIG_VALUE)
                continue;

            minCost = Math.min(minCost, pathCost + solve(idx + len));
        }

        return dpMemo[idx] = minCost;
    }

    public long minimumCost(
            String source,
            String target,
            String[] original,
            String[] changed,
            int[] cost) {

        sourceStr = source;
        targetStr = target;

        dpMemo = new long[10001];
        Arrays.fill(dpMemo, -1);

        for (int i = 0; i < original.length; i++) {
            adj.computeIfAbsent(original[i], k -> new ArrayList<>())
                    .add(new Pair(cost[i], changed[i]));
            validLengths.add(original[i].length());
        }

        long result = solve(0);
        return result == BIG_VALUE ? -1 : result;
    }

    public static void main(String[] args) {
        MinimumCostToConvertStringII solution = new MinimumCostToConvertStringII();
        
        String source = "bnc";
        String target = "abc";
        String[] original = {"bn", "bc", "b", "n"};
        String[] changed = {"ab", "ac", "c", "a"};
        int[] cost = {1, 2, 1, 3};

        long result = solution.minimumCost(source, target, original, changed, cost);
        System.out.println("Minimum cost: " + result);
    }
}
