
// Problem link - https://leetcode.com/problems/find-special-substring-of-length-k/description/?envType=problem-list-v2&envId=string

package string_problems;

public class FindSpecialSubstringOfLengthK {
    public static boolean hasSpecialSubstring(String s, int k) {
        // find string length
        int n = s.length();

        // edge cases:
        if (n < k)
            return false;

        // step 1 - iterate through string in chunks
        for (int i = 0; i <= n - k;) {
            char currChar = s.charAt(i);
            int j = i;

            // step 2 - find end of the current run of the same character
            while (j < n && s.charAt(j) == currChar) {
                j++;
            }

            // find length of current substring
            int runLength = j - i;

            // step 3 - if we found a run of exactly length k
            if (runLength == k) {
                // check the character before (if exist)
                boolean beforeValid = (i == 0) || (s.charAt(i - 1) != currChar);

                // check the character after (if exist)
                boolean afterValid = (j == n) || (s.charAt(j) != currChar);

                if (beforeValid && afterValid) {
                    return true;
                }
            }

            // move to next character after this run
            i = j;
        }

        // step 4 - return false if none of the conditions satisfy
        return false;
    }

    public static void main(String[] args) {
        // String s = "aaabaaa";
        // int k = 3;

        String s = "abc";
        int k = 2;
        System.out.println(hasSpecialSubstring(s, k));
    }
}