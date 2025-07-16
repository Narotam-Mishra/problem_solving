
// Problem link - https://leetcode.com/problems/left-and-right-sum-differences/?envType=problem-list-v2&envId=array

package Array_problems;

import java.util.*;

public class LeftAndRightSumDifferences {
    public static int[] leftRightDifference(int[] nums) {
        int n = nums.length;

        // store result in `answer`
        int[] answer = new int[n];

        // step 1 - calculate total sum of array elements
        int totalSum = 0;
        for(int num : nums){
            totalSum += num;
        }

        // store left sum in `leftSum`
        int leftSum = 0;

        // step 2 - iterate on nums and calculate difference
        for(int i=0; i<n; i++){
            // step 3 - calculate right sum 
            int rightSum = totalSum - leftSum - nums[i];

            // step 4 - calculate absolute difference in answer
            answer[i] = Math.abs(leftSum - rightSum);

            // step 5 - calculate left sum
            leftSum += nums[i];
        }

        // step 6 - return `answer` array
        return answer;
    }

    public static void main(String[] args) {
        // int[] nums = {10,4,8,3};

        int[] nums = {1};
        int[] res = leftRightDifference(nums);
        System.out.println(Arrays.toString(res));
    }
}