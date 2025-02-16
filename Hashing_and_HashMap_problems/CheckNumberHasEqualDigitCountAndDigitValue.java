
// Problem link - https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

public class CheckNumberHasEqualDigitCountAndDigitValue {
    public static boolean digitCount(String num) {
        // step 1 - create frquency array map 
        int[] freq = new int[10];
        int n = num.length();
        for(int i=0; i<n; i++){
            freq[num.charAt(i) - '0']++;
        }

        // step 2 -  check if each index i occurs num[i] times
        for(int i=0; i<n; i++){
            if(freq[i] != (num.charAt(i) - '0')){
                // found mismatch, so return false
                return false;
            }
        }

        // step 3 - all checks passed
        return true;
    }

    public static void main(String[] args) {
        // String num = "1210";

        String num = "030";
        System.out.println(digitCount(num));
    }
}