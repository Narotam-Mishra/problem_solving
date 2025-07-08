
// Problem link - https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits/description/

package Array_problems;

import java.util.Arrays;

public class MinimumSumOfFourDigitNumberAfterSplittingDigits {
    public static int minimumSum(int num) {
        // step 1 - extract all digits from the number
        String numStr = String.valueOf(num);
        
        // convert to string to easily access individual digits
        int[] digits = new int[4];
        for(int i=0; i<4; i++){
            digits[i] = numStr.charAt(i) - '0';
        }

        // step 3 - sort digits in ascending order, this will ensure minimum sum
        Arrays.sort(digits);

        // step 4 - build two 2-digit numbers
        int num1 = digits[0]*10 + digits[2];
        int num2 = digits[1]*10 + digits[3];

        // step 5 - return the sum
        return num1 + num2;
    }

    public static void main(String[] args) {
        // int num = 2932;

        int num = 4009;
        System.out.println(minimumSum(num));
    }
}