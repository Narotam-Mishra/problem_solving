
// Problem link - https://leetcode.com/problems/k-closest-points-to-origin/description/

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

class Point {
    constructor(xi, yi){
        this.x = xi;
        this.y = yi;
        // store euclidean distance from origin
        this.distance = Math.sqrt(xi*xi + yi*yi);
    }
}

let kClosest = function(points, k) {
    // created min-heap
    let hp = new CustomGenericHeap((pointA, pointB) => {
        // a > b for min heap
        return pointA.distance > pointB.distance;
    });

    // iterate on all given (x,y) co-oridnates
    for(let i=0; i<points.length; i++){
        // for the current (x,y) create Point object
        const p = new Point(points[i][0], points[i][1]);
        // find distance and insert into min-heap
        hp.insert(p);
    }

    let res = [];
    while(k > 0){
        // get x and y co-ordinates from top of min-heap
        let val = [hp.peek().x, hp.peek().y];
        // store (x,y) points in result 'res' array
        res.push(val);
        // remove top points to get further points
        hp.remove();
        k--;
    }
    return res;
};

let points = [[3,3],[5,-1],[-2,4]], k = 2;

// let points = [[1,3],[-2,2]], k = 1;
console.log(kClosest(points, k));