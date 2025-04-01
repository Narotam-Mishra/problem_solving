
// Problem link - https://leetcode.com/problems/find-the-encrypted-string/description/?envType=problem-list-v2&envId=string

package string_problems;

public class FindTheEncryptedString {
    public static String getEncryptedString(String s, int k) {
        // step 1 - initialize a `res` string to store result
        StringBuilder res = new StringBuilder();

        // find length of input string `s`
        int n = s.length();

        // step 2 - iterate on input string `s`
        for (int i = 0; i < n; i++) {
            // step 3 - find `res`
            res.append(s.charAt((i + k) % n));
        }

        // step 4 - return `res`
        return res.toString();
    }

    public static void main(String[] args) {
        // String s = "dart";
        // int k = 3;

        String s = "aaa";
        int k = 1;
        System.out.println(getEncryptedString(s, k));
    }
}