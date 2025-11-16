
// Problem link - https://leetcode.com/problems/number-of-substrings-with-only-1s/?envType=daily-question&envId=2025-11-16

package NumberTheory_Problems;

public class NumberOfSubstringsWithOnlyOnes {
    public static  int numSub1(String s) {
        final int mod = 1000000007;

        // store final result in res
        long res = 0;

        // step 1 - iterate on each character of s
        int count = 0;
        for (char ch : s.toCharArray()) {
            // step 2 - count ones in current subsring
            if (ch == '1') {
                count++;
            } else {
                // step 3 - calculate number of substring possible
                res = (res + ((long)count * (count + 1)) / 2) % mod;

                // step 4 - reset count of ones to 0 as streak of 1s break
                count = 0;
            }
        }

        // step 5 - calculate number of substring for last substring if exist
        if (count > 0) {
            res = (int)(res + ((long)count * (count + 1)) / 2) % mod;
        }

        // step 6 - return final result, res
        return (int)res;
    }

    public static int numSub(String s) {
        final int mod = 1_000_000_007;

        // store final result in res
        long res = 0;

        // step 1 - iterate on each substring of s
        int c = 0;
        for (char ch : s.toCharArray()) {
            // step 2 - count ones in each substring
            if (ch == '1') {
                c++;

                // calculate number of substring with 1s only
                res = (res + c) % mod;
            } else {
                // step 3 - reset count, c to 0 as 1s streaks break
                c = 0;
            }
        }

        // step 4 - return final result, res
        return (int)res;
    }

    public static void main(String[] args) {
        String s = "0110111";

        // String s = "101";

        // String s = "111111";
        System.out.println(numSub(s));
    }
}
