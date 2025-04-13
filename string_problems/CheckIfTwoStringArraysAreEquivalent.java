
// Problem link - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckIfTwoStringArraysAreEquivalent {
    public static boolean arrayStringsAreEqual(String[] word1, String[] word2) {
        // step 1 - join each characters of word array and check for equality
        return String.join("", word1).equals(String.join("", word2));
    }

    public static void main(String[] args) {
        // String[] word1 = {"ab", "c"};
        // String[] word2 = {"a", "bc"};

        // String[] word1 = {"a", "cb"};
        // String[] word2 = {"ab", "c"};

        String[] word1 = {"abc", "d", "defg"};
        String[] word2 = {"abcddefg"};
        System.out.println(arrayStringsAreEqual(word1, word2));
    }
}