
// Problem link - https://leetcode.com/problems/implement-queue-using-stacks/

#include<bits/stdc++.h>
using namespace std;

// Approach - 1 (enqueue efficient)
class MyQueue1 {
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue1() {}
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        if(st2.empty()){
            transferStack1ToStack2();
        }
        int top = st2.top();
        st2.pop();
        return top;
    }
    
    int peek() {
        if(st2.empty()){
            transferStack1ToStack2();
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty() && st2.empty();
    }

private:
    void transferStack1ToStack2(){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
    } 
};

// Approach - 2 (dequeue efficient)
class MyQueue {
    stack<int> st1;
    stack<int> st2;

public:
    MyQueue() {}
    
    void push(int x) {
        // Move all elements from stack2 to stack1
        while (st2.size() > 0){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
        // Move all elements back to stack2
        while (st1.size() > 0) {
            st2.push(st1.top());
            st1.pop();
        }
    }
    
    int pop() {
        int t = st2.top();
        st2.pop();
        return t;
    }
    
    int peek() {
        return st2.top();
    }
    
    bool empty() {
        return st2.empty();
    }
};

int main() {
    // Create an instance of MyQueue (PushEfficient)
    MyQueue queue;

    // Push some elements into the queue
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);

    // Print the queue
    cout << "Queue after pushing elements: ";

    // Peek at the front element
    cout << "Peek: " << queue.peek() << endl;

    // Pop elements from the queue
    cout << "Pop: " << queue.pop() << endl;
    cout << "Pop: " << queue.pop() << endl;

    return 0;
}