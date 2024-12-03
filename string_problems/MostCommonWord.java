
// Problem link : https://leetcode.com/problems/most-common-word/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

import java.util.*;

public class MostCommonWord {
    public static String mostCommonWord(String paragraph, String[] banned) {
        // step 1 : normalize the paragraph
        String normalizedPara = paragraph.toLowerCase().replaceAll("[^a-z0-9\\s]", " ");

        // step 2 : split the paragraph into words by removing extra spaces
        String[] words = normalizedPara.split("\\s+");

        // step 3 : convert banned words to a Set for efficient lookup
        Set<String> bannedWords = new HashSet<>(Arrays.asList(banned));

        // step 4 : count the frequency of non-banned words
        Map<String, Integer> wordCount = new HashMap<>();
        for(String word : words){
            // ignore empty strings and banned words
            if(!word.isEmpty() && !bannedWords.contains(word)){
                wordCount.put(word, wordCount.getOrDefault(word, 0) + 1);
            }
        }

        // step 5 : find the most frequent word
        String mostFrqWord = "";
        int maxCount = 0;
        for(Map.Entry<String, Integer> entry : wordCount.entrySet()){
            if(entry.getValue() > maxCount){
                mostFrqWord = entry.getKey();
                maxCount = entry.getValue();
            }
        }
        return mostFrqWord;
    }

    public static void main(String[] args) {
        String paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.";
        String[] banned = {"hit"};

        // String paragraph = "a.";
        // String[] banned = {};
        System.out.println(mostCommonWord(paragraph, banned));
    }
}