
// Problem link : https://leetcode.com/problems/find-the-difference/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

public class FindTheDifference {
    public static char findTheDifference(String s, String t) {
        int res = 0;

        // XOR all characters in both strings
        for(int i=0; i<s.length(); i++){
            res ^= s.charAt(i);
        }

        for(int i=0; i<t.length(); i++){
            res ^= t.charAt(i);
        }

        // convert the result to a character
        return (char) res;
    }

    public static void main(String[] args) {
        // String s = "abcd";
        // String t = "abcde";

        String s = "";
        String t = "y";
        System.out.println(findTheDifference(s, t));
    }
}