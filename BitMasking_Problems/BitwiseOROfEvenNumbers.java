
// Problem link - https://leetcode.com/problems/bitwise-or-of-even-numbers-in-an-array/?envType=problem-list-v2&envId=array

package BitMasking_Problems;

public class BitwiseOROfEvenNumbers {
    public static int evenNumberBitwiseORs(int[] nums) {
        // store final result in `res`
        int res = 0;

        // step 1 - iterate on each number of `nums`
        for (int num : nums) {
            // step 2 - check if it is even number or not
            if (num % 2 == 0) {
                // step 3 - calculate bitwise OR of even number
                // and store result in `res`
                res = res | num;
            }
        }

        // step 4 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,2,3,4,5,6};
        System.out.println(evenNumberBitwiseORs(nums));
    }
}