
// Implement Kruskal's algorithm to find MST

// DSU Implementation
// utility method for union operation
function Union(x, y, parent, size){
    let xRoot = Find(x, parent);
    let yRoot = Find(y, parent);

    if(xRoot === yRoot) return;
    // x and y are always in same set

    if(size[xRoot] < size[yRoot]){
        // x is smaller than y
        parent[xRoot] = yRoot;
        size[yRoot] += size[xRoot];
    }else{
        // y is smaller than x
        parent[yRoot] = xRoot;
        size[xRoot] += size[yRoot];
    }
}

// utility method for find operation
function Find(x, parent){
    if(parent[x] !== x){
        // if x is not parent of itself

        // then find the parent of x and attach it to parent
        parent[x] = Find(parent[x], parent);  // path compression
    }
    return parent[x];
}

// Time Complexity Kruskal's Algorithm is O(ElogE)
// utility method to implement Kruskal's Algorithm
function kruskalAlgoToFindMST(edgeList, numOfVertices){
    // sort edgeList on the basis of their edges
    edgeList.sort((e1, e2) => e1[2] - e2[2]);

    // to track minimum spanning tree sum
    let spanningTreeSum = 0;

    // to track parent element while perfroming DSU operation
    let parent = new Array(numOfVertices).fill(0);

    // intialize parent array with each vertex as its own parent
    parent = parent.map((element, index) => index);

    // intialize size array with 1 
    let sizeArr = new Array(numOfVertices).fill(1)

    // traverse each edge from edgeList
    for(let edge of edgeList){
        // destructure edges and its correponding weights
        let [u, v, weight] = edge;

        // find operation to check if both edges belong to same set or not
        if(Find(u, parent) !== Find(v, parent)){
            // if u and v are not in same set or same component
            // it means adding this edge will not form a cycle
            Union(u, v, parent, sizeArr);

            // picking the edge and add its weight to spanning tree sum
            spanningTreeSum += weight;
        }
    }
    return spanningTreeSum;
}


// test code

let edgeList = [
    [0, 1, 10],
    [0, 2, 6],
    [0, 3, 5],
    [1, 3, 15],
    [2, 3, 4],
];

let numOfVertices = 4;
console.log(kruskalAlgoToFindMST(edgeList, numOfVertices));