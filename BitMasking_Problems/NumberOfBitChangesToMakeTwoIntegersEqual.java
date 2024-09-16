
// Problem link : https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class NumberOfBitChangesToMakeTwoIntegersEqual {
    
    private static int countSetBits(int num){
        int setBits = 0;
        // loop through each bit in num
        while(num > 0){
            // check if the least significant bit is 1
            setBits += num & 1;
            // shift the bits of num to the right to check the next bit
            num = num >> 1;
        }
        return setBits;
    }
    
    public static int minChanges(int n, int k) {
        // edge case: if k has any 1s in positions where n has 0s, return -1
        if ((n & k) != k) {
            return -1;
        }

        // count the number of 1s in n and k
        int countOnesN = countSetBits(n);
        int countOnesK = countSetBits(k);

        // if n has fewer 1s than k, it's impossible to change n to k
        if(countOnesN < countOnesK){
            return - 1;
        }

        // calculate the XOR of n and k to identify differing bits
        int xorVal = n ^ k;

        // count the number of bits in the XOR value where n and k differ 
        // (this includes both 1->0 and 0->1 changes)
        int differBits = countSetBits(xorVal);

        // the minimum changes needed are the number of differing bits
        return differBits;
    }

    public static void main(String[] args) {
        // int n = 13, k = 4;

        // int n = 21, k = 21;

        int n = 14, k = 13;
        System.out.println(minChanges(n, k));
    }
}