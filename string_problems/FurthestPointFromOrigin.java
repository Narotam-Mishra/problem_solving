
// Problem link - https://leetcode.com/problems/furthest-point-from-origin/?envType=problem-list-v2&envId=string

package string_problems;

public class FurthestPointFromOrigin {
    public static int furthestDistanceFromOrigin(String moves) {
        // step 1 - initialize counters
        int left = 0, right = 0, dash = 0;

        // step 2 - traverse each character of moves
        for (char move : moves.toCharArray()) {
            // step 3 - count left, right & dashed (-)
            if (move == 'L') {
                left++;
            } else if (move == 'R') {
                right++;
            } else {
                dash++;
            }
        }

        // step 4 - assign all dash to the left
        int op1 = Math.abs((left + dash) - right);

        // step 5 - assign all dash to the right
        int op2 = Math.abs((right + dash) - left);

        // step 6 - return maximum distance from origin
        return Math.max(op1, op2);
    }

    public static void main(String[] args) {
        // String moves = "L_RL__R";

        // String moves = "_R__LL_";

        String moves = "_______";
        System.out.println(furthestDistanceFromOrigin(moves));
    }
}