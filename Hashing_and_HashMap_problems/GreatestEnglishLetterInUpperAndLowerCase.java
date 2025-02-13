
// Problem link - https://leetcode.com/problems/greatest-english-letter-in-upper-and-lower-case/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class GreatestEnglishLetterInUpperAndLowerCase {
    public static String greatestLetter(String s) {
        // step 1 - create a set to store all characters in the string
        Set<Character> charSet = new HashSet<>();
        for(char ch : s.toCharArray()){
            charSet.add(ch);
        }

        // step 2 - iterate from 'z' to 'a' and check if both lowercase and uppercase exist
        for(char ch = 'z'; ch >= 'a'; ch--){
            if(charSet.contains(ch) && charSet.contains(Character.toUpperCase(ch))){
                return String.valueOf(Character.toUpperCase(ch));
            }
        }

        // step 3 - if no valid letter is found, return an empty string
        return "";
    }

    public static void main(String[] args) {
        // String s = "lEeTcOdE";

        // String s = "arRAzFif";

        String s = "AbCdEfGhIjK";
        System.out.println(greatestLetter(s));
    }
}