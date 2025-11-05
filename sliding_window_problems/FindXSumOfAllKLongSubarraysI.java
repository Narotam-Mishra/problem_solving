
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-i/?envType=daily-question&envId=2025-11-04

package sliding_window_problems;

import java.util.*;

public class FindXSumOfAllKLongSubarraysI {
    static class Pair implements Comparable<Pair> {
        int freq, val;

        Pair(int freq, int val) {
            this.freq = freq;
            this.val = val;
        }

        @Override
        public int compareTo(Pair other) {
            // Sort primarily by frequency (ascending),
            // and by value (ascending) if frequencies are equal
            if (this.freq == other.freq)
                return this.val - other.val;
            return this.freq - other.freq;
        }
    }

    // utility method to find the x-sum of current frequency map
    private static int findTopXSum(Map<Integer, Integer> freqMap, int x) {
        PriorityQueue<Pair> pq = new PriorityQueue<>();

        for (Map.Entry<Integer, Integer> entry : freqMap.entrySet()) {
            pq.offer(new Pair(entry.getValue(), entry.getKey()));

            // Keep only top x most frequent elements
            if (pq.size() > x) {
                pq.poll();
            }
        }

        int sum = 0;
        while (!pq.isEmpty()) {
            Pair p = pq.poll();
            sum += p.freq * p.val;
        }

        return sum;
    }

    public static int[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        Map<Integer, Integer> freqMap = new HashMap<>();
        List<Integer> res = new ArrayList<>();

        int i = 0, j = 0;
        while (j < n) {
            // add current number to frequency map
            freqMap.put(nums[j], freqMap.getOrDefault(nums[j], 0) + 1);

            // when window reaches size k
            if (j - i + 1 == k) {
                // calculate x-sum
                int s = findTopXSum(freqMap, x);
                res.add(s);

                // remove leftmost element from window
                freqMap.put(nums[i], freqMap.get(nums[i]) - 1);
                if (freqMap.get(nums[i]) == 0) {
                    freqMap.remove(nums[i]);
                }

                i++;
            }

            j++;
        }

        // convert List<Integer> to int[]
        int[] ans = new int[res.size()];
        for (int idx = 0; idx < res.size(); idx++) {
            ans[idx] = res.get(idx);
        }

        // step 6 - return fianl result `ans`
        return ans;
    }

    public static void main(String[] args) {
        int[] nums = {1,1,2,2,3,4,2,3};
        int k = 6, x = 2;
        int[] res = findXSum(nums, k, x);
        System.out.println(Arrays.toString(res));
    }
}
