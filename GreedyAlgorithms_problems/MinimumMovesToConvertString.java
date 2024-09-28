
// Problem link : https://leetcode.com/problems/minimum-moves-to-convert-string/description/

package GreedyAlgorithms_problems;

public class MinimumMovesToConvertString {
    public static int minimumMoves(String s) {
        // counter for the number of moves required
        int moves = 0;

        // pointer to iterate through the string
        int i = 0;

        // iterate through the string
        while(i < s.length()){
            // if we find an 'X', we need to make a move
            if(s.charAt(i) == 'X'){
                // make a move, even if some of them are already 'O', it doesn't matter
                moves++;

                // skip the next two characters, as they are included in the current move
                i += 3;
            }else{
                // if the character is 'O', just move to the next character
                i++;
            }
        }
        // return the total number of moves required
        return moves;
    }

    public static void main(String[] args) {
        // String str = "XXX";

        // String str = "XXOX";

        String str = "OOOO";
        System.out.println(minimumMoves(str));
    }
}