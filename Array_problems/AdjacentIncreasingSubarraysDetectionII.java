
// Problem link - https://leetcode.com/problems/adjacent-increasing-subarrays-detection-ii/?envType=daily-question&envId=2025-10-15

package Array_problems;

import java.util.*;

public class AdjacentIncreasingSubarraysDetectionII {
    public static int maxIncreasingSubarrays(List<Integer> nums) {
        // find size of `nums` list
        int n = nums.size();
        
        // currRun: length of current strictly increasing sequence
        // prevRun: length of previous strictly increasing sequence
        int currRun = 1, prevRun = 0;

        // step 1 - iterate on each number of `nums`
        int k = 0;
        for(int i=1; i<n; i++){
            // step 2 - check if current number is greater than previous number
            if(nums.get(i) > nums.get(i-1)){
                // extend current increasing run
                currRun++;
            }else{
                // step 3 - current run breaks, save it as previous and reset current
                prevRun = currRun;
                currRun = 1;
            }

            // step 4 - case 1 : two adjacent subarrays of length k within the
            // current run so, we can split currRun into two equal or nearly equal parts
            k = Math.max(k, currRun/2);
            
            // step 5 - case 2 : one subarray at end of previous run, one at
            // start of current run so, the maximum k is limited by the shorter of the two runs
            k = Math.max(k, Math.min(currRun, prevRun));
        }

        // step 6 - return final value of `k`
        return k;
    }

    public static void main(String[] args) {
        // List<Integer> nums = Arrays.asList(2,5,7,8,9,2,3,4,3,1);

        List<Integer> nums = Arrays.asList(1,2,3,4,4,4,4,5,6,7);
        System.out.println(maxIncreasingSubarrays(nums));
    }
}
