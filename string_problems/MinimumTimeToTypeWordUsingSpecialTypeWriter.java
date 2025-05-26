
// Problem link - https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/?envType=problem-list-v2&envId=string

package string_problems;

public class MinimumTimeToTypeWordUsingSpecialTypeWriter {
    public static int minTimeToType(String word) {
        // step 1 - store minimum time in `minTime`
        int minTime = 0;

        // pointer start from character `a`
        char currChar = 'a';

        // step 2 - iterate on each character of word
        for(int i=0; i<word.length(); i++){
            // get current character as target character
            char targetChar = word.charAt(i);

            // step 3 - calculate absolute difference between current and target character
            int diff = Math.abs(targetChar - currChar);

            // step 4 - calculate minimum time
            // since typwriter is circular so it can be either clockwise or anti-clockwise
            int moveTime = Math.min(diff, 26 - diff);

            // step 5 - add 1 second to type each character
            minTime += moveTime + 1;

            // step 6 - update current chacter
            currChar = targetChar;
        }

        // step 7 - return minimum time to type out the word
        return minTime;
    }

    public static void main(String[] args) {
        // String word = "abc";

        // String word = "bza";

        String word = "zjpc";
        System.out.println(minTimeToType(word));
    }
}