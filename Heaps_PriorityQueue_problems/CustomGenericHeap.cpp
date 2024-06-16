
// Implement your own Heaps with all required methods

#include<bits/stdc++.h>
using namespace std;

template<typename T>
class CustomGenericHeap {
private:
    vector<T> arr;
    function<bool(const T&, const T&)> cmp;

    // utility method to perfrom upHeapify operation while insertion into heap
    void upHeapify(int idx){
        // idx represents the index of start upheapify from
        while(idx > 0){
            // till the time index 'idx' doesn't reach the root
            int pi = (idx - 1) / 2;

            // compare parent and child
            if(cmp(arr[pi], arr[idx])){
                // swap the parent and child
                swap(arr[pi], arr[idx]);
                idx = pi;
            }else{
                // everything is good, we have generic-Heap
                break;
            }
        }
    }

    // utility method to perfrom downHeapify operation while deletion into heap
    void downHepify(int idx){
        while(idx < arr.size()){
            // step1 - calculate left and right child index
            int lcIdx = 2 * idx + 1;
            int rcIdx = 2 * idx + 2;

            // assume root is max element index
            int maxElementIdx = idx;

            // compare parent and child
            if(lcIdx < arr.size() && cmp(arr[maxElementIdx], arr[lcIdx])) {
                // left child index exist and it has maximum element also
                maxElementIdx = lcIdx;
            }

            if(rcIdx < arr.size() && cmp(arr[maxElementIdx], arr[rcIdx])) {
                // right child idx exist and it has maximum element also
                maxElementIdx = rcIdx;
            }

            // after above comparison we found the maximum element
            if(idx == maxElementIdx){
                // if root' element index i.e 'idx' is still maximum element, then don't go further
                break;
            }else{
                // otherwise swap current element with maxElementIdx's element
                swap(arr[idx], arr[maxElementIdx]);

                // now current element's index 'idx' becomes maxElementIdx
                idx = maxElementIdx;
            }
        }
    }

public:
    CustomGenericHeap(function<bool(const T&, const T&)> cmp) : cmp(cmp) {}

    // utility method to insert into heaps
    void insert(T data){
        //step1 - insert data into array(heap)
        arr.push_back(data);

        //step2 - upheapify(insertion)
        upHeapify(arr.size() - 1);
    }

    // utility method to remove element from heap
    void remove(){
        // corner case:
        if(arr.empty()) return;

        // remove the priority wise element from heap
        // step1 - swap the root with last element
        swap(arr[0], arr[arr.size() - 1]);

        // step2 - remove the last element
        arr.pop_back();

        //step3 - downheapify(removal)
        downHepify(0);
    }

    // utility method to display heap's elements
    void display() {
        cout << "Heap's elements: ";
        for (const T& elem : arr) {
            cout<<elem<<" ";
        }
        cout<<endl;
    }

    // utility method to find top element of heap
    T peek(){
        return arr.empty() ? T() : arr[0];
    }

    // utility method to get size of heap
    int getSize(){
        return arr.size();
    }
};

int main(){
    //  a < b --> max Heap, a > b ---> min Heap
    CustomGenericHeap<int> hp([](const int& a, const int& b) { return a < b; });
    hp.insert(9);
    hp.insert(19);
    hp.insert(12);
    hp.insert(39);
    hp.insert(29);
    hp.insert(2);
    hp.insert(-9);
    hp.insert(6);
    hp.display();

    cout<<"Peek: "<<hp.peek()<<endl;
    hp.remove();
    hp.display();
    cout<<"Peek: "<<hp.peek()<<endl;
    cout<<"Size of Heap: "<<hp.getSize()<<endl;
}