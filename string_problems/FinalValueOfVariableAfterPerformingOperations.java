
// Problem link - https://leetcode.com/problems/final-value-of-variable-after-performing-operations/?envType=problem-list-v2&envId=string

package string_problems;

public class FinalValueOfVariableAfterPerformingOperations {
    public static int finalValueAfterOperations(String[] operations) {
        // step 1 - set initial to 0
        int val = 0;

        // step 2 - iterate on each operation and perform accordingly
        for (String op : operations) {
            // perform operation
            if (op == "--X" || op == "X--") {
                val--;
            } else {
                val++;
            }
        }

        // step 3 - return final value after all operations
        return val;
    }

    public static void main(String[] args) {
        String[] operations = {"--X","X++","X++"};

        // String[] operations = {"++X","++X","X++"};

        // String[] operations = {"X++","++X","--X","X--"};
        System.out.println(finalValueAfterOperations(operations));
    }
}