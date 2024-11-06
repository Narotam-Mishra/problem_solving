
// Problem link : https://leetcode.com/problems/rotate-string/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

public class RotateString {
    public static boolean rotateString(String s, String goal) {
        // cornor case: check if lengths are the same, 
        // if not, s can't be shifted to become goal
        if(s.length() != goal.length()) return false;

        // concatenate s with itself to cover all possible rotations
        String doubleStr = s + s;

        // check if goal is a substring of doubleS
        return doubleStr.contains(goal);
    }

    public static void main(String[] args) {
        // String s = "abcde", goal = "cdeab";

        String s = "abcde", goal = "abced";
        System.out.println(rotateString(s, goal));
    }
}