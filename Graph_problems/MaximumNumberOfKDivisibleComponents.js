
// Problem link - https://leetcode.com/problems/maximum-number-of-k-divisible-components/description/?envType=daily-question&envId=2025-11-28

let maxKDivisibleComponents = function(n, edges, values, k) {
    // step 1 - build adjacency list to represent the tree structure
    const adj = new Map();
    for(let i = 0; i < n; i++){
        adj.set(i, []);
    }
    
    for(const [u, v] of edges){
        adj.get(u).push(v);
        adj.get(v).push(u);
    }

    // step 2 - initialize component count
    let componentCount = 0;

    // step 3 - define DFS function using arrow function
    const dfs = (currNode, parent) => {
        // start with current node's value
        let sum = values[currNode];

        // step 4 - traverse all neighbors (children in the tree)
        for(const neighbor of adj.get(currNode)){
            // skip parent to avoid infinite loop
            if(neighbor !== parent){
                // recursively get sum from child subtree
                const childSum = dfs(neighbor, currNode);
                sum += childSum;
                sum %= k; // Keep sum manageable
            }
        }

        // step 5 - take final modulo
        sum %= k;

        // step 6 - check if subtree sum is divisible by k, we found a valid component
        if(sum === 0){
            componentCount++;
        }

        return sum;
    };

    // step 7 - start DFS from node 0 with no parent (-1)
    dfs(0, -1);

    // step 8 - return total count of k-divisible components
    return componentCount;
};

// const n = 5, edges = [[0,2],[1,2],[1,3],[2,4]], values = [1,8,1,4,4], k = 6;

const n = 7, edges = [[0,1],[0,2],[1,3],[1,4],[2,5],[2,6]], values = [3,0,6,1,5,2,1], k = 3;
console.log(maxKDivisibleComponents(n, edges, values, k));