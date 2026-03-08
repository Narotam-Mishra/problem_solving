
// Problem link - https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/description/

package sliding_window_problems;

public class MinimumNumberOfFlipsToMakeBinaryStringAlternating {
    public static int minFlips(String s) {
        int n = s.length();

        // store final result in `res`
        int res = Integer.MAX_VALUE;

        // keep track of flip required for both string s1 & s2
        int f1 = 0, f2 = 0;

        // step 1 - using sliding window approach
        int i = 0, j = 0;
        // expand window
        while (j < 2 * n) {
            // step 2 - find expected character for string s1 & s2
            char expCharS1 = (j % 2 == 1) ? '1' : '0';
            char expCharS2 = (j % 2 == 1) ? '0' : '1';

            // check for mismatch with pattern `s1`
            if (s.charAt(j%n) != expCharS1) {
                f1++;
            }

            // check for mismatch with pattern `s2`
            if (s.charAt(j%n) != expCharS2) {
                f2++;
            }

            // step 3 - check if window size exceed `n`
            // then shrink the window
            if (j - i + 1 > n) {
                expCharS1 = (i % 2 == 1) ? '1' : '0';
                expCharS2 = (i % 2 == 1) ? '0' : '1';

                // remove the effect of character leaving the window
                if (s.charAt(i%n) != expCharS1) {
                    f1--;
                }

                if (s.charAt(i%n) != expCharS2) {
                    f2--;
                }

                // move left pointer
                i++;
            }

            // step 4 - when window size is exactly n
            if (j - i + 1 == n) {
                // then update final result, `res`
                res = Math.min(res, Math.min(f1, f2));
            }

            // step 5 - move right pointer to expand window
            j++;
        }

        // step 6 - return final result, `res`
        return res;
    }

    public static void main(String[] args) {
        // String s = "111000";

        // String s = "010";

        String s = "1110";
        System.out.println(minFlips(s));
    }
}
