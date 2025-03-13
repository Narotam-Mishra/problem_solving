
// Problem link - https://leetcode.com/problems/count-binary-substrings/description/?envType=problem-list-v2&envId=string

package string_problems;

public class CountBinarySubstrings {
    public static int countBinarySubstrings(String s) {
        // step 1 - variable intialization
        int prevGroup = 0, currGroup = 1, count = 0;

        // step 2 - iterate on input string
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                // extend current group if current and previous digits are equal
                currGroup++;
            } else {
                // otherwise count valid substring
                count += Math.min(currGroup, prevGroup);

                // move to new group
                prevGroup = currGroup;

                // reset counter for the new group
                currGroup = 1;
            }
        }

        // step 3 - count last valid substring
        return count + Math.min(currGroup, prevGroup);
    }

    public static void main(String[] args) {
        // String s = "00110011";

        String s = "10101";
        System.out.println(countBinarySubstrings(s));
    }
}