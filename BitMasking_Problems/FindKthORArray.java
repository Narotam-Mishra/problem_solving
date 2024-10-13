
// Problem link : https://leetcode.com/problems/find-the-k-or-of-an-array/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

public class FindKthORArray {
    public static int findKOr(int[] nums, int k) {
        // array to count set bits at each position
        int[] bits = new int[32];
        int res = 0;

        // step 1: count set bits for each position across all numbers
        for(int num : nums){
            // index to track bit position (0 to 31)
            int i = 0;
            // iterate through each bit of the current number
            while(num > 0){
                // check if the least significant bit is 1
                if((num & 1) == 1){
                    // count the number of 1s in the ith position
                    bits[i] += 1;
                }
                // shift right to check the next bit
                num = num >> 1;
                // move to the next bit position
                i++;
            }
        }

        // step 2: calculate the result based on the counts of 1s
        int multiplier = 1;
        for (int j = 0; j < 32; j++) {
            // if there are k or more 1s at this bit position
            if (bits[j] >= k) {
                res += multiplier;
            }
            // update multiplier to next bit position (2^j)
            multiplier *= 2;
        }
        // return resultant value 'res'
        return res;
    }
    
    public static void main(String[] args) {
        // int[] nums = {7,12,9,8,9,15};
        // int k = 4;

        // int[] nums = {2,12,1,11,4,5};
        // int k = 6;

        int[] nums = {10,8,5,9,11,6,8};
        int k = 1;
        System.out.println(findKOr(nums, k));
    }
}