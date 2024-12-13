
// Problem link : https://leetcode.com/problems/goat-latin/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

import java.util.*;

public class GoatLatin {
    public static String toGoatLatin(String sentence) {
        // define set of vowels
        Set<Character> vowels = new HashSet<>(Arrays.asList('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'));

        // split sentence into words 
        String[] words = sentence.split(" ");
        StringBuilder res = new StringBuilder();

        // process each word and transform it into GoatLatin as per given conditions
        for(int i=0; i<words.length; i++){
            StringBuilder tw = new StringBuilder();

            // check if the word starts with a vowel
            if(vowels.contains(words[i].charAt(0))){
                // append "ma" if it starts with a vowel
                tw.append(words[i]).append("ma");
            }else{
                // if it starts with a consonant, move the first letter to the end and append "ma"
                tw.append(words[i].substring(1)).append(words[i].charAt(0)).append("ma");
            }

            // append 'a' based on the word index
            for(int j=0; j<=i; j++){
                tw.append('a');
            }

            // add the transformed word to the result 'res'
            if(i > 0){
                res.append(" ");
            }
            res.append(tw);
        }

        return res.toString();
    }

    public static void main(String[] args) {
        // String sentence = "I speak Goat Latin";

        String sentence = "The quick brown fox jumped over the lazy dog";
        System.out.println(toGoatLatin(sentence));
    }
}