
// Problem link - https://leetcode.com/problems/maximum-average-subarray-i/?envType=problem-list-v2&envId=sliding-window

package sliding_window_problems;

public class MaximumAverageSubarrayI {
    public static double findMaxAverage(int[] nums, int k) {
        // edge case: if array length is less than k
        int n = nums.length;
        if(n < k){
            int sum = 0;
            for(int num : nums){
                sum += num;
            }
            return (double) sum / n;
        }

        // step 1 - calculate sum of first k-elements of array
        int currSum = 0;
        for(int i=0; i<k; i++){
            currSum += nums[i];
        }

        // step 2 - initialize maximum sum `maxSum`
        int maxSum = currSum;

        // step 3 - slide the window through rest of array
        // start from index k and go till end
        for(int i=k; i<n; i++){
            currSum = currSum - nums[i-k] + nums[i];

            // step 4 - update maximum sum if current sum is larger
            maxSum = Math.max(maxSum, currSum);
        }

        // step 5 - return maximum average (sum divided by k)
        return (double) maxSum / k;
    }

    public static void main(String[] args) {
        // int[] nums = {1,12,-5,-6,50,3};
        // int k = 4;

        int[] nums = {5};
        int k = 1;
        System.out.println(findMaxAverage(nums, k));
    }
}