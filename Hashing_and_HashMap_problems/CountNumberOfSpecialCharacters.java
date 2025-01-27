
// Problem link : https://leetcode.com/problems/count-the-number-of-special-characters-i/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class CountNumberOfSpecialCharacters {
    public static int numberOfSpecialChars(String word) {
        // step 1 - initialize two sets to store lowercase and uppercase letters
        // to store all uppercase letters
        Set<Character> upperSet = new HashSet<>();

        // to store all lowercase letters
        Set<Character> lowerSet = new HashSet<>();

        // step 2 - populate the sets by iterating through the string `word`
        for(char ch : word.toCharArray()){
            if(ch >= 'a' && ch <= 'z'){
                lowerSet.add(ch);
            }else if(ch >= 'A' && ch <= 'Z'){
                upperSet.add(ch);
            }
        }

        // step 3 - count special letters
        int specialCharCount = 0;
        for(char ch : lowerSet){
            // convert lowercase to uppercase
            char upperCh = Character.toUpperCase(ch);
            if(upperSet.contains(upperCh)){
                specialCharCount++;
            }
        }

        // step 4 - return the total count of special letters
        return specialCharCount;
    }

    public static void main(String[] args) {
        // String word = "aaAbcBC";

        // String word = "abc";

        String word = "abBCab";
        System.out.println(numberOfSpecialChars(word));
    }
}