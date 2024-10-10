
// Problem link : https://leetcode.com/problems/count-pairs-of-similar-strings/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class CountPairsOfSimilarStrings {
    public static int similarPairs(String[] words) {
        int pairsCnt = 0;
        Map<String, Integer> countMap = new HashMap<>();

        // iterate through each word in the words array
        for(String word : words){
            // normalize the word by sorting unique characters
            Set<Character> charSet = new TreeSet<>();
            for(char ch : word.toCharArray()){
                charSet.add(ch);
            }

            // convert the set back to a string
            StringBuilder sortedWord = new StringBuilder();
            for(char c : charSet){
                sortedWord.append(c);
            }
            String normalizedWord = sortedWord.toString();

            // if this normalized word has been seen before, 
            // increment pairs count
            if(countMap.containsKey(normalizedWord)){
                pairsCnt += countMap.get(normalizedWord);
            }

            // increment or set the count for this normalized form of the word
            countMap.put(normalizedWord, countMap.getOrDefault(normalizedWord, 0) + 1);
        }
        return pairsCnt;
    }
    
    public static void main(String[] args) {
        // String[] words = {"aba","aabb","abcd","bac","aabc"};

        String[] words = {"aabb","ab","ba"};
        System.out.println(similarPairs(words));
    }
}