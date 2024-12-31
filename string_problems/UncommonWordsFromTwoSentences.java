
// Problem link : https://leetcode.com/problems/uncommon-words-from-two-sentences/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class UncommonWordsFromTwoSentences {
    public static String[] uncommonFromSentences(String s1, String s2) {
        // step 1 - split the sentences into words and combine them
        String[] words = (s1 + " " + s2).split(" ");

        // step 2 - create a frequency map to count occurrences of each word
        Map<String, Integer> wordMap = new HashMap<>();
        for(String word : words){
            wordMap.put(word, wordMap.getOrDefault(word, 0) + 1);
        }

        // step 3 - find uncommon words (words with a frequency of exactly 1)
        List<String> res = new ArrayList<>();
        for(Map.Entry<String, Integer> entry : wordMap.entrySet()){
            // only add words that appear exactly once
            if(entry.getValue() == 1){
                res.add(entry.getKey());
            }
        }

        // step 4 - return the result array list 'res'
        return res.toArray(new String[0]);
    }

    public static void main(String[] args) {
        // String s1 = "this apple is sweet", s2 = "this apple is sour";

        String s1 = "apple apple", s2 = "banana";
        String[] res = uncommonFromSentences(s1, s2);
        System.out.println(Arrays.asList(res));
    }
}
