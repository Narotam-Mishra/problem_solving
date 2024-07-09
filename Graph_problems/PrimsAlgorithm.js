
// Implement Prim's algorithm to find MST

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
  insert(key, value) {
    //step1 - insert data into array(heap)
    this.arr.push({key, value});

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

class Graph {
    constructor(numOfVetices){
        this.V = numOfVetices;
        this.adjList = new Map();
    }

    // utility method to add edges between nodes 
    addEdges(u, v, weight){
        // if edge is not already exist then intialize it with empty array
        if(!this.adjList.has(u)) this.adjList.set(u, []);
        if(!this.adjList.has(v)) this.adjList.set(v, []);

        // add edges between u to v with weight 
        this.adjList.get(u).push({ node: v, weight: weight});
        this.adjList.get(v).push({ node: u, weight: weight});
    }

    // utility method to implement prim's algorithm
    findMSTUsingPrimAlgo(){
        // mst array to keep track to nodes/vertices
        let mst = [];

        // visited array to keep track to already visited node/vertices
        let visited = new Array(this.numOfVetices).fill(false);
        
        // using min-heap (min priority queue) to keep track of minimum weight
        let minHeap = new CustomGenericHeap((a, b) => {
            return a.key > b.key;
        });

        // assume start node as 0
        let startNode = 0;

        // start with the first node, pushing all its edges into the heap
        // also mark true it in visited array
        visited[startNode] = true;

        // keep track of MST cost
        let mstCost = 0;

        // start with the first node, pushing all its edges into the heap
        this.adjList.get(startNode).forEach(edge => {
            // add weight, nodes 'u' and 'v' into min-heap
            minHeap.insert(edge.weight, { u: startNode, v:edge.node});
        })

        // traverse min-heap to calculate minimum cost of MST
        while(minHeap.size() > 0){
            let minEdge = minHeap.peek();
            minHeap.remove();

            let u = minEdge.value.u;
            let v = minEdge.value.v;

            // check if the destination node is already visited, skip
            if(visited[v]) continue;

            // mark the destination node as visited and add the edge to the MST
            visited[v] = true;
            mst.push({ u, v, weight: minEdge.key});
            mstCost += minEdge.key;

            // push all edges from the newly visited node to the heap
            this.adjList.get(v).forEach(edge => {
                if(!visited[edge.node]){
                    minHeap.insert(edge.weight, { u: v, v: edge.node });
                }
            })
        }

        // return minimum cost to traverse spanning tree
        console.log("Total cost of MST: " + mstCost);
        return mst;
    }
}

// test code
let g = new Graph(5);
g.addEdges(0, 1, 2);
g.addEdges(0, 3, 6);
g.addEdges(1, 2, 3);
g.addEdges(1, 3, 8);
g.addEdges(1, 4, 5);
g.addEdges(2, 4, 7);
g.addEdges(3, 4, 9);

let mst = g.findMSTUsingPrimAlgo();
console.log("Edges in the MST:");
mst.forEach(edge => {
    console.log(`${edge.u} - ${edge.v}: ${edge.weight}`);
});