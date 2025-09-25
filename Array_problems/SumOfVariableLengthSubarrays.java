
// Problem link - https://leetcode.com/problems/sum-of-variable-length-subarrays/?envType=problem-list-v2&envId=array

package Array_problems;

public class SumOfVariableLengthSubarrays {
    public static int subarraySum(int[] nums) {
        // find size of input array `nums`
        int n = nums.length;

        // store final subarray sum in `sum`
        int sum = 0;

        // step 1 - iterate on `nums` for each index `i`
        for(int i=0; i<n; i++){
            // step 2 - calculate start index as per problem
            int start = Math.max(0, i-nums[i]);

            // step 3 - add up all elements from nums[start] to nums[i]
            for(int j=start; j<=i; j++){
                sum += nums[j];
            }
        }

        // step 4 - return final subarray sum
        return sum;
    }

    public static void main(String[] args) {
        // int[] nums = {2,3,1};

        int[] nums = {3,1,1,2};
        System.out.println(subarraySum(nums));
    }
}
