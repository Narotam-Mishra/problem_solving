package Array_problems;

import java.util.Arrays;

public class MaximumNumberOfDistinctElementsAfterOperations {
    public static int maxDistinctElements(int[] nums, int k) {
        // find size of input array `nums` 
        int n = nums.length;

        // step 1 - sort input array `nums` to process elements in ascending order
        Arrays.sort(nums);

        // step 2 - keep track of previously updated element
        // we need this to ensure the next element gets a value > prev (distinct)
        int prevVal = Integer.MIN_VALUE;

        // step 3 - iterate through each element in the sorted array
        int count = 0;
        for(int i=0; i<n; i++){
            // step 4 - calculate the minimum possible value for current element
            int minVal = nums[i] - k;

            // case 1 - if previous value is less than the minimum possible
            // value this means there's a gap, and we can place current element at its minimum
            if(prevVal < minVal){
                prevVal = nums[i] - k;

                // increment count for this distinct element
                count++;
            }

            // case 2 - if previous value is within or just before the valid
            // range check if prev is less than the maximum possible value
            // (nums[i]+k)
            else if(prevVal < nums[i]+k){
                // this means we can place the element just after prev
                prevVal = prevVal + 1;
                
                // increment count for this distinct element
                count++;
            }
        }

        // step 5 - return the total count of distinct elements we could create
        return count;
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,2,3,3,4};
        // int k = 2;

        int[] nums = {4,4,4,4};
        int k = 1;
        System.out.println(maxDistinctElements(nums, k));
    }
}
