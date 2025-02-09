
// Problem link : https://leetcode.com/problems/isomorphic-strings/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class IsomorphicStrings {
    public static boolean isIsomorphic1(String s, String t) {
        // edge case: if length of both strings `s` & `t` are different
        // then they are not isomorphic, so return false right away
        if(s.length() != t.length()){
            return false;
        }

        // step 1 - create two maps to store the mapping from s to t and t to s
        Map<Character, Character> sTotMap = new HashMap<>();
        Map<Character, Character> tTosMap = new HashMap<>();

        // step 2 - iterate through each character of the strings
        // and check for isomorphic behaviour
        for(int i=0; i<s.length(); i++){
            char charS = s.charAt(i);
            char charT = t.charAt(i);

            // check if the current character in `s` is already mapped
            if(sTotMap.containsKey(charS)){
                // if it is already mapped, it should map to the corresponding character in `t`
                if(sTotMap.get(charS) != charT){
                    // otherwise return false
                    return false;
                }
            }else{
                // if not mapped already, add the mapping from `s` to `t`
                sTotMap.put(charS, charT);
            }

            // check if the current character in `t` is already mapped
            if(tTosMap.containsKey(charT)){
                // if it is already mapped, it should map to the corresponding character in `s`
                if(tTosMap.get(charT) != charS){
                    // otherwise return false
                    return false;
                }
            }else{
                // if not mapped already, add the mapping from `t` to `s`
                tTosMap.put(charT, charS);
            }
        }

        // step 3 - if all characters are mapped correctly, the strings are isomorphic and return true
        return true;
    }

    public static boolean isIsomorphic(String s, String t) {
        // edge case: if the lengths of the two strings are different, they cannot be isomorphic
        if (s.length() != t.length()) {
            return false;
        }

        // step 1 - create a map to store the mapping from s to t
        Map<Character, Character> charMap = new HashMap<>();

        // step 2 - create a set to track characters in t that have already been mapped
        Set<Character> usedChars = new HashSet<>();

        // step 3 - iterate through each character of the strings
        for (int i = 0; i < s.length(); i++) {
            char charS = s.charAt(i);
            char charT = t.charAt(i);

            // if the character in s is already mapped
            if (charMap.containsKey(charS)) {
                // check if it maps to the corresponding character in t
                if (charMap.get(charS) != charT) {
                    return false;
                }
            } else {
                // if the character in t has already been used, it cannot be mapped again
                if (usedChars.contains(charT)) {
                    return false;
                }
                // add the mapping from s to t
                charMap.put(charS, charT);
                // mark the character in t as used
                usedChars.add(charT);
            }
        }

        // step 4 - if all characters are mapped correctly, the strings are isomorphic
        return true;
    }

    public static void main(String[] args) {
        String s = "egg", t = "add";

        // String s = "foo", t = "bar";

        // String s = "paper", t = "title";
        System.out.println(isIsomorphic(s, t));
    }
}
