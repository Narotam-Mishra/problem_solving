
// Problem link - https://leetcode.com/problems/minimum-jumps-to-reach-end-via-prime-teleportation/?envType=daily-question&envId=2026-05-08

package Graph_problems;

import java.util.*;

public class MinimumJumpsToReachEndViaPrimeTeleportation {
    // keep track of prime number
    private boolean[] isPrime;

    // utility function to build prime sieve
    private void buildPrimeSieve(int maxNum) {
        // fill prime numbers
        isPrime = new boolean[maxNum + 1];
        Arrays.fill(isPrime, true);

        if (maxNum >= 0) {
            isPrime[0] = false;
        }
        if (maxNum >= 1) {
            isPrime[1] = false;
        }

        for (int num = 2; num * num <= maxNum; num++) {
            if (isPrime[num]) {
                for (int mul = num * num; mul <= maxNum; mul += num) {
                    isPrime[mul] = false;
                }
            }
        }
    }

    public int minJumps(int[] nums) {
        int n = nums.length;

        // map to track number and their indices occurence
        Map<Integer, List<Integer>> mp = new HashMap<>();

        // step 1 - find occurence and max element in nums
        int maxNum = 0;
        for (int i = 0; i < n; i++) {
            mp.computeIfAbsent(nums[i], key -> new ArrayList<>()).add(i);
            maxNum = Math.max(maxNum, nums[i]);
        }

        // step 2 - build prime sieve
        buildPrimeSieve(maxNum);

        // keep track of visited node
        boolean[] visited = new boolean[n];

        // step 3 - apply BFS traversal
        Queue<Integer> q = new LinkedList<>();
        q.offer(0);
        visited[0] = true;

        // keep track of already visited prime numbers
        Set<Integer> seen = new HashSet<>();

        int steps = 0;
        while (!q.isEmpty()) {
            int qSize = q.size();

            while (qSize-- > 0) {
                int i = q.poll();

                // early exit
                if (i == n - 1) {
                    // check if we have reached destination
                    return steps;
                }

                // visit left and right neighbours
                if (i - 1 >= 0 && !visited[i - 1]) {
                    q.offer(i - 1);
                    visited[i - 1] = true;
                }

                if (i + 1 < n && !visited[i + 1]) {
                    q.offer(i + 1);
                    visited[i + 1] = true;
                }

                // skip non prime and already visited prime
                if (!isPrime[nums[i]] || seen.contains(nums[i])) {
                    continue;
                }

                // step 4 - find multiples of prime for teleportation
                for (int mul = nums[i]; mul <= maxNum; mul += nums[i]) {
                    if (!mp.containsKey(mul)) {
                        continue;
                    }

                    for (int j : mp.get(mul)) {
                        if (!visited[j]) {
                            q.offer(j);
                            visited[j] = true;
                        }
                    }
                }

                seen.add(nums[i]);
            }

            // increment minimum jump
            steps++;
        }

        // step 5 - return minimum jumps
        return steps;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,4,6};
        MinimumJumpsToReachEndViaPrimeTeleportation obj = new MinimumJumpsToReachEndViaPrimeTeleportation();
        System.out.println(obj.minJumps(nums));
    }
}
