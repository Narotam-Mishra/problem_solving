
// Problem link - https://leetcode.com/problems/find-the-original-typed-string-i/?envType=problem-list-v2&envId=string

package string_problems;

public class FindTheOriginalTypedStringI {

    public static int possibleStringCount(String word) {
        // step 1 - count number of possible strings
        // start with 1 for the string as-is (no mistakes)
        int count = 1;

        // step 2 - iterate on each character of `word`
        for (int i = 0; i < word.length(); i++) {

            // step 3 - find the length of the current run of identical characters
            int j = i + 1;
            while (j < word.length() && word.charAt(j) == word.charAt(i)) {
                j++;
            }

            // step 4 - if we found repeated characters
            // Alice might have intended to type just one character here
            int runLength = j - i;
            if (runLength > 1) {
                // increment count for repeated characters
                count++;
            }
        }

        // step 5 - return count number of possible strings
        return count;
    }

    public static void main(String[] args) {
        // String word = "abbcccc";

        // String word = "abcd";

        String word = "aaaa";
        System.out.println(possibleStringCount(word));
    }
}