
// Problem link :- https://leetcode.com/problems/total-hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class TotalhammingDistance {
    public static int totalHammingDistance(int[] nums) {
        int n = nums.length, thdSum = 0;

        // iterate over each bit position (0 to 31)
        for(int i=0; i<32; i++){
            int ones = 0;

            // count how many numbers have a 1 at bit position i
            for(int num : nums){
                ones += (num >> i) & 1;
            }

            // number of zeros at this bit position
            int zeroes = n - ones;

            // contribution of this bit position to total Hamming distance
            thdSum += (ones * zeroes);
        }

        // return total hamming distance sum (thdSum)
        return thdSum;
    }

    public static void main(String[] args) {
        // int[] nums = {4, 14, 2};

        int[] nums = {4, 14, 4};
        System.out.println(totalHammingDistance(nums));
    }
}