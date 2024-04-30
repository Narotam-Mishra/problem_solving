
// Problem link - https://leetcode.com/problems/design-front-middle-back-queue/

#include<bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    vector<int> queue;
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        // push element at front of queue using insert() method
        queue.insert(queue.begin(), val);
    }
    
    void pushMiddle(int val) {
        // push element at the middle of queue using insert() method
        int midIdx = floor(queue.size() / 2);
        queue.insert(queue.begin() + midIdx, val);
    }
    
    void pushBack(int val) {
        // push element at the back of queue using push_back() method.
        queue.push_back(val);
    }
    
    int popFront() {
        // pop element from the back of queue using front() & erase() method
        if(queue.empty()) return -1;
        int val = queue.front();
        queue.erase(queue.begin());
        return val;
    }
    
    int popMiddle() {
        // pop middle element from the queue using floor() & erase() method
        if(queue.empty()) return -1;
        int midIdx = floor(queue.size() / 2);
        if(queue.size() % 2 == 0) midIdx--;
        int val = queue[midIdx];
        queue.erase(queue.begin() + midIdx);
        return val;
    }
    
    int popBack() {
        // pop back/rear element from the queue using back() & pop_back() method
        if(queue.empty()) return -1;
        int val = queue.back();
        queue.pop_back();
        return val;
    }
};

int main(){
    FrontMiddleBackQueue qu;

    qu.pushFront(1);
    qu.pushBack(2);
    qu.pushMiddle(3);
    qu.pushMiddle(4);

    cout<<qu.popFront()<<endl;
    cout<<qu.popMiddle()<<endl;
    cout<<qu.popMiddle()<<endl;
    cout<<qu.popBack()<<endl;
    cout<<qu.popFront()<<endl;
    return 0;
}