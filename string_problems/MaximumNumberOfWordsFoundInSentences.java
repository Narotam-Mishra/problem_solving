
// Problem link - https://leetcode.com/problems/maximum-number-of-words-found-in-sentences/?envType=problem-list-v2&envId=string

package string_problems;

public class MaximumNumberOfWordsFoundInSentences {
    public static int mostWordsFound(String[] sentences) {
        // step 1 - initialize variable to count maximum number of words
        int maxWords = 0;

        // step 2 - iterate on each sentence of `sentences`
        for(String sentence : sentences){
            // step 3 - trim, split by whitespace, and count words
            String[] words = sentence.trim().split("\\s+");

            // step 4 - update maximum number of words
            maxWords = Math.max(maxWords, words.length);
        }

        // step 5 - return maximum number of words `maxWords`
        return maxWords;
    }

    public static void main(String[] args) {
        // String[] sentences = {"alice and bob love leetcode", "i think so too", "this is great thanks very much"};

        String[] sentences = {"please wait", "continue to fight", "continue to win"};
        System.out.println(mostWordsFound(sentences));
    }
}