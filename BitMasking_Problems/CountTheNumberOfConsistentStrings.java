
// Problem link : https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

import java.util.*;

public class CountTheNumberOfConsistentStrings {
    public static int countConsistentStrings(String allowed, String[] words) {
        // convert 'allowed' string into a Set for efficient lookup of allowed characters
        Set<Character> allowedSet = new HashSet<>();
        for(char ch : allowed.toCharArray()){
            allowedSet.add(ch);
        }

        int consistentCount = 0;

        // iterate over each word in the 'words' array
        for(String word : words){
            boolean isConsistent = true;
            // check each character in the word
            for(char ch : word.toCharArray()){
                if(!allowedSet.contains(ch)){
                    // if character is not allowed, mark the word as inconsistent
                    isConsistent = false;
                    break;
                }
            }

            // if the word is consistent, increment the counter
            if(isConsistent){
                consistentCount++;
            }
        }
        return consistentCount;
    }

    public static void main(String[] args) {
        // String allowed = "ab";
        // String[] words = {"ad","bd","aaab","baa","badab"};

        String allowed = "abc";
        String[] words = {"a","b","c","ab","ac","bc","abc"};
        System.out.println(countConsistentStrings(allowed, words));
    }
}