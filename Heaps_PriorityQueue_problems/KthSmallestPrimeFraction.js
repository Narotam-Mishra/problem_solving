
// Problem link - https://leetcode.com/problems/k-th-smallest-prime-fraction/description/

class CustomGenericHeap {
  constructor(cmp) {
    this.arr = [];
    this.cmp = cmp;
  }

  // utility method to perfrom upHeapify operation while insertion into heap
  upHeapify(idx) {
    // idx represents the index of start upheapify from
    while (idx > 0) {
      // till the time index 'idx' doesn't reach the root
      let pi = Math.floor((idx - 1) / 2);
      if (this.cmp(this.arr[pi], this.arr[idx])) {
        // parent is smallert than current element

        // swap the parent and child
        let temp = this.arr[pi];
        this.arr[pi] = this.arr[idx];
        this.arr[idx] = temp;

        idx = pi;
      } else {
        // everything is good, we have max-Heap
        break;
      }
    }
  }

  // utility method to insert into heap
  insert(data) {
    //step1 - insert data into array(heap)
    this.arr.push(data);

    //step2 - upheapify(insertion)
    this.upHeapify(this.arr.length - 1);
  }

  // utility method to perfrom downHeapify operation while deletion into heap
  downHeapify(idx) {
    while (idx < this.arr.length) {
      // step1 - calculate left and right child index
      let lcIdx = 2 * idx + 1;
      let rcIdx = 2 * idx + 2;

      // assume root is max element index
      let maxElementIdx = idx;

      // compare parent and child
      if (
        lcIdx < this.arr.length &&
        this.cmp(this.arr[maxElementIdx], this.arr[lcIdx])
      ) {
        // left child index exist and it has maximum element also
        maxElementIdx = lcIdx;
      }

      if (
        rcIdx < this.arr.length &&
        this.cmp(this.arr[maxElementIdx], this.arr[rcIdx])
      ) {
        // right child idx exist and it has maximum element also
        maxElementIdx = rcIdx;
      }

      // after above comparison we found the maximum element
      if (idx === maxElementIdx) {
        // if root' element index i.e 'idx' is still maximum element, then don't go further
        break;
      } else {
        // otherwise swap current element with maxElementIdx's element
        let temp = this.arr[idx];
        this.arr[idx] = this.arr[maxElementIdx];
        this.arr[maxElementIdx] = temp;

        // now current element's index 'idx' becomes maxElementIdx
        idx = maxElementIdx;
      }
    }
  }

  // utility method to delete into heap
  remove() {
    // corner case:
    if (this.arr.length === 0) return;
    // remove the priority wise element from heap

    // step1 - swap the root with last element
    let temp = this.arr[0];
    this.arr[0] = this.arr[this.arr.length - 1];
    this.arr[this.arr.length - 1] = temp;

    // step2 - remove the last element
    this.arr.pop();

    //step3 - downheapify(removal)
    this.downHeapify(0);
  }

  // utility method to find top element of heap
  peek() {
    return this.arr.length === 0 ? null : this.arr[0];
  }

  // utility method to get size of max heap
  size() {
    return this.arr.length;
  }
}

class Triplet {
    constructor(nm, dm, val){
        this.nm = nm;
        this.dm = dm;
        this.val = val;
    }
}

let kthSmallestPrimeFraction = function(arr, k) {
    let size = arr.length;

    // created min-heap 
    const hp = new CustomGenericHeap((t1, t2) => {
        return t1.val > t2.val;
    })

    // iterate on arr elements and insert values into heap
    for(let i=0; i<size; i++){
        hp.insert(new Triplet( 0, i, arr[0]/arr[i]));
    }

    // since we need to find kth smallest fraction
    // so we do k-1 removals
    for(let i=0; i<k-1; i++){
        // get top value from heap
        const tripVal = hp.peek();

        // remove value from heap 
        hp.remove();

        // if the index exist then only we can insert
        if(tripVal.nm < arr.length - 1){
            // insert next fraction value (in next insertion denominator of fraction will be fixed)
            hp.insert(new Triplet(tripVal.nm+1, tripVal.dm, arr[tripVal.nm+1] / arr[tripVal.dm]));
        }
    }
    // after kth iteration we can return kth smallest fraction
    return [arr[hp.peek().nm], arr[hp.peek().dm]];
};

let arr = [1, 2, 3, 5], k = 3;
const res = kthSmallestPrimeFraction(arr,k);
console.log(res);