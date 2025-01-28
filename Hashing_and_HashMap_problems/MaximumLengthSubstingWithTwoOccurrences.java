
// Problem link : https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class MaximumLengthSubstingWithTwoOccurrences {
    public static int maximumLengthSubstring(String s) {
        // step 1 - initialize variables
        int maxLen = 0;
        Map<Character, Integer> charMap = new HashMap<>();
        int start = 0;

        // step 2 - Iterate through each character in the sliding window
        for (int end = 0; end < s.length(); end++) {
            // add current character to our count
            char curChar = s.charAt(end);
            charMap.put(curChar, charMap.getOrDefault(curChar, 0) + 1);

            // step 3 - while window becomes invalid (any char appears more than twice)
            // shrink window from start
            while (charMap.get(curChar) > 2) {
                char startChar = s.charAt(start);
                charMap.put(startChar, charMap.get(startChar) - 1);
                start++;
            }

            // step 4 - update maximum length of substring
            maxLen = Math.max(maxLen, end - start + 1);
        }

        // step 5 - return maximum length of substring
        return maxLen;
    }

    public static void main(String[] args) {
        // String s = "bcbbbcba";

        String s = "aaaa";
        System.out.println(maximumLengthSubstring(s));
    }
}