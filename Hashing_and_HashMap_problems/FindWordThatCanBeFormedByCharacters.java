
// Problem link : https://leetcode.com/problems/find-words-that-can-be-formed-by-characters/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package Hashing_and_HashMap_problems;

import java.util.*;

public class FindWordThatCanBeFormedByCharacters {
    public static int countCharacters(String[] words, String chars) {
        // step 1 : create a frequency map for `chars`
        Map<Character, Integer> charCount = new HashMap<>();
        for(char ch : chars.toCharArray()){
            charCount.put(ch, charCount.getOrDefault(ch, 0) + 1);
        }

        // to store the sum of lengths of "good" strings
        int totalLengthofGoodStr = 0;

        // step 2 : iterate through each word in `words`
        for(String word : words){
            // create a frequency map for the current word
            Map<Character, Integer> wordCount = new HashMap<>();
            for(char ch : word.toCharArray()){
                wordCount.put(ch, wordCount.getOrDefault(ch, 0) + 1);
            }

            // step 3 : check if the word can be formed using `chars`
            boolean canBeFormed = true;
            for(char ch : word.toCharArray()){
                if(!charCount.containsKey(ch) || wordCount.get(ch) > charCount.get(ch)){
                    // not enough characters available in `chars`
                    canBeFormed = false;
                    break;
                }
            }

            // step 4 : if the word is "good," add its length to `totalLengthofGoodStr`
            if(canBeFormed){
                totalLengthofGoodStr += word.length();
            }
        }
        return totalLengthofGoodStr;
    }

    public static void main(String[] args) {
        // String[] words = {"cat","bt","hat","tree"};
        // String chars = "atach";

        String[] words = {"hello","world","leetcode"};
        String chars = "welldonehoneyr";
        System.out.println(countCharacters(words, chars));
    }
}