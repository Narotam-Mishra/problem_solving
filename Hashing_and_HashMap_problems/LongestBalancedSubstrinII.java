
// Problem link - https://leetcode.com/problems/longest-balanced-substring-ii/?envType=daily-question&envId=2026-02-13

package Hashing_and_HashMap_problems;

import java.util.*;

public class LongestBalancedSubstrinII {
    private static int solve(String s, char ch1, char ch2) {
        int n = s.length();

        // diffMap stores the first occurrence index of each (cnt1 - cnt2) difference value.
        // Key insight: if the same difference appears at index i and later at index j,
        // then the substring s[i+1..j] has equal counts of ch1 and ch2.
        HashMap<Integer, Integer> diffMap = new HashMap<>();

        int maxLen = 0;
        int cnt1 = 0, cnt2 = 0;

        for (int i = 0; i < n; i++) {

            // If current character is neither ch1 nor ch2,
            // it acts as a wall — reset everything to start a fresh window.
            if (s.charAt(i) != ch1 && s.charAt(i) != ch2) {
                diffMap.clear();
                cnt1 = 0;
                cnt2 = 0;
                continue;
            }

            // Count occurrences of ch1 and ch2 so far in the current window.
            if (s.charAt(i) == ch1) cnt1++;
            if (s.charAt(i) == ch2) cnt2++;

            // If counts are equal, the entire current window (from start) is balanced.
            if (cnt1 == cnt2) {
                maxLen = Math.max(maxLen, cnt1 + cnt2);
            }

            // Use prefix difference trick:
            // diff = cnt1 - cnt2 captures the "imbalance" seen so far.
            // If this same diff was seen before at index k, then
            // between k+1 and i the counts of ch1 and ch2 are equal.
            int diff = cnt1 - cnt2;
            if (diffMap.containsKey(diff)) {
                maxLen = Math.max(maxLen, i - diffMap.get(diff));
            } else {
                // Only store the first occurrence to maximize future window lengths.
                diffMap.put(diff, i);
            }
        }
        return maxLen;
    }

    public static int longestBalanced(String s) {
        int n = s.length();

        int maxLen = 0;

        // ---------------------------
        // Case 1: Only one distinct character
        // Longest continuous run
        // ---------------------------
        int cnt = 1;  // count for current run

        for (int i = 1; i < n; i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                // Extend current run
                cnt++;
            } else {
                // Update max length
                maxLen = Math.max(maxLen, cnt);
                cnt = 1; // Reset count
            }
        }

        // Check last run
        maxLen = Math.max(maxLen, cnt);

        // ---------------------------
        // Case 2: Exactly 2 distinct characters
        // ---------------------------
        maxLen = Math.max(maxLen, solve(s, 'a', 'b'));
        maxLen = Math.max(maxLen, solve(s, 'a', 'c'));
        maxLen = Math.max(maxLen, solve(s, 'b', 'c'));

        // ---------------------------
        // Case 3: All three characters balanced
        // ---------------------------

        int cntA = 0, cntB = 0, cntC = 0;

        // Map to store imbalance state:
        // key = (cntA - cntB) + "_" + (cntA - cntC)
        // value = first index where this state appeared
        Map<String, Integer> diffMap = new HashMap<>();

        for (int i = 0; i < n; i++) {

            char current = s.charAt(i);

            if (current == 'a') cntA++;
            if (current == 'b') cntB++;
            if (current == 'c') cntC++;

            // If all three counts equal → prefix is balanced
            if (cntA == cntB && cntA == cntC) {
                maxLen = Math.max(maxLen, cntA + cntB + cntC);
            }

            // Encode imbalance state
            int diffAB = cntA - cntB;
            int diffAC = cntA - cntC;

            String key = diffAB + "_" + diffAC;

            if (diffMap.containsKey(key)) {
                maxLen = Math.max(maxLen, i - diffMap.get(key));
            } else {
                diffMap.put(key, i);
            }
        }

        // Final answer
        return maxLen;
    }

    public static void main(String[] args) {
        // String s = "abbac";

        // String s = "aabcc";

        String s = "aba";
        System.out.println(longestBalanced(s));
    }
}
