
// Problem link - https://leetcode.com/problems/vowel-spellchecker/?envType=daily-question&envId=2025-09-14

package string_problems;

import java.util.*;

public class VowelSpellchecker {
    // helper function to convert vowels to a pattern (replace vowels with `*`)
    private static String getVowelPattern(String word){
        StringBuilder vowelsPatternWord = new StringBuilder();
        String lowerWord = word.toLowerCase();

        for(char ch : lowerWord.toCharArray()){
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                vowelsPatternWord.append('*');
            }else{
                vowelsPatternWord.append(ch);
            }
        }
        return vowelsPatternWord.toString();
    }

    public static String[] spellchecker(String[] wordlist, String[] queries) {
        // step 1 - create required data structures
        // set for exact matches (case sensitive)
        Set<String> exactWords = new HashSet<>();

        // map for capitalization matches
        Map<String, String> capWords = new HashMap<>();

        // map for vowel pattern matches 
        Map<String, String> vowelsMap = new HashMap<>();

        // step 2 - iterate on wordlist and populate map
        for(String word : wordlist){
            // store word for exact matches
            exactWords.add(word);

            // store first occurrence for capitalization matches
            String lowerWord = word.toLowerCase();
            if(!capWords.containsKey(lowerWord)){
                capWords.put(lowerWord, word);
            }

            // store for vowel pattern matches
            String vowelWordPattern = getVowelPattern(word);
            if(!vowelsMap.containsKey(vowelWordPattern)){
                vowelsMap.put(vowelWordPattern, word);
            }
        }

        // step 3 - process each query according to given precedence rule
        String[] res = new String[queries.length];

        for(int i=0; i<queries.length; i++){
            String query = queries[i];
            String ans = "";

            // rule1 - check for exact match
            if(exactWords.contains(query)){
                ans = query;
            }

            // rule 2 - check for capitalization match (case insensitive)
            else if(capWords.containsKey(query.toLowerCase())){
                ans = capWords.get(query.toLowerCase());
            }

            // rule 3 - check for vowel error match
            else{
                String queryVowelPattern = getVowelPattern(query);
                if(vowelsMap.containsKey(queryVowelPattern)){
                    ans = vowelsMap.get(queryVowelPattern);
                }

                // rule 4 - for no match, return empty 
                // for which ans is set to ""
            }

            // store result for current query
            res[i] = ans;
        }

        // step 4 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        String[] wordlist = {"KiTe","kite","hare","Hare"}, queries = {"kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"};
        String[] res = spellchecker(wordlist, queries);
        System.out.println(Arrays.toString(res));
    }
}
