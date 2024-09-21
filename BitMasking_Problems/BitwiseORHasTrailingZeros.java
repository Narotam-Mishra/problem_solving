
// Problem link : https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class BitwiseORHasTrailingZeros {
    
    public static boolean hasTrailingZeros(int[] nums) {
        int count = 0;
        for(int num : nums){
            if((num & 1) != 1) count++;
        }
        return count >= 2;
    }

    public static void main(String[] args) {
        // int[] nums = {1, 2, 3, 4, 5};

        // int[] nums = {2, 4, 8, 16};

        int[] nums = {1, 3, 5, 7, 9};
        boolean res = hasTrailingZeros(nums);
        System.out.println(res);
    }
}