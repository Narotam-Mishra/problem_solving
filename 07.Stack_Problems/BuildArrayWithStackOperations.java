
// Problem link - https://leetcode.com/problems/build-an-array-with-stack-operations/description/

package Stack_Problems;

import java.util.ArrayList;
import java.util.List;

public class BuildArrayWithStackOperations {
    public static List<String> buildArray(int[] target, int n) {
        // Initialize a list to store operations
        List<String> stack = new ArrayList<>();
        // Initialize a variable to track the current integer in the stream
        int i = 1;

        // Iterate through each number in the target array
        for(int num : target){
            // While the current integer in the stream is less than the target number
            while (i < num) {
                // Push the current integer to the stack
                stack.add("Push");
                // Pop the integer immediately after pushing
                stack.add("Pop");
                // Move to the next integer in the stream
                i++;
            }
            // Push the target number to the stack
            stack.add("Push");
            // Move to the next integer in the stream
            i++;
        }
        // Return the stack operations
        return stack;
    }

    public static void main(String[] args) {
        int[] target = {1,2,3};
        int n = 3;
        List<String> ans = buildArray(target, n);
        System.out.println(ans);
    }
}