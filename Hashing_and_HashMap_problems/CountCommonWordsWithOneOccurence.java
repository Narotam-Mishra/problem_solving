
// Problem link : https://leetcode.com/problems/count-common-words-with-one-occurrence/description/

package Hashing_and_HashMap_problems;

import java.util.*;

public class CountCommonWordsWithOneOccurence {
    public static int countWords(String[] words1, String[] words2) {
        // step 1: create a hashmap to store the frequency of each word
        Map<String, Integer> wordMap1 = new HashMap<>();
        Map<String, Integer> wordMap2 = new HashMap<>();

        // step 2 : count frequencies in words1
        for(String word : words1){
            wordMap1.put(word, wordMap1.getOrDefault(word, 0) + 1);
        }

        // step 3 : count frequencies in words2
        for(String word : words2){
            wordMap2.put(word, wordMap2.getOrDefault(word, 0) + 1);
        }

        // step 4 : compare counts and count matches
        int count = 0;
        for(String word : wordMap1.keySet()){
            if(wordMap1.get(word) == 1 && wordMap2.getOrDefault(word, 0) == 1){
                count++;
            }
        }

        // step 5 : return count
        return count;
    }

    public static void main(String[] args) {
        // String[] words1 = {"leetcode","is","amazing","as","is"};
        // String[] words2 = {"amazing","leetcode","is"};

        // String[] words1 = {"b","bb","bbb"};
        // String[] words2 = {"a","aa","aaa"};

        String[] words1 = {"a","ab"};
        String[] words2 = {"a","a","a","ab"};
        System.out.println(countWords(words1, words2));
    }
}
