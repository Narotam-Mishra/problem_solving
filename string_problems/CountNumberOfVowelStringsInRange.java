package string_problems;

import java.util.*;

public class CountNumberOfVowelStringsInRange {
    public static int vowelStrings(String[] words, int left, int right) {
        // step 1 - initialize counter
        int count = 0;

        // step 2 - create vowels set for fast lookup
        Set<Character> vowelSet = new HashSet<>(Arrays.asList('a','e','i','o','u'));

        // step 3 - iterate on words array in range of `left` to `right`
        for(int i=left; i<=right; i++){
            String word = words[i];
            // step 4 - check for vowel string conditions
            if(vowelSet.contains(word.charAt(0)) && vowelSet.contains(word.charAt(word.length() - 1))){
                // increment the counter if it matches the given vowel string conditions
                count++;
            }
        }

        // step 5 - return counter `count`
        return count;
    }

    public static void main(String[] args) {
        // String[] words = {"are","amy","u"};
        // int left = 0;
        // int right = 2;

        String[] words = {"hey","aeo","mu","ooo","artro"};
        int left = 1;
        int right = 4;
        System.out.println(vowelStrings(words, left, right));
    }
}