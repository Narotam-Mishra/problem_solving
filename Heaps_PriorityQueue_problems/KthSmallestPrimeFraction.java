
// Problem link - https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

package Heaps_PriorityQueue_problems;

import java.util.*;

class Triplet {
    int nm, dm;
    double val;

    public Triplet(int nm, int dm, double val){
        this.nm = nm;
        this.dm = dm;
        this.val = val;
    }
}

class CustomMinHeapUtils {
    private ArrayList<Triplet> arr;
    private java.util.Comparator<Triplet> cmp;

    public CustomMinHeapUtils(java.util.Comparator<Triplet> cmp) {
        this.arr = new ArrayList<>();
        this.cmp = cmp;
    }

    // Utility method to perform upHeapify operation while insertion into heap
    private void upHeapify(int idx) {
        while (idx > 0) {
            int pi = (idx - 1) / 2;
            if (cmp.compare(arr.get(pi), arr.get(idx)) > 0) {
                Triplet temp = arr.get(pi);
                arr.set(pi, arr.get(idx));
                arr.set(idx, temp);
                idx = pi;
            } else {
                break;
            }
        }
    }

    // Utility method to insert into heap
    public void insert(Triplet data) {
        arr.add(data);
        upHeapify(arr.size() - 1);
    }

    // Utility method to perform downHeapify operation while deletion into heap
    private void downHeapify(int idx) {
        while (idx < arr.size()) {
            int lcIdx = 2 * idx + 1;
            int rcIdx = 2 * idx + 2;
            int minIdx = idx;

            if (lcIdx < arr.size() && cmp.compare(arr.get(lcIdx), arr.get(minIdx)) < 0) {
                minIdx = lcIdx;
            }

            if (rcIdx < arr.size() && cmp.compare(arr.get(rcIdx), arr.get(minIdx)) < 0) {
                minIdx = rcIdx;
            }

            if (minIdx == idx) {
                break;
            } else {
                Triplet temp = arr.get(idx);
                arr.set(idx, arr.get(minIdx));
                arr.set(minIdx, temp);
                idx = minIdx;
            }
        }
    }

    // Utility method to delete from heap
    public void remove() {
        if (arr.size() == 0) return;
        Triplet temp = arr.get(0);
        arr.set(0, arr.get(arr.size() - 1));
        arr.set(arr.size() - 1, temp);
        arr.remove(arr.size() - 1);
        downHeapify(0);
    }

    // Utility method to find top element of heap
    public Triplet peek() {
        return arr.size() == 0 ? null : arr.get(0);
    }

    // Utility method to get size of heap
    public int size() {
        return arr.size();
    }
}

public class KthSmallestPrimeFraction {

    public static int[] kthSmallestPrimeFraction(int[] arr, int k) {
        int size = arr.length;

        // min-heap using priority queue
        PriorityQueue<Triplet> pq = new PriorityQueue<>(new Comparator<Triplet>() {
            @Override
            public int compare(Triplet t1, Triplet t2){
                return Double.compare(t1.val, t2.val);
            }
        });

        // iterate over arr elements and insert values into heap
        for(int i=1; i<size; i++){
            pq.offer(new Triplet(0, i, (double) arr[0]/arr[i]));
        }

        // perform k-1 removals
        for(int i=0; i<k-1; i++){
            // get top samllest fraction value from heap
            Triplet tripVal = pq.poll();

            if(tripVal.nm+1 < arr.length){
                pq.offer(new Triplet(tripVal.nm+1, tripVal.dm, (double) arr[tripVal.nm+1]/arr[tripVal.dm]));
            }
        }

        // return the kth smallest fraction
        Triplet top =  pq.poll();
        return new int []{ arr[top.nm], arr[top.dm]};
    }
    
    public static int[] kthSmallestPrimeFraction1(int[] arr, int k) {
        // created min-heap 
        CustomMinHeapUtils hp = new CustomMinHeapUtils((t1, t2) -> Double.compare(t1.val, t2.val));
        
        // iterate over arr elements and insert values into heap
        for(int i=1; i<arr.length; i++){
            hp.insert(new Triplet(0, i, (double) arr[0] / arr[i]));
        }

        // Perform k-1 removals
        for(int i=0; i<k-1; i++){
            // get top samllest fraction value from heap
            Triplet tripVal = hp.peek();
            hp.remove();

            if(tripVal.nm + 1 < arr.length){
                hp.insert(new Triplet(tripVal.nm+1, tripVal.dm, (double) arr[tripVal.nm+1] / arr[tripVal.dm]));
            }
        }
        // return the kth smallest fraction
        Triplet top = hp.peek();
        return new int[] { arr[top.nm], arr[top.dm]};
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 3, 5};
        int k = 3;
        int[] res = kthSmallestPrimeFraction(arr, k);
        System.out.println("["+res[0]+","+res[1]+"]");
    }
}
