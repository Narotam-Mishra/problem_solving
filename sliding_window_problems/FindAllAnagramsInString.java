
// Problem link - https://leetcode.com/problems/find-all-anagrams-in-a-string/description/?envType=problem-list-v2&envId=string

package sliding_window_problems;

import java.util.*;

public class FindAllAnagramsInString {
    public static List<Integer> findAnagrams(String s, String p) {
        // step 1 - store result in `res` list
        List<Integer> res = new ArrayList<>();

        // check for base case:
        if(p.length() > s.length()){
            return res;
        }

        // step 2 - using fixed size frequency arrays to count frquencies
        int[] pCount = new int[26];
        int[] windowCount = new int[26];

        // step 3 - count pattern frquencies
        for(char ch : p.toCharArray()){
            pCount[ch - 'a']++;
        }

        // step 4 - calculate window size
        int windowSize = p.length();

        // step 5 - initialize first window
        for(int i=0; i<windowSize; i++){
            windowCount[s.charAt(i) - 'a']++;
        }

        // step 6 - check first window
        if(Arrays.equals(pCount, windowCount)){
            res.add(0);
        }

        // step 7 - slide through each the window
        for(int i=windowSize; i<s.length(); i++){
            // add character's frequency to window
            windowCount[s.charAt(i) - 'a']++;

            // remove character's frequency from window
            windowCount[s.charAt(i - windowSize) - 'a']--;

            // check current window
            if(Arrays.equals(pCount, windowCount)){
                res.add(i - windowSize + 1);
            }
        }

        // step 8 - return resultant list `res`
        return res;
    }

    public static void main(String[] args) {
        // String s = "cbaebabacd", p = "abc";

        String s = "abab", p = "ab";
        List<Integer> res = findAnagrams(s, p);
        System.out.println(res);
    }
}