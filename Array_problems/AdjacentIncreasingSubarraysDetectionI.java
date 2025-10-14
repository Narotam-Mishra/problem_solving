
// Problem link - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

package Array_problems;

import java.util.*;

public class AdjacentIncreasingSubarraysDetectionI {
    public static boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        // find size of `nums`
        int n = nums.size();

        // step 1 - check for edge case : if array is too small to contain two subarrays of length `k`
        if(n < 2 * k) return false;

        // step 2 - create an array to store which positions have strictly increasing subarrays
        boolean[] increasing = new boolean[n-k+1];

        // step 3 - build incresing array
        for(int i=0; i<n-k+1; i++){
            boolean isIncreasing = true;

            // check if subarray starting at `i` is strictly increasing
            for(int j=i; j<i+k-1; j++){
                if(nums.get(j) >= nums.get(j+1)){
                    isIncreasing = false;
                    // early exit if there is non-increasing pair
                    break;
                }
            }

            increasing[i] = isIncreasing;
        }

        // step 4 - check for two adjacent subarray with no overlap
        for(int i=0; i<=n-2*k; i++){
            if(increasing[i] && increasing[i+k]){
                // step 5 - return true immediately if such pair exist
                return true;
            }
        }

        // otherwise no such pair exist, return false
        return false;
    }

    public static void main(String[] args) {
        // List<Integer> nums = Arrays.asList(2,5,7,8,9,2,3,4,3,1);
        // int k = 3;

        // List<Integer> nums = Arrays.asList(1,2,3,4,4,4,4,5,6,7);
        // int k = 5;

        List<Integer> nums = Arrays.asList(5,8,-2,-1);
        int k = 2;
        System.out.println(hasIncreasingSubarrays(nums, k));
    }
}
