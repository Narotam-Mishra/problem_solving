
// Disjoint Set Union (DSU) implementation

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

function Find(x, parent){
    if(parent[x] !== x){
        // if x is not parent of itself

        // then find the parent of x and attach it to parent
        parent[x] = Find(parent[x], parent);  // path compression
    }
    return parent[x];
}


// test code
let parent = [0, 1, 2, 3, 4, 5];
let size = [1, 1, 1, 1, 1, 1]

Union(0, 1, parent, size);
Union(2, 3, parent, size);
Union(4, 5, parent, size);

console.log(parent);
console.log(size);