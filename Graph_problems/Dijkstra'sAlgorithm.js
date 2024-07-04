
// Implement Shortest Path Dijkstra's Algorithm

// using custom min-Heap (priority queue)
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

// Dijkstra algorithm

function findShortestPathUsingDijkstra(n, graph, src) {
  // using min-priority queue
  let pq = new CustomGenericHeap((a, b) => {
    // [node, distance] pair will be inseted into min-priority queue
    return a[1] > b[1];
  });

  // to track already visited nodes, we will use visited set
  let visited = new Set();

  //   to track via path mapping we will use via map
  let via = {};

  //   to track distance (weight cost) for each node/vertex
  let distances = {};

  // iterating on graph
  for (let i = 0; i < n; i++) {
    // initially via path is undefined
    via[i] = undefined;
    // and distance is infinity
    distances[i] = Infinity;
  }

  // initially via path for src node is -1 and distance (weight cost) is 0
  via[src] = -1;
  distances[src] = 0;

  // we will insert pair of node and distance inside the min-priority queue
  pq.insert([src, 0]);

  // traverse priority queue
  while (pq.size() > 0) {
    // get the root node
    let topmost = pq.peek();

    // then we remove the root node
    pq.remove();

    //destructure node and distance (distance from source to current node)
    const [node, distance] = topmost;

    // if we have already visited this node then ignore it because it is stale entry
    if (visited.has(node)) continue;

    // mark the node as visited
    visited.add(node);

    // traverse all the neighbors of current node
    for (const neighbour of graph[node]) {
      // destructure neighbour's node and distance
      const [neighbourNode, neighbourDistance] = neighbour;

      // if neighbour node is already visited then we skip it
      if (visited.has(neighbourNode)) continue;

      if (
        via[neighbourNode] === undefined ||
        distances[neighbourNode] > distance + neighbourDistance
      ) {
        // previous found distance was greater than the current distance

        // update the via mapping
        via[neighbourNode] = node;

        // update distance
        distances[neighbourNode] = distance + neighbourDistance;

        // insert updated distance and neighbour node
        pq.insert([neighbourNode, distance + neighbourDistance]);
      }
    }
  }

  // return distances and via map
  return [distances, via];
}


// create graph and check above algorithm on it
let n = 5;

let graph = [
    [[1, 4], [2, 8]],
    [[0, 4], [2, 2], [3, 5]],
    [[0, 8], [1, 2], [3, 5]],
    [[1, 5], [2, 5], [4, 6]],
    [[3, 6]]
];

const res = findShortestPathUsingDijkstra(n, graph, 0);
console.log("Distances are: ", res[0]);
console.log("Via array is: ", res[1]);