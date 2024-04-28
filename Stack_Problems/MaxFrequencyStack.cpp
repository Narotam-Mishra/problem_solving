
// Problem link - https://leetcode.com/problems/maximum-frequency-stack/description/

#include<bits/stdc++.h>
using namespace std;

class FreqStack {
private:
    // frequency map to maintain frequency of each elements
    unordered_map<int, int> frqMap;
    // stackMap to store stack of elements for each frequency
    unordered_map<int, stack<int>> stackMap;
    // to track max frequency
    int maxFrq;
public:
    FreqStack() {
        maxFrq = 0;
    }
    
    void push(int val) {
        // 1). Increment frequency
        int frq = frqMap[val] + 1;

        // 2). Update frequency map
        frqMap[val] = frq;

        // 3). Update maxFreq if needed
        maxFrq = max(maxFrq, frq);

        // 4). Initialize stack for this frequency if not exists
        // 5). Push the element to the stack for this frequency
        stackMap[frq].push(val);
    }
    
    int pop() {
        // 1). Get the stack with maximum frequency
        stack<int>& maxFrqStack = stackMap[maxFrq];

        //2). Pop the top element from the stack
        int poppedElement = maxFrqStack.top();
        maxFrqStack.pop();

        // 3).decrease maxFreq if the stack becomes empty
        if(maxFrqStack.empty()){
            maxFrq--;
        }

        // 4). Update frequency map
        frqMap[poppedElement]--;

        // return popped element
        return poppedElement;
    }
};

int main(){
    FreqStack freqStack;
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(5);
    freqStack.push(7);
    freqStack.push(4);
    freqStack.push(5);
    cout<<freqStack.pop()<<endl; // Output: 5
    cout<<freqStack.pop()<<endl; // Output: 7
    cout<<freqStack.pop()<<endl; // Output: 5
    cout<<freqStack.pop()<<endl; // Output: 4
    return 0;
}