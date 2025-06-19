
// Problem link - https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=array

package Stack_Problems;

import java.util.*;

public class BaseballGame {
    public static int calPoints(String[] operations) {
        // using stack to perform each operation
        Stack<Integer> score = new Stack<>();

        // step 1 - iterate on each operation `op`
        for (String op : operations) {
            // step 2 - perform each operation in stack `score`
            if (op.equals("+")) {
                // for `+` add sum of previous two scores
                int n = score.size();
                int newScore = score.get(n - 1) + score.get(n - 2);
                score.push(newScore);
            } else if (op.equals("C")) {
                // cancel (remove) the previous score
                score.pop();
            } else if (op.equals("D")) {
                // add double of previous score
                int newScore = score.peek() * 2;
                score.push(newScore);
            } else {
                // it's an integer - add new score to stack `score` record
                int num = Integer.parseInt(op);
                score.push(num);
            }
        }

        // step 3 - return sum of all scores
        int sum = 0;
        for (int num : score) {
            sum += num;
        }
        return sum;
    }

    public static void main(String[] args) {
        // String[] ops = {"5","2","C","D","+"};

        String[] ops = {"5","-2","4","C","D","9","+","+"};
        System.out.println(calPoints(ops));
    }
}