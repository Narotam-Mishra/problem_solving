
// Problem link - https://leetcode.com/problems/count-vowel-substrings-of-a-string/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CountVowelSubstringOfString {
    public static int countVowelSubstrings(String word) {
        // step 1 - create map to store the last occurrence index of each vowel
        Map<Character, Integer> map = new HashMap<>();
        map.put('a', -1);
        map.put('e', -1);
        map.put('i', -1);
        map.put('o', -1);
        map.put('u', -1);

        // counter for valid vowel substrings
        // left pointer of window
        int count = 0, left = 0;

        // step 2 - iterate current input string `word`
        for (int i = 0; i < word.length(); i++) {
            if (i < word.length() && map.containsKey(word.charAt(i))) {
                // step 3 - update the last occurrence index of the current vowel
                map.put(word.charAt(i), i);

                // step 4 - find the minimum index among the last occurrences of all vowels
                int minIndex = Collections.min(map.values());

                // step 5 - if all vowels are present in the current window,
                if (minIndex >= 0 && minIndex >= left) {
                    // count valid substrings
                    count += (minIndex - left) + 1;
                }
            } else {
                // if a non-vowel is encountered, reset the window
                left = i + 1;
            }
        }

        // step 6 - return count
        return count;
    }

    public static void main(String[] args){
        // String word = "aeiouu";

        // String word = "unicornarihan";

        String word = "cuaieuouac";
        System.out.println(countVowelSubstrings(word));
    }
}