
// Problem link - https://leetcode.com/problems/maximum-frequency-stack/description/

package Stack_Problems;

import java.util.*;

class FreqStack {
    // frequency map to maintain frequency of each elements
    private Map<Integer, Integer> freqMap;
    // stackMap to store stack of elements for each frequency
    private Map<Integer, Stack<Integer>> stackMap;
    // to track max frequency
    private int maxFrq;

    public FreqStack() {
        freqMap = new HashMap<>();
        stackMap = new HashMap<>();
        maxFrq = 0;
    }
    
    public void push(int val) {
        // 1). Increment frequency
        if(!freqMap.containsKey(val)){
            freqMap.put(val, 1);
        }else{
            // 2). Update frequency map
            freqMap.put(val, freqMap.get(val) + 1);
        }

        // 3). Update maxFreq if needed
        maxFrq = Math.max(maxFrq, freqMap.get(val));

        // 4). Initialize stack for this frequency if not exists
        // get current frequency
        int curFrq = freqMap.get(val);
        if(!stackMap.containsKey(curFrq)){
            stackMap.put(curFrq, new Stack<>());
        }

        // 5). Push the element to the stack for this frequency
        stackMap.get(curFrq).push(val);
    }
    
    public int pop() {
        // 1). Get the stack with maximum frequency
        Stack<Integer> maxFrqStack = stackMap.get(maxFrq);

        //2). Pop the top element from the stack
        int poppedElement = maxFrqStack.pop();

        //3). decrease maxFreq if the stack becomes empty
        if(maxFrqStack.size() == 0){
            maxFrq--;
        }

        //4). Update frequency map
        freqMap.put(poppedElement, freqMap.get(poppedElement)-1);

        // 5). returned popped element
        return poppedElement;
    }
}

public class MaxFrequencyStack {
    public static void main(String[] args) {
        FreqStack st = new FreqStack();
        st.push(5);
        st.push(7);
        st.push(5);
        st.push(7);
        st.push(4);
        st.push(5);
        System.out.println(st.pop()); // Output: 5
        System.out.println(st.pop()); // Output: 7
        System.out.println(st.pop()); // Output: 5
        System.out.println(st.pop()); // Output: 4
    }
}