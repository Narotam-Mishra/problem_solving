
// Problem link : https://leetcode.com/problems/find-words-containing-character/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

import java.util.ArrayList;
import java.util.List;

public class FindWordsContainingCharacter {
    public static List<Integer> findWordsContaining(String[] words, char x) {
        List<Integer> res = new ArrayList<>();

        // iterate through each word in the array
        for(int i=0; i<words.length; i++){
            String currWord = words[i];

            // check if the current word contains the character x
            if(currWord.indexOf(x) != -1){
                res.add(i);
            }
        }

        // return the list of indices where words contain the character x
        return res;
    }

    public static void main(String[] args) {
        // String[] words = {"leet","code"};
        // char x = 'e';

        // String[] words = {"abc","bcd","aaaa","cbc"};
        // char x = 'a';

        String[] words = {"abc","bcd","aaaa","cbc"};
        char x = 'z';
        System.out.println(findWordsContaining(words, x));
    }
}
