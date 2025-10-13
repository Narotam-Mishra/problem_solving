
// Problem link - https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/?envType=daily-question&envId=2025-10-13

package string_problems;

import java.util.*;

public class FindResultantArrayAfterRemovingAnagrams {
    // utility method to check if two strings are Anagram or not
    private static boolean areAnagrams(String s1, String s2){
        // check both strings length
        if(s1.length() != s2.length()) return false;

        // sort both strings
        char[] strChar1 = s1.toCharArray();
        char[] strChar2 = s2.toCharArray();

        Arrays.sort(strChar1);
        Arrays.sort(strChar2);

        // check if each chars of both strings are equal or not
        return Arrays.equals(strChar1, strChar2);
    }

    public static List<String> removeAnagrams(String[] words) {
        // step 1 - store a copy of words in list of string
        List<String> res = new ArrayList<>(Arrays.asList(words));

        // step 2 - start from index `1` as need to check previous index (i-1) as well
        int i=1;

        // step 3 - iterate on words array
        while(i < res.size()){
            // step 4 - check if current word is an anagram of previous word
            if(areAnagrams(res.get(i), res.get(i-1))){
                // step 5 - remove current word from `words`
                res.remove(i);

                // step 6 - after removal, step back one position (if possible)
                // the word that was at position i+1 is now at position i
                // we need to check if this "new" word at position i is also an anagram of i-1
                if(i > 1){
                    i--;
                }

            }

            // step 7 - otherwise move to next position
            else{
                i++;
            }
        }

        // step 8 - return final list after modification
        return res;
    }

    public static void main(String[] args) {
        String[] words = {"abba","baba","bbaa","cd","cd"};
        System.out.println(removeAnagrams(words));
    }
}