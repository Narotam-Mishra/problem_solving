
// Problem link - https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckIfNumberAreAscendingInSentence {
    public static boolean areNumbersAscending(String s) {
        // step 1 - split the sentence by spaces to get all tokens
        String[] tokens = s.split(" ");

        // initialize to smallest possible value
        int prevNumber = Integer.MIN_VALUE;  

        // step 2 - iterate on each token
        for (String token : tokens) {
            // step 3 - check if the token is a valid number (no leading zero, only digits)
            if (token.matches("[1-9][0-9]*")) {
                int currentNumber = Integer.parseInt(token);  // Convert string to integer
                if (currentNumber <= prevNumber) {
                    // not strictly increasing
                    return false; 
                }

                // update previous number
                prevNumber = currentNumber;  
            }
        }

        // step 4 - all numbers were strictly increasing
        return true;  
    }

    public static void main(String[] args) {
        // String s = "1 box has 3 blue 4 red 6 green and 12 yellow marbles";
        
        // String s = "hello world 5 x 5";

        String s = "sunset is at 7 51 pm overnight lows will be in the low 50 and 60 s";
        System.out.println(areNumbersAscending(s));
    }
}