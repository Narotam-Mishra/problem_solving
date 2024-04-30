
// Problem link - https://leetcode.com/problems/design-front-middle-back-queue/

package Queue_Problems;

import java.util.ArrayList;
import java.util.List;

class FrontMiddleBackQueue {
    private List<Integer> queue;

    public FrontMiddleBackQueue() {
        queue = new ArrayList<>();
    }
    
    public void pushFront(int val) {
        // push element at front of queue using add() method
        queue.add(0,val);
    }
    
    public void pushMiddle(int val) {
        // push element at the middle of queue using add() method
        int midIdx = (int) Math.floor(queue.size() / 2.0);
        queue.add(midIdx, val);
    }
    
    public void pushBack(int val) {
        // push element at the back of queue using add() method.
        queue.add(val);
    }
    
    public int popFront() {
        // pop element from the back of queue using get() & remove() method
        if(queue.isEmpty()) return -1;
        int val = queue.get(0);
        queue.remove(0);
        return val;
    }
    
    public int popMiddle() {
        // pop middle element from the queue using get() & remove() method
        if(queue.isEmpty()) return -1;
        int midIdx = (int) Math.floor(queue.size() / 2.0);
        if(queue.size() % 2 == 0) midIdx--;
        int val = queue.get(midIdx);
        queue.remove(midIdx);
        return val;
    }
    
    public int popBack() {
        // pop back/rear element from the queue using get() & size() method
        if(queue.isEmpty()) return -1;
        int val = queue.get(queue.size() - 1);
        queue.remove(queue.size() - 1);
        return val;
    }
}

public class DesignQueue {
    public static void main(String[] args) {
        FrontMiddleBackQueue qu = new FrontMiddleBackQueue();
        qu.pushFront(1);
        qu.pushBack(2);
        qu.pushMiddle(3);
        qu.pushMiddle(4);

        System.out.println(qu.popFront());
        System.out.println(qu.popMiddle());
        System.out.println(qu.popMiddle());
        System.out.println(qu.popBack());
        System.out.println(qu.popFront());
    }
}
