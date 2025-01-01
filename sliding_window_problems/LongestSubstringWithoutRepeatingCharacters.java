
// Problem link - https://leetcode.com/problems/longest-substring-without-repeating-characters/

package sliding_window_problems;

import java.util.*;

public class LongestSubstringWithoutRepeatingCharacters {
    public static int lengthOfLongestSubstring1(String s) {
        // step 1 - initialize a Set to store unique characters in the current window
        Set<Character> set = new HashSet<>();
        
        // step 2 - initialize two pointers `start` & `end` for the sliding window
        int start = 0;
        // use `maxLength`to keep track of the maximum length of the substring
        int maxLength = 0;

        // step 3 - iterate over the string using `end` pointer
        for (int end = 0; end < s.length(); end++) {
            // if the character at 'end' is already in the set, shrink the window
            while (set.contains(s.charAt(end))) {
                // remove the character at `start` from the set and move `start` forward
                set.remove(s.charAt(start));
                start++;
            }

            // add the current character at 'end' to the set
            set.add(s.charAt(end));
            
            // update maximum length of substring
            maxLength = Math.max(maxLength, end - start + 1);
        }

        // step 4 - return the maximum length found
        return maxLength;
    }

    public static int lengthOfLongestSubstring(String s) {
        // step 1 - initialize a Map to store the characters and their most recent indices
        Map<String, Integer> map = new HashMap<>();

        // step 2 - initialize two pointers `start` & `end` for the sliding window
        int start = 0;
        int maxLength = 0;

        // step 3 - iterate over the string using `end` pointer
        for(int end = 0; end < s.length(); end++){
            String currentChar = String.valueOf(s.charAt(end));

            // if the character is already in the map, move the `start` pointer
            if(map.containsKey(currentChar)){
                // move the `start` pointer to the right of the previous index of the current character
                start = Math.max(start, map.get(currentChar) + 1);
            }

            // update the most recent index of the current character
            map.put(currentChar, end);

            // update maximum length of substring
            maxLength = Math.max(maxLength, end - start + 1);
        }

        // step 4: return the maximum length found
        return maxLength;
    }

    public static void main(String[] args) {
        // String s = "abcabcbb";

        // String s = "bbbbb";

        String s = "pwwkew";
        System.out.println(lengthOfLongestSubstring(s));
    }
}