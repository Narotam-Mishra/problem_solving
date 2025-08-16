
// Problem link - https://leetcode.com/problems/minimum-absolute-difference/description/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class MinimumAbsoluteDifference {
    public static List<List<Integer>> minimumAbsDifference(int[] arr) {
        int n = arr.length;

        // store minimum absolute difference in `minDiff`
        int minDiff = Integer.MAX_VALUE;

        // step 1 - sort the array
        Arrays.sort(arr);

        // step 2 - check all pairs for minimum absolute difference
        for (int i = 0; i < n - 1; i++) {
            // always positive since array is sorted
            int currDiff = arr[i + 1] - arr[i];
            minDiff = Math.min(currDiff, minDiff);
        }

        // step 3 - iterate through adjacent pairs again to find all with min difference
        List<List<Integer>> res = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            int currDiff = arr[i + 1] - arr[i];

            // step 4 - if this pair has the minimum difference, add it to result
            if (currDiff == minDiff) {
                List<Integer> pair = Arrays.asList(arr[i], arr[i + 1]);
                res.add(pair);
            }
        }

        // step 5 - return resultant array `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] arr = {4,2,1,3};

        int[] arr = {1,3,6,10,15};
        System.out.println(minimumAbsDifference(arr));
    }
}