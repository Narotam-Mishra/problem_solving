
// Problem link : https://leetcode.com/problems/rearrange-characters-to-make-target-string/description/

package string_problems;

public class RearrangeCharactersToMakeTargetString {

    // helper function to create a frequency map of characters in a string
    private static int[] createFrequencyMap(String s) {
        int[] frequencyMap = new int[26];
        for (char c : s.toCharArray()) {
            frequencyMap[c - 'a']++;
        }
        return frequencyMap;
    }

    public static int rearrangeCharacters(String s, String target) {
        // step 1 : create frequency maps for both s and target
        int[] strMap = createFrequencyMap(s);
        int[] targetMap = createFrequencyMap(target);

        // step 2 : initialize the maximum number of copies to a large number
        int maxCopies = Integer.MAX_VALUE;

        // step 3 : // calculate the maximum number of copies of target that can be
        // formed
        // Calculate the maximum number of copies of target that can be formed
        for (int i = 0; i < 26; i++) {
            if (targetMap[i] > 0) {
                if (strMap[i] == 0) {
                    // If a character in target is not present in s, we can't form target even once
                    return 0;
                }
                // Calculate how many times this character can contribute to forming target
                int possibleCopies = strMap[i] / targetMap[i];
                // Update the maximum number of copies
                maxCopies = Math.min(maxCopies, possibleCopies);
            }
        }
        // step 4 : return `maxCopies` maximum copies possible
        return maxCopies;
    }

    public static void main(String[] args) {
        String s = "ilovecodingonleetcode", target = "code";

        // String s = "abbaccaddaeea", target = "aaaaa";
        System.out.println(rearrangeCharacters(s, target));
    }
}