
// Problem link : https://leetcode.com/problems/largest-substring-between-two-equal-characters/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

import java.util.*;

public class LargestSubstringBetweenTwoEqualCharacters {
    public static int maxLengthBetweenEqualCharacters(String s) {
        // step 1 - initialize a map to store the first occurrence of each character
        Map<Character, Integer> map = new HashMap<>();

        // step 2 - variable to store the maximum length of substring found
        int maxLength = -1;

        // step 3 - iterate through the string and find largest sbstring length
        for(int i=0; i<s.length(); i++) {
            char curChar = s.charAt(i);

            // check if the current character has been seen before
            if(map.containsKey(curChar)){
                // calculate the length of the largest substring between the two occurrences
                int lengthBetween = i - map.get(curChar) - 1;

                // update the maximum substring length
                maxLength = Math.max(maxLength, lengthBetween);
            }else{
                // store the first occurrence index of the character
                map.put(curChar, i);
            }
        }

        // step 4 - return the maximum length found, or -1 if no such substring exists
        return maxLength;
    }

    public static void main(String[] args) {
        // String str = "aa";

        // String str = "abca";

        String str = "cbzxy";
        System.out.println(maxLengthBetweenEqualCharacters(str));
    }
}