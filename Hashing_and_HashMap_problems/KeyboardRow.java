
// Problem link - https://leetcode.com/problems/keyboard-row/

package Hashing_and_HashMap_problems;

import java.util.*;

public class KeyboardRow {

    private static boolean isWordInRow(String word, Set<Character> rowSet){
        for(char ch : word.toLowerCase().toCharArray()){
            if(!rowSet.contains(ch)){
                return false;
            }
        }
        return true;
    }

    public static String[] findWords(String[] words) {
        // step 1 - define sets for each row
        Set<Character> row1 = new HashSet<>(
            Arrays.asList('q','w','e','r','t','y','u','i','o','p')
        );

        Set<Character> row2 = new HashSet<>(
            Arrays.asList('a','s','d','f','g','h','j','k','l')
        );

        Set<Character> row3 = new HashSet<>(
            Arrays.asList('z','x','c','v','b','n','m')
        );

        // step 2 - store final result in `res` 
        List<String> res = new ArrayList<>();
        
        // step 3 - iterate on each word of words
        for(String word : words){
            char firstChar = Character.toLowerCase(word.charAt(0));

            // step 4 - determine row for each word
            if(row1.contains(firstChar)){
                if(isWordInRow(word, row1)) res.add(word);
            }else if(row2.contains(firstChar)){
                if(isWordInRow(word, row2)) res.add(word);
            }else{
                if(isWordInRow(word, row3)) res.add(word);
            }
        }

        // step 5 - return final result `res`
        return res.toArray(new String[0]);
    }

    public static void main(String[] args) {
        // String[] words = {"Hello","Alaska","Dad","Peace"};

        // String[] words = {"omk"};

        String[] words = {"adsdf", "sfd"};
        String[] res = findWords(words);
        System.out.println(Arrays.toString(res));
    }
}