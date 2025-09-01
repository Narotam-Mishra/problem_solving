
// Problem link - https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2025-09-01

// Custom max-heap implementation for storing [gain, classIndex] pairs
class CustomMaxHeap {
  constructor() {
    this.arr = [];
  }

  // Utility method to perform upHeapify operation while insertion into heap
  upHeapify(idx) {
    // idx represents the index to start upheapify from
    while (idx > 0) {
      // Till the time index 'idx' doesn't reach the root
      let pi = Math.floor((idx - 1) / 2);
      
      // Compare based on gain (first element of array)
      if (this.arr[pi][0] < this.arr[idx][0]) {
        // Parent gain is smaller than current element's gain
        
        // Swap the parent and child
        let temp = this.arr[pi];
        this.arr[pi] = this.arr[idx];
        this.arr[idx] = temp;

        idx = pi;
      } else {
        // Everything is good, we have max-heap property maintained
        break;
      }
    }
  }

  // Utility method to insert [gain, classIndex] into heap
  insert(data) {
    // Step 1 - Insert data into array (heap)
    this.arr.push(data);

    // Step 2 - Upheapify to maintain max-heap property
    this.upHeapify(this.arr.length - 1);
  }

  // Utility method to perform downHeapify operation while deletion from heap
  downHeapify(idx) {
    while (idx < this.arr.length) {
      // Step 1 - Calculate left and right child index
      let lcIdx = 2 * idx + 1;
      let rcIdx = 2 * idx + 2;

      // Assume root is max element index
      let maxElementIdx = idx;

      // Compare gains (first element of arrays)
      if (lcIdx < this.arr.length && this.arr[maxElementIdx][0] < this.arr[lcIdx][0]) {
        // Left child exists and has maximum gain
        maxElementIdx = lcIdx;
      }

      if (rcIdx < this.arr.length && this.arr[maxElementIdx][0] < this.arr[rcIdx][0]) {
        // Right child exists and has maximum gain
        maxElementIdx = rcIdx;
      }

      // After above comparison we found the maximum element
      if (idx === maxElementIdx) {
        // If root element index 'idx' is still maximum element, then stop
        break;
      } else {
        // Otherwise swap current element with maxElementIdx's element
        let temp = this.arr[idx];
        this.arr[idx] = this.arr[maxElementIdx];
        this.arr[maxElementIdx] = temp;

        // Now current element's index 'idx' becomes maxElementIdx
        idx = maxElementIdx;
      }
    }
  }

  // Utility method to remove and return the maximum element from heap
  remove() {
    // Corner case: empty heap
    if (this.arr.length === 0) return null;
    
    // Single element case
    if (this.arr.length === 1) return this.arr.pop();

    // Step 1 - Store the root (maximum element) to return
    const maxElement = this.arr[0];
    
    // Step 2 - Move last element to root
    this.arr[0] = this.arr[this.arr.length - 1];
    
    // Step 3 - Remove the last element
    this.arr.pop();

    // Step 4 - Downheapify to maintain max-heap property
    this.downHeapify(0);
    
    return maxElement;
  }

  // Utility method to find top of heap without removing
  peek() {
    return this.arr.length === 0 ? null : this.arr[0];
  }

  // Utility method to get size of max heap
  size() {
    return this.arr.length;
  }
}

let maxAverageRatio = function (classes, extraStudents) {
  // get the number of classes we need to work with
  const n = classes.length;

  // step 1 - create a max-heap using PriorityQueue with custom comparator
  // we will store arrays: [gain, class_index]
  // max heap: higher gain has priority
  const pq = new CustomMaxHeap();

  // step 2 - calculate initial gain for each class and add to priority queue
  for (let i = 0; i < n; i++) {
    // calculate current pass ratio for class i
    const currRatio = classes[i][0] / classes[i][1];

    // calculate what the pass ratio would be if we add 1 extra student
    const newRatio = (classes[i][0] + 1) / (classes[i][1] + 1);

    // calculate the improvement (delta/gain) we get by adding 1 student
    const gain = newRatio - currRatio;

    // add to max-heap: {gain, class_index}
    pq.insert([gain, i]);
  }

  // step 3 - greedily assign each extra student to the class with maximum gain
  while (extraStudents > 0) {
    extraStudents--;

    // get the class that currently offers maximum gain
    const curr = pq.remove();

    // gain value
    let gain = curr[0];

    // index of the class with max gain
    const idx = curr[1];

    // step 4 - add one extra student to the selected class
    classes[idx][0]++; // increment passing students
    classes[idx][1]++; // increment total students

    // step 5 - recalculate the gain for this class after adding the student
    const currRatio = classes[idx][0] / classes[idx][1];
    const newRatio = (classes[idx][0] + 1) / (classes[idx][1] + 1);

    // calculate updated gain for this class
    gain = newRatio - currRatio;

    // step 6 - put the class back into priority queue with its new gain
    pq.insert([gain, idx]);
  }

  // step 7 - calculate the final average pass ratio across all classes
  let res = 0.0;
  for (let i = 0; i < n; i++) {
    res += classes[i][0] / classes[i][1];
  }

  // step 8 - return average = total_sum_of_ratios / number_of_classes
  return res / n;
};

// const classes = [[1,2],[3,5],[2,2]], extraStudents = 2;

const classes = [[2,4],[3,9],[4,5],[2,10]], extraStudents = 4;
console.log(maxAverageRatio(classes, extraStudents));