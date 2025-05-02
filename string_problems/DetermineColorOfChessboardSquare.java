
// Problem link - https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/?envType=problem-list-v2&envId=string

package string_problems;

public class DetermineColorOfChessboardSquare {
    public static boolean squareIsWhite(String coordinates) {
        // step 1 - extract character and number from coordinates
        int charVal = coordinates.charAt(0) - 'a' + 1;
        int num = coordinates.charAt(1) - '0';

        // step 2 - find sum of both co-ordinates
        int sum = charVal + num;

        // step 3 - check whether sum is odd or even and return true and false accordingly
        if(sum % 2 == 0){
            // return false for even sum
            return false;
        }else{
            // return true for odd sum
            return true;
        }
    }

    public static void main(String[] args) {
        // String coordinates = "a1";

        // String coordinates = "h3";

        String coordinates = "c7";
        System.out.println(squareIsWhite(coordinates));
    }
}