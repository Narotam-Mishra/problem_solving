
// problem link - https://leetcode.com/problems/maximum-number-of-words-you-can-type/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class MaximumNumberOfWordsYouCanType {
    public static int canBeTypedWords(String text, String brokenLetters) {
        // step 1 - change brokenLetters into brokenSet for better lookup
        Set<Character> brokenSet = new HashSet<>();
        for(char ch : brokenLetters.toCharArray()){
            brokenSet.add(ch);
        }

        // step 2 - split text into words
        String[] words = text.split(" ");
        int count = 0;

        // step 3 -iterate over each word
        for(String word : words){
            // assume that word is typeable
            boolean canType = true;

            // step 4 - check if the word contains any broken letters
            for(char ch : word.toCharArray()){
                if(brokenSet.contains(ch)){
                    canType = false;
                    break;
                }
            }

            // step 5 - if the word can be typed, increment count
            if(canType) count++;
        }

        // step 6 - return count
        return count;
    }

    public static void main(String[] args) {
        String text = "hello world", brokenLetters = "ad";
        
        // String text = "leet code", brokenLetters = "lt";
        
        // String text = "leet code", brokenLetters = "e";
        System.out.println(canBeTypedWords(text, brokenLetters));
    }
}