
// Problem link : https://leetcode.com/problems/sorting-the-sentence/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

// utility class to store the word and its position
class Pair{
    String word;
    int position;
    Pair(String word, int position){
        this.word = word;
        this.position = position;
    }
}

public class SortingTheSentence {
    public static String sortSentence(String s) {
        // step 1 - split the sentence into words
        String[] words = s.split(" ");

        // create a list to store words with their positions
        List<Pair> wordList = new ArrayList<>();

        // step 2 - find word and its position
        for(String word : words){
            // extract the position from the last character
            int position = word.charAt(word.length()-1) - '0';
            
            // extract the actual word by removing the last character
            String actualWord = word.substring(0, word.length()-1);
            
            // add the word and its position to the list
            wordList.add(new Pair(actualWord, position));
        }

        // step 3 - sort the words based on their position
        Collections.sort(wordList, new Comparator<Pair>(){
            public int compare(Pair p1, Pair p2){
                return p1.position - p2.position;
            }
        });

        // step 4 - recreate the final sentence
        StringBuilder sortedSentence = new StringBuilder();
        for(Pair pair : wordList){
            sortedSentence.append(pair.word).append(" ");
        }

        // step 5 - remove the last space and return the final sentence
        return sortedSentence.toString().trim();
    }

    public static void main(String[] args) {
        // String s = "is2 sentence4 This1 a3";

        String s = "Myself2 Me1 I4 and3";
        System.out.println(sortSentence(s));
    }
}