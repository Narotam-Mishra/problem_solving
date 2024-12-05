
// Problem link : https://leetcode.com/problems/find-common-characters/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

package string_problems;

import java.util.*;

public class FindCommonCharacters {
    public static List<String> commonChars(String[] words) {
        // initialize frequency array for first word
        int[] commonCount = new int[26];
        
        // count frequencies in first word
        for(char ch : words[0].toCharArray()){
            commonCount[ch - 'a']++;
        }

        // iterate through remaining words
        for(int i=1; i<words.length; i++){
            int[] currCharCount = new int[26];

            // count frequencies in current word
            for(char ch : words[i].toCharArray()){
                currCharCount[ch - 'a']++;
            }

            // update common frequencies
            for(int j=0; j<26; j++){
                commonCount[j] = Math.min(commonCount[j], currCharCount[j]);
            }
        }

        // build result 'res' list
        List<String> res = new ArrayList<>();
        for(int i=0; i<26; i++){
            // add character repeated its common count times
            for(int j=0; j<commonCount[i]; j++){
                res.add(String.valueOf((char)('a' + i)));
            }
        }
        // return result 'res' list
        return res;
    }

    public static void main(String[] args) {
        // String[] words = {"bella","label","roller"};

        String[] words = {"cool","lock","cook"};
        System.out.println(commonChars(words));
    }
}