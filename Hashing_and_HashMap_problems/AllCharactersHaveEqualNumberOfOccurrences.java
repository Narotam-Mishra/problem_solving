
// Problem link : https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class AllCharactersHaveEqualNumberOfOccurrences {
    public static boolean areOccurrencesEqual1(String s) {
        // step 1 - create map and store frequency of each character of input string `s`
        Map<Character, Integer> map = new HashMap<>();
        for(char ch : s.toCharArray()){
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }

        // step 2 - get count of first charcter of input string
        int currCount = map.get(s.charAt(0));

        // step 3 - compare 1st charcter count with remaining characters
        for(int i=1; i<s.length(); i++){
            // if remaining characters count are not equal
            if(currCount != map.get(s.charAt(i))){
                // return false immediately
                return false;
            }
        }
        // step 4 - otherwise return true
        return true;
    }

    public static boolean areOccurrencesEqual(String s) {
        // step 1 - create frequency array map and store frequency of each character of input string `s`
        int[] frqArr = new int[26];
        for(int i=0; i<s.length(); i++){
            frqArr[s.charAt(i) - 'a']++;
        }

        // step 2 - get count of first charcter of input string
        int currCount = frqArr[s.charAt(0) - 'a'];
        
        // step 3 - compare 1st charcter count with remaining characters
        for(int num : frqArr){
            // if remaining characters count are not equal
            if(num !=0 && num != currCount){
                // return false immediately
                return false;
            }
        }

        // step 4 - otherwise return true
        return true;
    }

    public static void main(String[] args) {
        String s = "abacbc";

        // String s = "aaabb";
        System.out.println(areOccurrencesEqual(s));
    }
}