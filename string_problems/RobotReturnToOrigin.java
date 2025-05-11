
// Problem link - https://leetcode.com/problems/robot-return-to-origin/?envType=problem-list-v2&envId=string

package string_problems;

public class RobotReturnToOrigin {
    public static boolean judgeCircle(String moves) {
        // step 1 - intilaize variables to keep track of position
        int x = 0, y = 0;

        // step 2 - iterate on each move
        for (char move : moves.toCharArray()) {
            // step 3 - incremnt / decremnt position as per its move
            // for Up (U) and Right (R) moves increment its position
            // for Down (D) and Left (L) moves decrement its position
            if (move == 'U') {
                y++;
            } else if (move == 'D') {
                y--;
            } else if (move == 'R') {
                x++;
            } else {
                x--;
            }
        }

        // step 4 - check whether Robot returns to its origin or not
        return x == 0 && y == 0;
    }

    public static void main(String[] args) {
        // String moves = "UD";

        // String moves = "LL";

        String moves = "RRDD";
        System.out.println(judgeCircle(moves));
    }
}