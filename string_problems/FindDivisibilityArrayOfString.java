
// Problem link - https://leetcode.com/problems/find-the-divisibility-array-of-a-string/

package string_problems;

import java.util.*;

public class FindDivisibilityArrayOfString {
    public static int[] divisibilityArray(String word, int m) {
        // step 1 - use `div` array to store result
        int n = word.length();
        int[] div = new int[n];
        long currMod = 0;

        // step 2 - iterate on each digit of string `word`
        for(int i=0; i<n; i++){
            // step 3 - convert the current digit character to integer
            int digit = word.charAt(i) - '0';

            // step 4 - update the running modulo using rolling formula
            currMod = (currMod * 10 + digit) % m;

            // step 5 - if current number from word[0..i] is divisible by m, mark as 1
            div[i] = (currMod == 0) ? 1 : 0;
        }

        // step 6 - return resultant `div`
        return div;
    }

    public static void main(String[] args) {
        // String word = "998244353";
        // int m = 3;

        String word = "1010";
        int m = 10;
        System.out.println(Arrays.toString(divisibilityArray(word, m)));
    }
}