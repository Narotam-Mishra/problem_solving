
// Problem link : https://leetcode.com/problems/counting-words-with-a-given-prefix/description/

package string_problems;

public class CountWordsWithGivenPrefix {
    public static int prefixCount(String[] words, String pref) {
        // intialize counter `countPrefix` to count number of prefix exist in words array
        int countPrefix = 0;

        // step 1 - iterate through words array
        for (String word : words) {
            // step 2 - check if prefix exists
            if (word.startsWith(pref)) {
                // step 3 - increment the prefix count
                countPrefix++;
            }
        }

        // step 4 - return `countPrefix` counter
        return countPrefix;
    }

    public static void main(String[] args) {
        // String[] words = {"pay","attention","practice","attend"};
        // String pref = "at";

        String[] words = {"leetcode","win","loops","success"};
        String pref = "code";
        System.out.println(prefixCount(words, pref));
    }
}