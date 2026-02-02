
// Problem link - https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-ii/description/?envType=daily-question&envId=2026-02-02

package sliding_window_problems;

import java.util.*;

public class DivideArrayIntoSubarraysWithMinimumCostII {
    static class Node {
        long val;
        int idx;

        Node(long val, int idx) {
            this.val = val;
            this.idx = idx;
        }
    }

    public static long minimumCost(int[] nums, int k, int dist) {
        int n = nums.length;

        // stores (k-1) minimum elements
        TreeSet<Node> kMin = new TreeSet<>(
            (a, b) -> a.val != b.val ? Long.compare(a.val, b.val) : Integer.compare(a.idx, b.idx)
        );

        TreeSet<Node> rem = new TreeSet<>(
            (a, b) -> a.val != b.val ? Long.compare(a.val, b.val) : Integer.compare(a.idx, b.idx)
        );

        long sum = 0;

        // step 1 - initial window
        int i = 1;
        while (i - dist < 1) {
            Node cur = new Node(nums[i], i);
            kMin.add(cur);
            sum += nums[i];

            // step 2 - keep only k-1 elements
            if (kMin.size() > k - 1) {
                Node temp = kMin.last(); // largest in kMin
                sum -= temp.val;
                rem.add(temp);
                kMin.remove(temp);
            }
            i++;
        }

        long res = Long.MAX_VALUE;

        // sliding window
        while (i < n) {
            Node cur = new Node(nums[i], i);
            kMin.add(cur);
            sum += nums[i];

            if (kMin.size() > k - 1) {
                Node temp = kMin.last();
                sum -= temp.val;
                rem.add(temp);
                kMin.remove(temp);
            }

            res = Math.min(res, sum);

            // step 4 - remove outgoing element
            Node remove = new Node(nums[i - dist], i - dist);
            if (kMin.contains(remove)) {
                kMin.remove(remove);
                sum -= remove.val;

                if (!rem.isEmpty()) {
                    Node temp = rem.first(); // smallest from rem
                    kMin.add(temp);
                    sum += temp.val;
                    rem.remove(temp);
                }
            } else {
                rem.remove(remove);
            }

            i++;
        }

        // step 6 - final result
        return nums[0] + res;
    }

    public static void main(String[] args) {
        int[] nums = {1,3,2,6,4,2};
        int k = 3, dist = 3;
        System.out.println(minimumCost(nums, k, dist));
    }
}
