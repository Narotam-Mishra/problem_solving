
// Problem link - https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/?envType=problem-list-v2&envId=number-theory

package NumberTheory_Problems;

public class CheckIfDigitsAreEqualInStringAfterOperationI {
    public static boolean hasSameDigits(String s) {
        // step 1 - convert the string into an array of digits
        int[] digits = new int[s.length()];

        for(int i=0; i<s.length(); i++){
            digits[i] = s.charAt(i) - '0';
        }

        // step 2 - Keep reducing the array until only two digits remain
        int n = digits.length;
        while(n > 2){
            // step 3 - compute new digits based on adjacent pairs
            for(int i=0; i<s.length()-1; i++){
                digits[i] = (digits[i] + digits[i+1]) % 10;
            }

            // step 4 - reduce the effective length of the array
            n--;
        }

        // step 5 - check if the final two digits are equal or not
        return digits[0] == digits[1];
    }

    public static void main(String[] args) {
        // String s = "3902";

        String s = "34789";
        System.out.println(hasSameDigits(s));
    }
}