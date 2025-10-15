
// Problem link - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/description/?envType=daily-question&envId=2025-10-14

package Array_problems;

import java.util.*;

public class AdjacentIncreasingSubarraysDetectionI {
    public static boolean hasIncreasingSubarrays1(List<Integer> nums, int k) {
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

    public static boolean hasIncreasingSubarrays(List<Integer> nums, int k) {
        // find size of `nums` array
        int n = nums.size();

        // currRun: length of current strictly increasing sequence
        // prevRun: length of previous strictly increasing sequence
        int currRun = 1, prevRun = 0;

        // step 1 - iterate on each number of `nums`
        for (int i = 1; i < n; i++) {
            // step 2 - check if current number is greater than previous number
            if (nums.get(i) > nums.get(i - 1)) {
                // extend current increasing run
                currRun++;
            } else {
                // step 3 - current run breaks, save it as previous and reset
                // current
                prevRun = currRun;
                currRun = 1;
            }

            // step 4 - case 1 : two adjacent subarrays of length k within the
            // current run so, we can split currRun into two equal or nearly
            // equal parts hence we can return true
            if (currRun / 2 >= k) {
                return true;
            }

            // step 5 - case 2 : one subarray at end of previous run, one at
            // start of current run check if minimum of current run(currRun) and
            // previous run(prevRun) is >= `k` so, we can return true in this
            // case as well
            if (Math.min(currRun, prevRun) >= k) {
                return true;
            }
        }

        // otherwise return false
        return false;
    }

    public static void main(String[] args) {
        List<Integer> nums = Arrays.asList(2,5,7,8,9,2,3,4,3,1);
        int k = 3;

        // List<Integer> nums = Arrays.asList(1,2,3,4,4,4,4,5,6,7);
        // int k = 5;

        // List<Integer> nums = Arrays.asList(5,8,-2,-1);
        // int k = 2;
        System.out.println(hasIncreasingSubarrays(nums, k));
    }
}
