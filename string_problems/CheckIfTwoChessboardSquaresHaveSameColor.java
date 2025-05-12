
// Problem link - https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/description/?envType=problem-list-v2&envId=string

package string_problems;

public class CheckIfTwoChessboardSquaresHaveSameColor {
    public static boolean checkTwoChessboards(String coordinate1, String coordinate2) {
        // step 1 - extract character and number from coordinate
        int charVal1 = coordinate1.charAt(0) - 'a' + 1;
        int num1 = coordinate1.charAt(1) - '0';

        int charVal2 = coordinate2.charAt(0) - 'a' + 1;
        int num2 = coordinate2.charAt(1) - '0';

        // step 2 - find sum of both co-ordinates
        int sum1 = charVal1 + num1;

        int sum2 = charVal2 + num2;

        // step 3 - check if both sum are either even or odd then return true, otherwise return false
        if(sum1 % 2 == 0 && sum2 % 2 == 0){
            return true;
        }else if(sum1 % 2 != 0 && sum2 % 2 != 0){
            return true;
        }else{
            return false;
        }
    }

    public static void main(String[] args) {
        String coordinate1 = "a1", coordinate2 = "c3";

        // String coordinate1 = "a1", coordinate2 = "h3";
        System.out.println(checkTwoChessboards(coordinate1, coordinate2));
    }
}