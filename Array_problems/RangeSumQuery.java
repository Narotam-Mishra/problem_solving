
// Problem link - https://leetcode.com/problems/range-sum-query-immutable/description/

package Array_problems;

class NumArray {
    private int[] nums;
    public NumArray(int[] nums) {
        this.nums = nums;
    }
    
    public int sumRange(int left, int right) {
        int rangeSum = 0;
        for(int i=left; i<=right; i++){
            rangeSum += nums[i];
        }
        return rangeSum;
    }
}

public class RangeSumQuery {
    public static void main(String[] args) {
        int[] nums = {1, 2, 3, 4, 5};
        NumArray numArray = new NumArray(nums);

        // Test the sumRange method
        System.out.println(numArray.sumRange(0, 2)); // Output: 6 (1 + 2 + 3)
        System.out.println(numArray.sumRange(1, 3)); // Output: 9 (2 + 3 + 4)
        System.out.println(numArray.sumRange(2, 4)); // Output: 12 (3 + 4 + 5)
    }
}