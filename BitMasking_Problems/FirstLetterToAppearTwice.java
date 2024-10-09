
// Problem link : https://leetcode.com/problems/first-letter-to-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

package BitMasking_Problems;

import java.util.*;

public class FirstLetterToAppearTwice {
    public static char repeatedCharacter(String s) {
        // create a hashmap to store character frequencies
        HashMap<Character, Integer> hm = new HashMap<>();

        // traverse each character in the string
        for(char ch : s.toCharArray()){
            // if the character already exists in the map, increment its count
            hm.put(ch, hm.getOrDefault(ch, 0) + 1);

            // if the count becomes 2, return that character
            if(hm.get(ch) == 2){
                return ch;
            }
        }
        // in case no character is repeated
        return '\0';
    } 
    
    public static void main(String[] args) {
        // String str = "abccbaacz";

        String str = "abcdd";
        System.out.println(repeatedCharacter(str));
    }
}