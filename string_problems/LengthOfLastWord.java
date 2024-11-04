
// Problem link : https://leetcode.com/problems/length-of-last-word/description/

package string_problems;

public class LengthOfLastWord {
    public static int lengthOfLastWord(String s) {
        // remove trailing spaces
        s = s.trim();

        // find the last space index
        int lsIdx = s.lastIndexOf(' ');

        // if no space, return length of entire string
        if(lsIdx == -1){
            return s.length();
        }

        // return the length of the substring after the last space
        return s.length() - lsIdx - 1;
    }

    public static void main(String[] args) {
        // String str = "The last word is World with";

        // String str = "Hello World";

        String str = "   fly me   to   the moon  ";
        System.out.println(lengthOfLastWord(str));
    }
}