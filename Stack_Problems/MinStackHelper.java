
// Problem link - https://leetcode.com/problems/min-stack/description/

package Stack_Problems;

import java.util.Stack;

class MinStack {
    // Using two stacks, one for the main stack and 
    // another for tracking minimum elements
    private Stack<Integer> stack;
    private Stack<Integer> minStack;

    public MinStack() {
        stack = new Stack<>();
        minStack = new Stack<>();
    }
    
    public void push(int val) {
        // push value into stack
        stack.push(val);
        // If the minStack is empty or the new value is less than or equal to the current minimum,
        // push the new value onto the minStack
        if(minStack.isEmpty() || val <= getMin()){
            minStack.push(val);
        }
    }
    
    public void pop() {
        // If the value being popped is the current minimum, 
        // also pop it from the minStack
        if(stack.pop().equals(getMin())){
            minStack.pop();
        }
    }
    
    public int top() {
        // Returns the top element of the stack without removing it
        return stack.peek();
    }
    
    public int getMin() {
        // Retrieves the minimum element in the stack
        return minStack.peek();
    }
}

public class MinStackHelper{
    public static void main(String[] args) {
        MinStack minSt = new MinStack();
        minSt.push(-2);
        minSt.push(0);
        minSt.push(-3);
        System.out.println(minSt.getMin()); // return -3
        minSt.pop();
        System.out.println(minSt.top());    // return 0
        System.out.println(minSt.getMin()); // return -2
    }
}