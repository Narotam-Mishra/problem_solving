
// Problem link : https://leetcode.com/problems/maximum-strong-pair-xor-i/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class MaximumStrongPairXOR {
    public static int maximumStrongPairXor(int[] nums) {
        // intialize `maxXor` to 0 to store result
        int maxXor = 0;

        // iterate on each pairs
        for(int i=0; i<nums.length; i++){
            for(int j=i+1; j<nums.length; j++){
                // check strong pair condition
                if(Math.abs(nums[i] - nums[j]) <= Math.min(nums[i], nums[j])){
                    // calculate XOR and find maximum XOR value
                    maxXor = Math.max(maxXor, nums[i] ^ nums[j]);
                }
            }
        }
        // return `maxXor` value
        return maxXor;
    }

    public static void main(String[] args) {
        // int[] arr = {1,2,3,4,5};

        // int[] arr = {10, 100};

        int[] arr = {5, 6, 25, 30};
        System.out.println(maximumStrongPairXor(arr));
    }
}