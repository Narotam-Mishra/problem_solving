
// Problem link : https://leetcode.com/problems/unique-morse-code-words/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.HashSet;

public class UniqueMorseCodeWords {
    public static int uniqueMorseRepresentations(String[] words) {
        // step 1 : define the Morse code lookup table
        String[] morseCodeTable = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
            "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
            "..-", "...-", ".--", "-..-", "-.--", "--.."
        };

        // step 2 : initialize a Set to store unique transformations
        HashSet<String> tSet = new HashSet<>();

        // step 3 : iterate through each word in the words array
        for(String word : words){
            // initialize an empty string to build the Morse code for the word
            StringBuilder morseWord = new StringBuilder();

            // convert each letter in the word to its Morse code equivalent
            for(char ch : word.toCharArray()){
                // append the Morse code of the character
                morseWord.append(morseCodeTable[ch - 'a']);
            }

            // add the transformation to the HashSet
            tSet.add(morseWord.toString());
        }

        // step 4 : return the size of the Set (number of unique transformations)
        return tSet.size();
    }

    public static void main(String[] args) {
        // String [] words = {"gin","zen","gig","msg"};

        String [] words = {"a"};
        System.out.println(uniqueMorseRepresentations(words));
    }
}