
// Problem link - https://leetcode.com/problems/closest-equal-element-queries/description/?envType=daily-question&envId=2026-04-16

package Hashing_and_HashMap_problems;

import java.util.*;

public class ClosestEqualElementQueries {
    public static  List<Integer> solveQueries(int[] nums, int[] queries) {
        int n = nums.length;

        // step 1 - find occurrence of element in map
        Map<Integer, List<Integer>> mp = new HashMap<>();
        for (int i = 0; i < n; i++) {
            mp.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);
        }

        // step 2 - iterate and solve each query
        List<Integer> result = new ArrayList<>();
        for (int qi : queries) {
            int element = nums[qi];
            List<Integer> occList = mp.get(element);

            int len = occList.size();
            if (len == 1) {
                result.add(-1);
                continue;
            }

            // step 3 - using binary search to find qi in occList
            int qiPos = Collections.binarySearch(occList, qi);

            // step 4 - calculate minimum distance for left and right neighbour
            // keep track of minimum distance
            int res = Integer.MAX_VALUE;

            // find right neighbour, distance & circular distance
            int right = occList.get((qiPos + 1) % len);
            int dist = Math.abs(qi - right);
            int cirDist = n - dist;

            // update minimum distance for right
            res = Math.min(res, Math.min(dist, cirDist));

            // find left neighbour, distance & circular distance
            int left = occList.get((qiPos - 1 + len) % len);
            dist = Math.abs(qi - left);
            cirDist = n - dist;

            // update minimum distance for left
            res = Math.min(res, Math.min(dist, cirDist));

            // store res in final result
            result.add(res);
        }

        // step 5 - return final resultant list
        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1,3,1,4,1,3,2};
        int[] queries = {0,3,5};
        List<Integer> res = solveQueries(nums, queries);
        System.out.println(res);
    }
}
