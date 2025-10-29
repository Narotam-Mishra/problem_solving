
// Problem link - https://leetcode.com/problems/smallest-number-with-all-set-bits/description/?envType=daily-question&envId=2025-10-29

package BitMasking_Problems;

public class SmallestNumberWithAllSetBits {
    private static boolean checkAllBitSet(int num){
        return (num & num+1) == 0;
    }

    public static int smallestNumber1(int n) {
        // step 1 - take input `n` as first potential answer
        int x = n;

        // step 2 - check if all bit of `res` are set or not
        while (!checkAllBitSet(x)) {
            // step 3 - increment the number if all bit are not set
            x++;
        }

        // step 4 - return the smallest number whose all bits are set
        return x;
    }

    public static int smallestNumber2(int n) {
        // step 1 - start from `1` as potential answer
        int x = 1;

        // step 2 - move to next number till it is less than `n`
        while (x < n) {
            // step 3 - increment the number for next potentail answer
            // 2 ^ x + 1
            x = 2 * x + 1;
        }

        // step 4 - return the smallest number whose all bits are set
        return x;
    }

    public static int smallestNumber(int n) {
        // step 1 - find number of bits required to represent input `n`
        // we can find this using log2(n) + 1 since log2 gives the highest set
        // bit position.
        int bitRequired = (int)(Math.log(n) / Math.log(2)) + 1;

        // step 2 - construct the smallest number with all bits set for that bit
        // length. (1 << bitRequired) gives 2^bitRequired, so subtracting 1 sets
        // all lower bits to 1.
        return (1 << bitRequired) - 1;
    }
    
    public static void main(String[] args) {
        int n = 5;

        // int n = 10;

        // int n = 3;
        System.out.println(smallestNumber(n));
    }
}