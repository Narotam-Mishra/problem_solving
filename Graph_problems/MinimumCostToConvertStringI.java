
// Problem link - https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29

package Graph_problems;

public class MinimumCostToConvertStringI {
    private static final long INF = (long) 1e18;

    private static void applyFloydWarshall(
            long[][] adjMatrix,
            char[] original,
            char[] changed,
            int[] cost
    ) {
        // Populate adjacency matrix
        for (int i = 0; i < original.length; i++) {
            int src = original[i] - 'a';
            int tar = changed[i] - 'a';
            adjMatrix[src][tar] = Math.min(adjMatrix[src][tar], cost[i]);
        }

        // Floyd–Warshall
        for (int k = 0; k < 26; k++) {
            for (int i = 0; i < 26; i++) {
                for (int j = 0; j < 26; j++) {
                    if (adjMatrix[i][k] < INF && adjMatrix[k][j] < INF) {
                        adjMatrix[i][j] = Math.min(
                                adjMatrix[i][j],
                                adjMatrix[i][k] + adjMatrix[k][j]
                        );
                    }
                }
            }
        }
    }

    public static long minimumCost(String source, String target, char[] original, char[] changed, int[] cost) {
        // step 1 - create adjacency matrix and populate its cost
        long[][] adjMatrix = new long[26][26];

        // Initialize with INF
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                adjMatrix[i][j] = INF;
            }
        }

        // step 2 - apply Floyd Warshall Algorithm
        applyFloydWarshall(adjMatrix, original, changed, cost);

        // step 3 - calculate minimum cost
        long ans = 0;
        for (int i = 0; i < source.length(); i++) {
            // skip same character
            if (source.charAt(i) == target.charAt(i)) continue;

            int s = source.charAt(i) - 'a';
            int t = target.charAt(i) - 'a';

            // check if no path exist
            if (adjMatrix[s][t] == INF) return -1;

            ans += adjMatrix[s][t];
        }

        // step 4 - return minimum cost from `ans`
        return ans;
    }

    public static void main(String[] args) {
        String source = "abcd", target = "acbe";
        char[] original = {'a','b','c','c','e','d'}, changed = {'b','c','b','e','b','e'};
        int[] cost = {2,5,5,1,2,20};
        System.out.println(minimumCost(source, target, original, changed, cost));
    }
}
