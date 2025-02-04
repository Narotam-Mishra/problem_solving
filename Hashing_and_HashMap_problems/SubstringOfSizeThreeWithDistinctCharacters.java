
// Problem link : https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class SubstringOfSizeThreeWithDistinctCharacters {
    public static int countGoodSubstrings1(String s) {
        // edge case:
        if(s.length() < 3) return 0;

        // step 1 - initialize variable `count` to tack good substrings
        int count = 0;

        // step 2 - iterate through the string, extracting substrings of length 3
        for(int i=0; i<=s.length() - 3; i++){
            // extract a substring of length 3
            String subString = s.substring(i, i+3);

            // step 3 - convert the substring to a Set to check for uniqueness
            Set<Character> uniqueChars = new HashSet<>();
            for(char ch : subString.toCharArray()){
                uniqueChars.add(ch);
            }
            
            // step 4 - if the set size is 3, all characters are unique
            if(uniqueChars.size() == 3){
                count++;
            }
        }

        // step 5 - return the count of good substrings
        return count;
    }

    public static int countGoodSubstrings(String s) {
        // edge case:
        if(s.length() < 3) return 0;
        
        // step 1 - initialize variable `count` to tack good substrings
        int count = 0;

        // step 2 - iterate through the string, 
        for (int i = 0; i < s.length() - 2; i++) {
            // extracting substrings of length 3
            // and check all three characters are unique
            if (s.charAt(i) != s.charAt(i + 1) &&
                s.charAt(i) != s.charAt(i + 2) &&
                s.charAt(i + 1) != s.charAt(i + 2)) {
                // increment count if above condition met
                count++;
            }
        }

        // step 3 - return the counter `count`
        return count;
    }

    public static void main(String[] args) {
        // String s = "xyzzaz";

        String s = "aababcabc";
        System.out.println(countGoodSubstrings(s));
    }
}