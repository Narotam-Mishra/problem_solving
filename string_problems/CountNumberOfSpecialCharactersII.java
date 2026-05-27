
// Problem link - https://leetcode.com/problems/count-the-number-of-special-characters-ii/?envType=daily-question&envId=2026-05-27

package string_problems;

import java.util.*;

public class CountNumberOfSpecialCharactersII {
    public int numberOfSpecialChars(String word) {
        // get size of word
        int n = word.length();

        // keep track occurance of lowecase & uppercase characters separately
        int[] lastLower = new int[26];
        Arrays.fill(lastLower, -1);

        int[] firstUpper = new int[26];
        Arrays.fill(firstUpper, n);

        // step 1 - iterate through the string to fill both arrays
        for (int i = 0; i < n; i++) {
            // extract current character
            char ch = word.charAt(i);

            // for lower case letter update lastLower
            if (Character.isLowerCase(ch)) {
                int idx = ch - 'a';
                lastLower[idx] = i;
            } else {
                // for upper case letter update firstUpper
                int idx = ch - 'A';
                if (firstUpper[idx] == n) {
                    firstUpper[idx] = i;
                }
            }
        }

        // keep track of special count
        int specialCount = 0;

        // step 2 - count special characters
        for (int i = 0; i < 26; i++) {
            // case 1 - check if lower case letter exist
            boolean lowercaseExist = lastLower[i] != -1;

            // case 2 - check if upper case letter exist
            boolean uppercaseExist = firstUpper[i] != n;

            // case 3 - check if last lowercase comes before first uppercase
            boolean orderStaisfied = lastLower[i] < firstUpper[i];

            // check above three condiitons
            if (lowercaseExist && uppercaseExist && orderStaisfied) {
                // increment special characters count
                specialCount++;
            }
        }

        // step 3 - return special characters count
        return specialCount;
    }

    public static void main(String[] args) {
        String word = "aaAbcBC";
        CountNumberOfSpecialCharactersII obj = new CountNumberOfSpecialCharactersII();
        System.out.println(obj.numberOfSpecialChars(word));
    }
}
