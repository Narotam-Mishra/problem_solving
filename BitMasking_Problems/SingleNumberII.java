
// Problem link : https://leetcode.com/problems/single-number-ii/description/

package BitMasking_Problems;

public class SingleNumberII {
    public static int singleNumber(int[] nums) {
        int res = 0;
        int sum, mask;

        // iterate through each 32-bit positions
        for(int i=0; i<32; i++){
            // sum will keep track of the count of 1s at the i-th bit position
            sum = 0;
            // create mask where i-th bit is set
            mask = (1 << i);

            // iterate through all numbers in array
            for(int num : nums){
                // check if the i-th bit is set in the current number 'num'
                if((num & mask) != 0){
                    // increment sum
                    sum++;
                }
            }

            // after couting, check if the sum is not divisible by 3
            // it means that the unique number has the i-th bit set
            if(sum % 3 != 0){
                // set the i-th bit in the result
                res = res | mask;
            }
        }
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {2, 2, 3, 2};

        int[] nums = {0,1,0,1,0,1,99};
        System.out.println(singleNumber(nums));
    }
}
