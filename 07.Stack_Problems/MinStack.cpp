
// Problem link - https://leetcode.com/problems/min-stack/description/

#include<bits/stdc++.h>
using namespace std;

class MinStack{
private:
    stack<int> st;
    stack<int> mst;

public:
    MinStack() {}

    void push(int val) {
        st.push(val);
        // If the minStack is empty or the new value is less than or equal to the current minimum,
        // then push the new value onto the minStack
        if(mst.empty() || val <= getMin()){
            mst.push(val);
        }
    }
    
    void pop() {
        // If the value being popped is the current minimum, 
        // also pop it from the minStack
        if(st.top() == getMin()){
            mst.pop();
        }
        st.pop();
    }
    
    int top() {
        // Returns the top element of the stack without removing it
        return st.top();
    }
    
    int getMin() {
        // Retrieves the minimum element in the stack
        return mst.top();
    }

};

int main(){
    MinStack minst;
    minst.push(-2);
    minst.push(0);
    minst.push(-3);
    cout<<minst.getMin()<<endl; // return -3
    minst.pop();
    cout<<minst.top()<<endl;    // return 0
    cout<<minst.getMin() << endl; // return -2
    return 0;
}