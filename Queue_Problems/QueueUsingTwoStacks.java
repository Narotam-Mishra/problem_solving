
// Problem link - https://leetcode.com/problems/implement-queue-using-stacks/

package Queue_Problems;

import java.util.Stack;

// Approach - 1 (enqueue efficient)
class MyQueue1 {
    Stack<Integer> st1;
    Stack<Integer> st2;

    public MyQueue1() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }
    
    public void push(int x) {
        st1.push(x);
    }
    
    public int pop() {
        if(st2.isEmpty()){
            transferStack1ToStack2();
        }
        return st2.pop();
    }
    
    public int peek() {
        if(st2.isEmpty()){
            transferStack1ToStack2();
        }
        return st2.peek();
    }
    
    public boolean empty() {
        return st1.isEmpty() && st2.isEmpty();
    }

    private void transferStack1ToStack2(){
        while (!st1.isEmpty()) {
            st2.push(st1.pop());
        }
    }
}

// Approach - 2 (dequeue efficient)
class MyQueue {
    Stack<Integer> st1;
    Stack<Integer> st2;

    public MyQueue() {
        st1 = new Stack<>();
        st2 = new Stack<>();
    }
    
    public void push(int x) {
        // Move all elements from stack2 to stack1
        while (st2.size() > 0) {
            st1.push(st2.pop());
        }

        st1.push(x);

        // Move all elements back to stack2
        while (st1.size() > 0) {
            st2.push(st1.pop());
        }
    }
    
    public int pop() {
        return st2.pop();
    }
    
    public int peek() {
        return st2.peek();
    }
    
    public boolean empty() {
        return st2.isEmpty();
    }
}

public class QueueUsingTwoStacks {
    public static void main(String[] args) {
        // Create an instance of MyQueue (PushEfficient)
        MyQueue queue = new MyQueue();

        // Push some elements into the queue
        queue.push(1);
        queue.push(2);
        queue.push(3);
        queue.push(4);

        // Peek at the front element
        System.out.println("Peek: " + queue.peek());

        // Pop elements from the queue
        System.out.println("Pop: " + queue.pop());
        System.out.println("Pop: " + queue.pop());
    }
}