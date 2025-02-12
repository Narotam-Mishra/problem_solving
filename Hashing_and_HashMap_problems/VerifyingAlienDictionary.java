
// Problem link - https://leetcode.com/problems/verifying-an-alien-dictionary/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class VerifyingAlienDictionary {
    public static boolean isAlienSorted(String[] words, String order) {
        // step 1 - create a map to store letter to index mapping from alien alphabet
        Map<Character, Integer> orderMap = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            orderMap.put(order.charAt(i), i);
        }

        // step 2 - compare adjacent words
        for (int i = 0; i < words.length - 1; i++) {
            String word1 = words[i];
            String word2 = words[i + 1];

            // get length of shorter word
            int minLength = Math.min(word1.length(), word2.length());
            boolean isDifferent = false;

            // compare the two words character by character
            for (int j = 0; j < minLength; j++) {
                int weight1 = orderMap.get(word1.charAt(j));
                int weight2 = orderMap.get(word2.charAt(j));

                // if characters are different
                if (weight1 != weight2) {
                    // if current character in word1 has higher weight,
                    // then words are not sorted
                    if (weight1 > weight2) {
                        return false;
                    }

                    // mark that we found a difference and break
                    isDifferent = true;
                    break;
                }
            }

            // if no difference found in common prefix and word1 is longer,
            // then words are not sorted (e.g., "apple" vs "app")
            if (!isDifferent && word1.length() > word2.length()) {
                return false;
            }
        }

        // step 3 - if all pairs are in order, return true
        return true;
    }

    public static void main(String[] args) {
        // String[] words = {"hello","leetcode"};
        // String order = "hlabcdefgijkmnopqrstuvwxyz";

        // String[] words = {"word","world","row"};
        // String order = "worldabcefghijkmnpqstuvxyz";

        String[] words = {"apple","app"};
        String order = "abcdefghijklmnopqrstuvwxyz";
        System.out.println(isAlienSorted(words, order));
    }
}