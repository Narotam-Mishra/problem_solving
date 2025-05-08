
// Problem link - https://leetcode.com/problems/increasing-decreasing-string/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class IncreasingDecresingString {
    public static String sortString(String s) {
        // step 1 - use frequency array to count frquency of each character
        int[] freq = new int[26];
        Arrays.fill(freq, 0);

        // step 2 - count frequency of each character of `s`
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        // step 3 - store result in `res`
        StringBuilder res = new StringBuilder();
        int n = s.length();

        // step 4 - complete the operation as state in algorithm
        while (res.length() < n) {
            // follow step 1 to 3 of given algorithm
            for (int i = 0; i < 26; i++) {
                if (freq[i] > 0) {
                    res.append((char) (i + 'a'));
                    freq[i]--;
                }
            }

            // follow step 4 to 6 of given algorithm
            for (int i = 25; i >= 0; i--) {
                if (freq[i] > 0) {
                    res.append((char) (i + 'a'));
                    freq[i]--;
                }
            }
        }

        // step 5 - return result `res`
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "aaaabbbbcccc";

        String s = "rat";
        System.out.println(sortString(s));
    }
}