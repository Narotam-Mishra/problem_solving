
// Problem link - https://leetcode.com/problems/permutation-in-string/description/

package Hashing_and_HashMap_problems;

import java.util.*;

public class PermutationInString {
    public static boolean checkInclusion(String s1, String s2) {
        // edge case: if s1 is longer than s2, no permutation can exist
        if(s1.length() > s2.length()){
            return false;
        }

        // step 1 - using fixed size frequency arrays to count frquencies
        int[] pCount = new int[26];
        int[] windowCount = new int[26];

        // step 2 - count pattern `s1` frquencies
        for(char ch : s1.toCharArray()){
            pCount[ch - 'a']++;
        }

        // step 3 - calculate window size
        int windowSize = s1.length();

        // step 4 - initialize first window
        for(int i=0; i<windowSize; i++){
            windowCount[s2.charAt(i) - 'a']++;
        }

        // step 5 - check first window
        if(Arrays.equals(pCount, windowCount)){
            return true;
        }

        // step 6 - slide through each the window
        for(int i=windowSize; i<s2.length(); i++){
            // add character's frequency to window
            windowCount[s2.charAt(i) - 'a']++;

            // remove character's frequency from window
            windowCount[s2.charAt(i - windowSize) - 'a']--;

            // check current window
            if(Arrays.equals(pCount, windowCount)){
                return true;
            }
        }

        // step 7 - return false as sliding through window is completed
        return false;
    }

    public static void main(String[] args) {
        // String s1 = "ab", s2 = "eidbaooo";

        String s1 = "ab", s2 = "eidboaoo";
        System.out.println(checkInclusion(s1, s2));
    }
}
