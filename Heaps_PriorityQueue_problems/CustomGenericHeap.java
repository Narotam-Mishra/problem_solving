
// Implement your own Heaps with all required methods

package Heaps_PriorityQueue_problems;

import java.util.*;

class GenericHeap<T>{
    private ArrayList<T> arr;
    private java.util.Comparator<T> cmp;

    public GenericHeap(java.util.Comparator<T> cmp){
        this.arr = new ArrayList<>();
        this.cmp = cmp;
    }

    // utility method to perfrom upHeapify operation while insertion into heap
    private void upHeapify(int idx){
        // idx represents the index of start upheapify from
        while(idx > 0){
            // till the time index 'idx' doesn't reach the root
            int pi = (idx - 1)/2;
            if(cmp.compare(arr.get(pi), arr.get(idx)) < 0){
                // compare parent and child

                // swap the parent and child
                T temp = arr.get(pi);
                arr.set(pi, arr.get(idx));
                arr.set(idx, temp);

                idx = pi;
            }else{
                // everything is good, we have generic-Heap
                break;
            }
        }
    }

    // utility method to insert into heaps
    public void insert(T data){
        //step1 - insert data into array(heap)
        arr.add(data);

        //step2 - upheapify(insertion)
        upHeapify(arr.size() - 1);
    }

    // utility method to perfrom downHeapify operation while deletion into heap
    private void downHepify(int idx){
        while(idx < arr.size()){
            // step1 - calculate left and right child index
            int lcIdx = 2 * idx + 1;
            int rcIdx = 2 * idx + 2;

            // assume root is max element index
            int maxElementIdx = idx;

            // compare parent and child
            if(lcIdx < arr.size() && cmp.compare(arr.get(maxElementIdx), arr.get(lcIdx)) < 0){
                // left child index exist and it has maximum element also
                maxElementIdx = lcIdx;
            }

            if(rcIdx < arr.size() && cmp.compare(arr.get(maxElementIdx), arr.get(rcIdx)) < 0){
                // right child idx exist and it has maximum element also
                maxElementIdx = rcIdx;
            }

            // after above comparison we found the maximum element
            if(idx == maxElementIdx){
                // if root' element index i.e 'idx' is still maximum element, then don't go further
                break;
            }else{
                // otherwise swap current element with maxElementIdx's element
                T temp = arr.get(idx);
                arr.set(idx, arr.get(maxElementIdx));
                arr.set(maxElementIdx, temp);

                // now current element's index 'idx' becomes maxElementIdx
                idx = maxElementIdx;
            }
        }
    }

    // utility method to remove element from heap
    public void remove(){
        // corner case:
        if(arr.size() == 0) return;

        // remove the priority wise element from heap
        // step1 - swap the root with last element
        T temp = arr.get(0);
        arr.set(0, arr.get(arr.size() - 1));
        arr.set(arr.size() - 1, temp);

        // step2 - remove the last element
        arr.remove(arr.size() - 1);

        //step3 - downheapify(removal)
        downHepify(0);
    }
    
    // utility method to display heap's elements
    public void display() {
        System.out.println("Heap's elements: " + arr);
    }

    // utility method to find top element of heap
    public T peek() {
        return arr.size() == 0 ? null : arr.get(0);
    }

    // utility method to get size of heap
    public int size() {
        return arr.size();
    }
}

public class CustomGenericHeap {
    
    public static void main(String[] args) {
        // a - b ---> Max Heap,  b - a ---> Min Heap
        GenericHeap<Integer> hp = new GenericHeap<>((a, b) -> a - b);
        hp.insert(9);
        hp.insert(19);
        hp.insert(12);
        hp.insert(39);
        hp.insert(29);
        hp.insert(2);
        hp.insert(-9);
        hp.insert(6);
        hp.display();

        System.out.println("Peek: " + hp.peek());
        hp.remove();
        hp.display();
        System.out.println("Peek: " + hp.peek());
        System.out.println("Heap's size: " + hp.size());
    }
}