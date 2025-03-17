
// Problem link - https://leetcode.com/problems/goal-parser-interpretation/?envType=problem-list-v2&envId=string

package string_problems;

public class GoalParserInterpretation {
    public static String interpret(String command) {
        // step 1 - initialize an empty string `res` to store the result
        StringBuilder res = new StringBuilder(command.length());
        int i = 0;

        // step 2 - iterate on input string `command` and scane each character
        while (i < command.length()) {
            // 'G' remains unchanged
            if (command.charAt(i) == 'G') {
                res.append("G");
                i++;
            } else if (command.charAt(i) == '(') {
                // check if it's "()" or "(al)"
                if (command.charAt(i + 1) == ')') {
                    // "()" will be interprreted as 'o'
                    res.append("o");
                    i += 2;
                } else {
                    // "(al)" is interpreted as "al"
                    res.append("al");
                    i += 4;
                }
            }
        }

        // step 3 - return result string `res`
        return res.toString();
    }

    public static void main(String[] args) {
        // String command = "G()(al)";

        // String command = "G()()()()(al)";

        String command = "(al)G(al)()()G";
        System.out.println(interpret(command));
    }
}