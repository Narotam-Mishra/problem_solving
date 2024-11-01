
// Problem link : https://leetcode.com/problems/word-pattern/description/

package Hashing_and_HashMap_problems;

import java.util.*;

public class WordPattern {
    public static boolean wordPattern(String pattern, String s) {
        // split the string `s` into words
        String[] words = s.split(" ");

        // corner case: if pattern length and words length don't match, immediately
        // return false
        if (pattern.length() != words.length)
            return false;

        // maps to keep track of pattern to word and word to pattern mappings
        Map<Character, String> patternToWord = new HashMap<>();
        Map<String, Character> wordToPattern = new HashMap<>();

        // iterate through each letter in the pattern and corresponding word in words
        for (int i = 0; i < pattern.length(); i++) {
            char letter = pattern.charAt(i);
            String word = words[i];

            // check if the letter in the pattern already maps to a different word
            if (patternToWord.containsKey(letter)) {
                if (!patternToWord.get(letter).equals(word)) {
                    // conflict: letter is mapped to a different word
                    return false;
                }
            } else {
                // map the letter to the current word
                patternToWord.put(letter, word);
            }

            // check if the word is already mapped to a different letter in the pattern
            if (wordToPattern.containsKey(word)) {
                if (!wordToPattern.get(word).equals(letter)) {
                    // conflict: word is mapped to a different letter
                    return false;
                }
            } else {
                // map the word to the current letter
                wordToPattern.put(word, letter);
            }
        }
        // if all mappings are consistent, return true
        return true;
    }

    public static void main(String[] args) {
        // String pattern = "abba";
        // String s = "dog cat cat dog";

        // String pattern = "abba";
        // String s = "dog cat cat fish";

        String pattern = "abba";
        String s = "dog constructor constructor dog";
        System.out.println(wordPattern(pattern, s));
    }
}