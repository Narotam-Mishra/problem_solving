
// Problem link - https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30

package Array_problems;

public class FindTriangularSumOfArray {
    public static int triangularSum(int[] nums) {
        // find size of inpt array `nums`
        int n = nums.length;

        // step 1 - iterate till we have only one element left in array `nums`
        while(n > 1){
            // step 2 - process each adjacent pairs of nums array
            for(int i=0; i<n-1; i++){
                // step 3 - add current element with next element and take mod 10
                // store result back in position i 
                nums[i] = (nums[i] + nums[i+1]) % 10;
            }

            // step 4 - reduce the effective length of our array
            n--;
        }

        // step 5 - return the single remaining element
        return nums[0];
    }

    public static void main(String[] args) {
        // int[] nums = {1,2,3,4,5};

        int[] nums = {5};
        System.out.println(triangularSum(nums));
    }
}
