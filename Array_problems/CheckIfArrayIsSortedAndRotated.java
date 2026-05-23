
// Problem link - https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/?envType=daily-question&envId=2026-05-23

package Array_problems;

public class CheckIfArrayIsSortedAndRotated {
    public boolean check(int[] nums) {
        // get the size of the array
        int n = nums.length;

        // keep track of peak counter to count number of "breaks" where nums[i]
        // > nums[i+1]
        int peak = 0;

        // step 1 - iterate through each element and check if it's greater than
        // the next element
        for (int i = 0; i < n; i++) {
            // using modulo to wrap around from last element to first
            if (nums[i] > nums[(i + 1) % n]) {
                // step 2 - increment peak count when a decreasing point is
                // found
                peak++;
            }
        }

        // step 3 - a sorted and rotated array should have exactly one "break"
        // point
        return peak <= 1;
    }

    public static void main(String[] args) {
        int[] nums = {3,4,5,1,2};
        CheckIfArrayIsSortedAndRotated obj = new CheckIfArrayIsSortedAndRotated();
        System.out.println(obj.check(nums));
    }
}
