
// Problem link - https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/?envType=problem-list-v2&envId=string

package string_problems;

public class NumberOfStringsThatAppearAsSubstringInWord {
    public static int numOfStrings(String[] patterns, String word) {
        // Step 1 - initialize counter
        int count = 0;

        // Step 2 - iterate over each pattern
        for (String w : patterns) {
            // Step 3 - check if word contains the pattern
            if (word.contains(w)) {
                count++;
            }
        }

        // Step 4 - return count
        return count;
    }

    public static void main(String[] args) {
        // String[] patterns = {"a","abc","bc","d"};
        // String word = "abc";

        // String[] patterns = {"a","b","c"};
        // String word = "aaaaabbbbb";

        String[] patterns = {"a","a","a"};
        String word = "ab";
        System.out.println(numOfStrings(patterns, word));
    }
}