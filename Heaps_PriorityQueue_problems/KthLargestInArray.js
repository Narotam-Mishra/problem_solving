
// Problem link - https://leetcode.com/problems/kth-largest-element-in-an-array/description/

class MaxHeap {
  constructor() {
    this.arr = [];
  }

  // utility method to perfrom upHeapify operation while insertion into heap
  upHeapify(idx) {
    // idx represents the index of start upheapify from
    while (idx > 0) {
      // till the time index 'idx' doesn't reach the root
      let pi = Math.floor((idx - 1) / 2);
      if (this.arr[pi] < this.arr[idx]) {
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

      if (
        lcIdx < this.arr.length &&
        this.arr[maxElementIdx] < this.arr[lcIdx]
      ) {
        // left child index exist and it has maximum element also
        maxElementIdx = lcIdx;
      }

      if (
        rcIdx < this.arr.length &&
        this.arr[maxElementIdx] < this.arr[rcIdx]
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
    // remove the highest priority element from heap

    // step1 - swap the root with last element
    let temp = this.arr[0];
    this.arr[0] = this.arr[this.arr.length - 1];
    this.arr[this.arr.length - 1] = temp;

    // step2 - remove the last element
    this.arr.pop();

    //step3 - downheapify(removal)
    this.downHeapify(0);
  }

  // utility method to find top of heap
  peek() {
    return this.arr.length === 0 ? null : this.arr[0];
  }

  // utility method to get size of max heap
  size() {
    return this.arr.length;
  }
}
  
let findKthLargest = function (nums, k) {
  let hpMax = new MaxHeap();

  for (let num of nums) {
    hpMax.insert(num);
  }

  let kthMax = -1;
  while (k > 0) {
    kthMax = hpMax.peek();
    hpMax.remove();
    k--;
  }
  return kthMax;
};

// let arr = [3,2,1,5,6,4], k = 2;

let arr = [3,2,3,1,2,4,5,5,6], k = 4;

console.log(findKthLargest(arr, k));