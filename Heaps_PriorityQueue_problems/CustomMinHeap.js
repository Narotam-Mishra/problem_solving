
// Implement your own min-Heap with all required methods

class CustomMinHeap {
  constructor() {
    this.arr = [];
  }

  // Utility method to perform upHeapify operation while insertion into heap
  upHeapify(idx) {
    // idx represents the index of start upheapify from
    while (idx > 0) {
      // till the time index 'idx' doesn't reach the root
      let pi = Math.floor((idx - 1) / 2);
      if (this.arr[pi] > this.arr[idx]) {
        // parent is greater than current element

        // swap the parent and child
        let temp = this.arr[pi];
        this.arr[pi] = this.arr[idx];
        this.arr[idx] = temp;

        idx = pi;
      } else {
        // everything is good, we have min-Heap
        break;
      }
    }
  }

  // Utility method to insert into heap
  insert(data) {
    // Step1 - insert data into array(heap)
    this.arr.push(data);

    // Step2 - upheapify(insertion)
    this.upHeapify(this.arr.length - 1);
  }

  // Utility method to perform downHeapify operation while deletion into heap
  downHeapify(idx) {
    while (idx < this.arr.length) {
      // Step1 - calculate left and right child index
      let lcIdx = 2 * idx + 1;
      let rcIdx = 2 * idx + 2;

      // Assume root is min element index
      let minElementIdx = idx;

      if (
        lcIdx < this.arr.length &&
        this.arr[minElementIdx] > this.arr[lcIdx]
      ) {
        // left child index exist and it has minimum element also
        minElementIdx = lcIdx;
      }

      if (
        rcIdx < this.arr.length &&
        this.arr[minElementIdx] > this.arr[rcIdx]
      ) {
        // right child idx exist and it has minimum element also
        minElementIdx = rcIdx;
      }

      // After above comparison we found the minimum element
      if (idx === minElementIdx) {
        // if root's element index i.e 'idx' is still minimum element, then don't go further
        break;
      } else {
        // otherwise swap current element with minElementIdx's element
        let temp = this.arr[idx];
        this.arr[idx] = this.arr[minElementIdx];
        this.arr[minElementIdx] = temp;

        // now current element's index 'idx' becomes minElementIdx
        idx = minElementIdx;
      }
    }
  }

  // Utility method to delete into heap
  remove() {
    // Corner case:
    if (this.arr.length === 0) return;
    // remove the highest priority element from heap

    // Step1 - swap the root with last element
    let temp = this.arr[0];
    this.arr[0] = this.arr[this.arr.length - 1];
    this.arr[this.arr.length - 1] = temp;

    // Step2 - remove the last element
    this.arr.pop();

    // Step3 - downheapify(removal)
    this.downHeapify(0);
  }

  // Utility method to display heap's elements
  display() {
    console.log("Min Heap's elements: ", this.arr);
  }

  // Utility method to find top of heap
  peek() {
    return this.arr.length === 0 ? null : this.arr[0];
  }

  // Utility method to get size of min heap
  size() {
    return this.arr.length;
  }
}

let minHp = new CustomMinHeap();
minHp.insert(9);
minHp.insert(19);
minHp.insert(12);
minHp.insert(39);
minHp.insert(29);
minHp.insert(2);
minHp.insert(-9);
minHp.insert(6);

minHp.display();

minHp.remove();
minHp.display();
  