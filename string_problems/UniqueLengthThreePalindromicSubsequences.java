
// https://leetcode.com/problems/unique-length-3-palindromic-subsequences/description/?envType=daily-question&envId=2025-11-21

package string_problems;

import java.util.HashSet;

public class UniqueLengthThreePalindromicSubsequences {
    public static int countPalindromicSubsequence(String s) {
        int n = s.length();

        // step 1 - store first and last occurrences of each character
        int[][] idx = new int[26][2];
        for (int i = 0; i < 26; i++) {
            idx[i][0] = -1; // first
            idx[i][1] = -1; // last
        }

        for (int i = 0; i < n; i++) {
            int c = s.charAt(i) - 'a';
            if (idx[c][0] == -1) {
                idx[c][0] = i;
            }
            idx[c][1] = i;
        }

        int res = 0;

        // step 2 - for each character, check middle part
        for (int i = 0; i < 26; i++) {
            int left = idx[i][0];
            int right = idx[i][1];

            if (left == -1)
                continue;

            // step 3 - count unique chars between left and right
            HashSet<Character> set = new HashSet<>();
            for (int mid = left + 1; mid <= right - 1; mid++) {
                set.add(s.charAt(mid));
            }

            res += set.size();
        }

        return res;
    }

    public static void main(String[] args) {
        // String s = "aabca";

        // String s = "adc";

        String s = "bbcbaba";
        System.out.println(countPalindromicSubsequence(s));
    }
}
