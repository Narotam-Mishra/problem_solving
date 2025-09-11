
// Problem link - https://leetcode.com/problems/sort-vowels-in-a-string/description/?envType=daily-question&envId=2025-09-11

package string_problems;

import java.util.*;

public class SortVowelsInString {
    // utility method to check if character is vowel or not
    private static boolean isVowel(char ch) {
        ch = Character.toLowerCase(ch);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public static String sortVowels(String s) {
        // step 1 - count frequency of each vowel in input string `s`
        Map<Character, Integer> vowelMap = new HashMap<>();
        for (char ch : s.toCharArray()) {
            if (isVowel(ch)) {
                vowelMap.put(ch, vowelMap.getOrDefault(ch, 0) + 1);
            }
        }

        // step 2 - define vowels in ASCII sorted order
        String vowels = "AEIOUaeiou";

        // pointer to track current position in sorted vowels string
        int j = 0;

        // step 3 - replace vowels in input string `s` with help of sorted vowels
        // convert string to array for mutability
        char[] inputStr = s.toCharArray();
        for (int i = 0; i < inputStr.length; i++) {
            if (isVowel(inputStr[i])) {
                // find next available vowel in sorted order
                while ((vowelMap.getOrDefault(vowels.charAt(j), 0)) == 0) {
                    // skip vowels that are not present in input string
                    j++;
                }

                // replace current vowel with the smallest available vowel
                inputStr[i] = vowels.charAt(j);

                // decrese used vowel count in `vowelMap`
                vowelMap.put(vowels.charAt(j), vowelMap.get(vowels.charAt(j)) - 1);
            }
        }

        // step 4 - return modified string `s`
        return new String(inputStr);
    }

    public static void main(String[] args) {
        // String s = "lEetcOde";

        String s = "lYmpH";
        System.out.println(sortVowels(s));
    }
}
