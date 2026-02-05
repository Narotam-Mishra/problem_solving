
// Problem link - https://leetcode.com/problems/transformed-array/description/?envType=daily-question&envId=2026-02-05

package Array_problems;

import java.util.Arrays;

public class TransformedArray {
    public static int[] constructTransformedArray(int[] nums) {
        int n = nums.length;

        // store final result in `res`
        int[] res = new int[n];

        // step 1 - iterate on each num of nums
        for(int i=0; i<n; i++){
            // step 2 - check if it is positive value
            if(nums[i] > 0){
                // then move right
                int newIndex = (i + nums[i]) % n;
                res[i] = nums[newIndex];
            }

            // step 3 - check if it is negative value
            else if(nums[i] < 0){
                // move left
                int steps = Math.abs(nums[i]);
                int newIndex = ((i - steps) % n + n) % n;
                res[i] = nums[newIndex];
            }

            // step 4 - check if value is zero
            else{
                // then stay at same index
                res[i] = nums[i];
            }
        }

        // step 5 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {3,-2,1,1};

        int[] nums = {-1,4,-1};
        int[] res = constructTransformedArray(nums);
        System.out.println(Arrays.toString(res));
    }
}
