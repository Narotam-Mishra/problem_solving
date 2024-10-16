
// Problem link : https://leetcode.com/problems/longest-nice-substring/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class LongestNiceSubstring {

    private static boolean isNiceString(String str){
        // create set to store unique characters in the substring
        Set<Character> strSet = new HashSet<>();

        for(char ch : str.toCharArray()){
            strSet.add(ch);
        }

        // check if every character has both uppercase and lowercase present
        for(char ch : strSet){
            if(!strSet.contains(Character.toUpperCase(ch)) || !strSet.contains(Character.toLowerCase(ch))){
                return false;
            }
        }
        return true;
    }
    
    public static String longestNiceSubstring(String s) {
        // track maximum length of a "nice" substring
        int maxLen = 0;

        // store the longest "nice" substring
        String res = "";

        // iterate over all possible substrings of the string
        for (int i = 0; i < s.length(); i++) {
            for (int j = i + 1; j <= s.length(); j++) {
                // extract substring from index i to j-1
                String subStr = s.substring(i, j);

                // check if the current substring is "nice"
                if (isNiceString(subStr) && subStr.length() > maxLen) {
                    // ppdate maxLength if a longer "nice" substring is found
                    maxLen = subStr.length();

                    // store the new longest "nice" substring
                    res = subStr;
                }
            }
        }
        return res;
    }

    public static void main(String[] args) {
        String str = "YazaAay";

        // String str = "Bb";
        System.out.println(longestNiceSubstring(str));
    }
}