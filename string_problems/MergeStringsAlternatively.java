
// Problem link - https://leetcode.com/problems/merge-strings-alternately/description/?envType=problem-list-v2&envId=string

package string_problems;

public class MergeStringsAlternatively {
    public static String mergeAlternately(String word1, String word2) {
        // step 1 - use two pointers technique
        int i=0, j=0;

        // step 2 - store merged string into `res`
        String res = "";

        // step 3 - iterate on both strings alternatively
        while(i < word1.length() && j < word2.length()){
            res += word1.charAt(i++);
            res += word2.charAt(j++);
        }

        // check if some characters are left in word1 
        while(i < word1.length()){
            res += word1.charAt(i++);
        }

        // check if some characters are left in word2 
        while(j < word2.length()){
            res += word2.charAt(j++);
        }

        // step 4 - return final merged string `res`
        return res;
    }

    public static void main(String[] args) {
        // String word1 = "abc", word2 = "pqr";

        // String word1 = "ab", word2 = "pqrs";

        String word1 = "abcd", word2 = "pq";
        System.out.println(mergeAlternately(word1, word2));
    }
}