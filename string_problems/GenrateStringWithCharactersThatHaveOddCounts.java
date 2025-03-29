
// Problem link - https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/?envType=problem-list-v2&envId=string

package string_problems;

public class GenrateStringWithCharactersThatHaveOddCounts {
    public static String generateTheString(int n) {
        // step 1 - if `n` is odd then generate `n` characters
        // step 2 - if `n` is even then generate `n-1` characters first and one different character
        return (n % 2 == 1) ? "a".repeat(n) : "a".repeat(n-1) + "b";
    }

    public static void main(String[] args) {
        // int n = 4;

        // int n = 2;

        int n = 7;
        System.out.println(generateTheString(n));
    }
}