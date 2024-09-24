
// Problem link : https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class SingleNumber {
    public static int singleNumber(int[] nums) {
        int res = 0;
        for(int num : nums){
            res ^= num;
        }   
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 2, 1};

        int[] nums = {4, 1, 2, 1, 2};
        System.out.println(singleNumber(nums));
    }
}
