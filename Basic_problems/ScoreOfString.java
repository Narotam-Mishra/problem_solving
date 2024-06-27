
// Problem link - https://leetcode.com/problems/score-of-a-string/?envType=daily-question&envId=2024-06-01

package Basic_problems;

public class ScoreOfString {
    public static int scoreOfString(String s) {
        int absDiff = 0;
        for(int i=1; i<s.length(); i++){
            // calculate the absolute difference between adjacent characters
            absDiff += Math.abs(s.charAt(i-1) - s.charAt(i));
        }
        return absDiff;
    }

    public static void main(String[] args) {
        String str = "hello";
        System.out.println(scoreOfString(str));
    }
}