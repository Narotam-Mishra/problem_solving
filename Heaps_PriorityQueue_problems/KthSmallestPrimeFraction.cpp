
// Problem link - https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

#include<bits/stdc++.h>
using namespace std;

class Triplet {
public:
    int nm, dm;
    double val;

    Triplet(int nm, int dm, double val){
        this->nm = nm;
        this->dm = dm;
        this->val = val;
    }
};

// Custom comparator clss

class TripletComparator {
public:
    bool operator()(const Triplet& t1, const Triplet& t2) const {
        // comparison for min-heap
        return t1.val > t2.val;
    }
};

class CustomGenericHeap {
private:
    vector<Triplet> arr;
    function<bool(const Triplet&, const Triplet&)> cmp;

    void upHeapify(int idx) {
        while (idx > 0) {
            int pi = (idx - 1) / 2;
            if (cmp(arr[pi], arr[idx])) {
                swap(arr[pi], arr[idx]);
                idx = pi;
            } else {
                break;
            }
        }
    }

    void downHeapify(int idx) {
        while (idx < arr.size()) {
            int lcIdx = 2 * idx + 1;
            int rcIdx = 2 * idx + 2;
            int minIdx = idx;

            if (lcIdx < arr.size() && cmp(arr[minIdx], arr[lcIdx])) {
                minIdx = lcIdx;
            }

            if (rcIdx < arr.size() && cmp(arr[minIdx], arr[rcIdx])) {
                minIdx = rcIdx;
            }

            if (minIdx == idx) {
                break;
            } else {
                swap(arr[idx], arr[minIdx]);
                idx = minIdx;
            }
        }
    }

public:
    CustomGenericHeap(function<bool(const Triplet&, const Triplet&)> cmp) : cmp(cmp) {}

    void insert(Triplet data) {
        arr.push_back(data);
        upHeapify(arr.size() - 1);
    }

    void remove() {
        if (arr.empty()) return;
        swap(arr[0], arr[arr.size() - 1]);
        arr.pop_back();
        downHeapify(0);
    }

    Triplet peek() {
        return arr[0];
    }

    int size() {
        return arr.size();
    }
};

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    // min-heap using priority_queue
    priority_queue<Triplet, vector<Triplet>, TripletComparator> pq;

    // iterate over arr elements and insert values into heap
    for(int i=1; i<arr.size(); i++){
        pq.push(Triplet(0, i, (double) arr[0] / arr[i]));
    }

    // perform k-1 remove_all_extents
    for(int i=0; i<k-1; i++){
        // get top value from min priority queue
        Triplet tripVal = pq.top();
        pq.pop();

        // if the index exist then only we can insert
        if(tripVal.nm + 1 < arr.size()){
            pq.push(Triplet(tripVal.nm+1, tripVal.dm, (double) arr[tripVal.nm+1] / arr[tripVal.dm]));
        }
    }

    // return the kth smallest fraction
    Triplet top = pq.top();
    return { arr[top.nm], arr[top.dm]};
}

vector<int> kthSmallestPrimeFraction1(vector<int>& arr, int k) {
    //  created min-heap
    CustomGenericHeap hp([](const Triplet& t1, const Triplet& t2) {
        return t1.val > t2.val;
    });

    // iterate over arr elements and insert values into heap
    for(int i=1; i<arr.size(); i++){
        hp.insert(Triplet(0, i, (double) arr[0] / arr[i]));
    }

    // perform k-1 removals
    for(int i=0; i<k-1; i++){
        // get top value from heap
        Triplet tripVal = hp.peek();

        hp.remove();

        // if the index exist then only we can insert
        if(tripVal.nm + 1 < arr.size()){
            // insert next fraction value (in next insertion denominator of fraction will be fixed)
            hp.insert(Triplet(tripVal.nm+1, tripVal.dm, (double) arr[tripVal.nm+1] / arr[tripVal.dm]));
        }
    }

    // return the kth smallest fraction
    Triplet top = hp.peek();
    return { arr[top.nm], arr[top.dm]};
}

int main(){
    vector<int> arr = {1, 2, 3, 5};
    int k = 3;
    vector<int> res = kthSmallestPrimeFraction(arr, k);
    cout<<"["<<res[0]<<","<<res[1]<<"]";
    return 0;
}
