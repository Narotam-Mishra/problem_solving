
// Problem link - https://leetcode.com/problems/find-if-path-exists-in-graph/description/


// utility method for BFS traversal
function bfs(src, dest, g, visited){
    // base case1: if src is dest only
    if(src === dest) return true;

    // using array as queue
    const queue = [];
    queue.push(src);

    // add the source, 'src' node to visted set as we have visited it 
    // and now we will go to current node neighbour
    visited.add(src);

    // till queue is empty
    while(queue.length > 0){
        // remove from start
        const currVer = queue.shift();

        // traverse each neighbour one by one
        for(const neighbour of g[currVer]){
            // base case2: neighbor is destination 'dest'
            if(neighbour === dest) return true;
            if(!visited.has(neighbour)){
                // if we have not already visited the neighbour then go to that neighbour
                visited.add(neighbour);
                // then add the neighbour to the vsisted set
                queue.push(neighbour);
                // then add the neighbouring node into queue
            }
        }
    }
    return false;
}

// utility method for DFS traversal
function dfs(src, dest, g, visited){
    // base case: if src is dest only
    if(src === dest) return true;

    // add the source, 'src' node to visted set as we have visited it 
    // and now we will go to nearest neighbour
    visited.add(src);

    // traverse each neighbour one by one
    let ans = false;
    for(const neighbour of g[src]){
        if(!visited.has(neighbour)){
            // if we have not already visited the neighbour then go to that neighbour
            ans = ans || dfs(neighbour, dest, g, visited);
        }
    }
    return ans;
}

// TC : O(V+E)
let validPath = function(n, edges, source, destination) {
    // graph creation
    const g = new Array(n);

    // convert edge list into adjacency list
    for(let i = 0; i < n; i++){
        g[i] = [];
    }

    // populate the graph's edges
    for(let i=0; i<edges.length; i++){
        let u = edges[i][0];
        let v =edges[i][1];

        //for bidirectional edges
        g[u].push(v);
        g[v].push(u)
    }

    return dfs(source, destination, g, new Set());
};

function main(){
    // const n = 6; // number of nodes
    // const edges = [[0, 1], [0, 2], [3, 5], [5, 4], [4, 3]]; // edges in the graph
    // const source = 0; // starting node
    // const destination = 5; // destination node

    const n = 3; // number of nodes
    const edges = [[0,1],[1,2],[2,0]]; // edges in the graph
    const source = 0; // starting node
    const destination = 2; // destination node

    const result = validPath(n, edges, source, destination);
    console.log(`Path from ${source} to ${destination} exists: ${result}`);
}

main();