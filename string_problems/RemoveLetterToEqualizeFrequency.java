
// Problem link - https://leetcode.com/problems/remove-letter-to-equalize-frequency/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class RemoveLetterToEqualizeFrequency {
    public static boolean equalFrequency(String word) {
        // step 1 - store frequency of each character in frequency array `frq`
        int[] frq = new int[26];
        for (char ch : word.toCharArray()) {
            frq[ch - 'a']++;
        }

        // step 2 - try removing each frequency once
        for (int i = 0; i < 26; i++) {
            // skip 0-frequency
            if (frq[i] == 0) {
                continue;
            }

            // step 3 - remove frequency once
            frq[i]--;

            // step 4 - collect non-zero frequency once
            Set<Integer> frqSet = new HashSet<>();
            for (int f : frq) {
                if (f > 0) {
                    frqSet.add(f);
                }
            }

            // step 5 - check if all frquencies are same, then return true immediately
            if (frqSet.size() == 1)
                return true;

            // step 6 - restore original frquency
            frq[i]++;
        }

        // step 7 - return false if conditions not met
        return false;
    }

    public static void main(String[] args) {
        // String s = "abcc";

        String s = "aazz";
        System.out.println(equalFrequency(s));
    }
}