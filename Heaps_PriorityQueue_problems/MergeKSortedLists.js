
// Problem link - https://leetcode.com/problems/merge-k-sorted-lists/description/

function ListNode(val, next) {
  this.val = val === undefined ? 0 : val;
  this.next = next === undefined ? null : next;
}

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

let mergeKLists = function(lists) {
    // resultant 'res' list and 123 is dummy head
    let res = new ListNode(123);

    // temp points to the resultant 'res' list
    let temp = res;

    // created min-heap of list
    let hp = new CustomGenericHeap((n1, n2) => {
        return n1.val  > n2.val;
    });

    // iterate on k-lists
    for(let i=0; i < lists.length; i++){
        if(lists[i] !== null){
            // will insert only non-empty ll
            // insert each node into heap
            hp.insert(lists[i]);
        }
    }

    while(hp.size() > 0){
        // get top node from heap
        let root = hp.peek();

        // attach current node to the next of resultant 'res' node
        temp.next = root;
        temp = temp.next;

        // after storing top node, remove it from heap
        hp.remove();

        // move to next node
        let nextNode = root.next
        
        // break the connection
        root.next = null;

        // insert next node into heap
        if(nextNode !== null) hp.insert(nextNode);
    }

    // at the end return resultant 'res' list
    return res.next;
};

// utility function to create linked list from array
function createLinkedList(arr){
    let temp = new ListNode(0);
    let curr = temp;
    for(let val of arr){
        curr.next = new ListNode(val);
        curr = curr.next;
    }
    return temp.next;
}

// utility function to print linked list
function printLinkedList(node){
    let arr = [];
    while(node !== null){
        arr.push(node.val);
        node = node.next;
    }
    console.log(arr.join(" -> "));
}

let lists = [
    createLinkedList([1, 4, 5]),
    createLinkedList([1, 3, 4]),
    createLinkedList([2, 6])
];

let res = mergeKLists(lists);
printLinkedList(res);