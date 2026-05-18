
// Problem link - https://leetcode.com/problems/jump-game-iv/description/?envType=daily-question&envId=2026-05-18

package Graph_problems;

import java.util.*;

public class JumpGameIV {
    public int minJumps(int[] arr) {
        int n = arr.length;

        // edge case: already at the last index
        if (n == 1) return 0;

        // step 1 - precompute value -> list of indices map
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.computeIfAbsent(arr[i], key -> new ArrayList<>()).add(i);
        }

        // step 2 - using BFS Algorithm
        // keep track of visited node
        boolean[] visited = new boolean[n];

        // using BFS queue to hold current index
        Queue<Integer> q = new ArrayDeque<>();
        q.offer(0);
        visited[0] = true;

        // keep track of minimum steps
        int minSteps = 0;

        // step 3 - start performing BFS traversal
        while (!q.isEmpty()) {
            // each iteration of outer loop = 1 step/level
            minSteps++;

            // process all nodes at current level
            int levelSize = q.size();

            for (int k = 0; k < levelSize; k++) {
                int currNode = q.poll();

                // explore all neighbours
                int left = currNode - 1;
                int right = currNode + 1;

                // neighbor 1: Jump right
                if (right < n && !visited[right]) {
                    if (right == n - 1) return minSteps;
                    visited[right] = true;
                    q.offer(right);
                }

                // neighbor 2: Jump left
                if (left >= 0 && !visited[left]) {
                    if (left == n - 1) return minSteps;
                    visited[left] = true;
                    q.offer(left);
                }

                // neighbor 3: teleport to all indices with same value
                List<Integer> sameValueIndices = mp.get(arr[currNode]);
                if (sameValueIndices != null) {
                    for (int j : sameValueIndices) {
                        if (!visited[j]) {
                            if (j == n - 1) return minSteps;
                            visited[j] = true;
                            q.offer(j);
                        }
                    }
                }

                // clear this value group from the map
                // Once we process a group member via BFS, all others in the
                // group are already queued or visited.
                mp.remove(arr[currNode]);
            }
        }

        return -1;
    }

    public static void main(String[] args) {
        int[] arr = {100,-23,-23,404,100,23,23,23,3,404};
        JumpGameIV obj = new JumpGameIV();
        System.out.println(obj.minJumps(arr));
    }
}
