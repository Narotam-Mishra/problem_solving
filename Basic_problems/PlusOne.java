
// Problem link - https://leetcode.com/problems/plus-one/

package Basic_problems;

import java.util.Arrays;

public class PlusOne {
    public static  int[] plusOne1(int[] digits) {
        // Start from the end of the array (least significant digit)
        for(int i=digits.length-1; i>=0; i--){
            // If the current digit is less than 9, we can simply increment it by one
            if(digits[i] < 9){
                digits[i]++;
                // No further carry, we can return the result
                return digits;
            }

            // If the current digit is 9, set it to 0 and continue to the next significant digit
            digits[i] = 0;
        }

        // If we have processed all digits and still have a carry, create a new array
        int[] newDigits = new int[digits.length + 1];
        // The most significant digit is 1, others are 0 by default
        newDigits[0] = 1;
        return newDigits;
    }

    public static int[] plusOne(int[] digits) {
        // find size of digits
        int n = digits.length;

        // step 1 - iterate on digits from LSB and perform operation
        int i = n - 1;
        while(i >= 0){
            // check if digit is less than 9
            if(digits[i] < 9){
                digits[i] += 1;
                return digits;
            }

            // check if digit is 9 than add carry
            digits[i] = 0;
            i--;
        }

        // step 2 - corner case
        // if we have processed all digits and still have a carry, add that carry in start
        int[] res = new int[n+1];
        res[0] = 1;

        // step 3 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        int[] digits = {1, 2, 3};

        // int[] digits = {9, 9, 9};
        System.out.println(Arrays.toString(plusOne(digits)));
    }
}
