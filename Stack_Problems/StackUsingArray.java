
// Design your own stack using Array

package Stack_Problems;

import java.util.ArrayList;

class CustomStack{
    private ArrayList<Integer> arr;

    // constructor
    public CustomStack(){
        arr = new ArrayList<>();
    }

    // Method to push element onto the stack
    public void push(int element){
        arr.add(element);
    }

    // Method to pop element from the stack
    public void pop(){
        if(!arr.isEmpty()){
            arr.remove(arr.size() - 1);
        }else{
            System.out.println("Your Stack is already empty!!");
        }
    }

    // Method to get the top element of the stack
    public int top(){
        if(!arr.isEmpty()){
            return arr.get(arr.size() - 1);
        }
        return -1;
    }

    // Method to check if the stack is empty
    public boolean isEmpty(){
        return arr.isEmpty();
    }
}

public class StackUsingArray {
    public static void main(String[] args) {
        CustomStack st = new CustomStack();
        st.push(10);
        st.push(20);
        st.push(40);
        st.push(50);
        st.push(70);
        System.out.println(st.top());
        st.pop();
        System.out.println(st.top());
        System.out.println(st.isEmpty());
    }
}