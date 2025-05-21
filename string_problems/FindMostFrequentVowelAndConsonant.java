
// Problem link - https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/?envType=problem-list-v2&envId=string

package string_problems;

public class FindMostFrequentVowelAndConsonant {
    public static int maxFreqSum(String s) {
        // step 1 - use frquency array to store frquency of each character in `s`
        int[] frq = new int[26];

        // step 2 - iterate on each character of `s` and store its frquency
        for (char ch : s.toCharArray()) {
            frq[ch - 'a']++;
        }

        // step 3 - find maximum vowel and consonants frquency
        int maxFrqV = 0, maxFrqC = 0;
        for (int i = 0; i < 26; i++) {
            if (i == 0 || i == 4 || i == 8 || i == 14 || i == 20) {
                maxFrqV = Math.max(maxFrqV, frq[i]);
            } else {
                maxFrqC = Math.max(maxFrqC, frq[i]);
            }
        }

        // step 4 - return sum of maximum vowel and consonant frequency
        return maxFrqC + maxFrqV;
    }

    public static void main(String[] args) {
        // String s = "successes";

        String s = "aeiaeia";
        System.out.println(maxFreqSum(s));
    }
}