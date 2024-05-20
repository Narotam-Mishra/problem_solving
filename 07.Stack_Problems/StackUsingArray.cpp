
// Design your own stack using Array

#include<bits/stdc++.h>
using namespace std;

class Stack{
private:
    vector<int> arr;

public:
    // constructor
    Stack(){}

    // Method to push element onto the stack
    void push(int element){
        arr.push_back(element);
    }

    // Method to pop element from the stack
    void pop(){
        if(!arr.empty()){
            arr.pop_back();
        }else{
            cout<<"Your Stack is empty!"<<endl;
        }
    }

    // Method to get the top element of the stack
    int top(){
        if(!arr.empty()){
            return arr.back();
        }
        return -1;
    }

    // Method to check if the stack is empty
    bool isEmpty(){
        return arr.empty();
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(40);
    st.push(50);
    st.push(70);
    cout << st.top() <<endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.isEmpty() << endl;
    return 0;
}