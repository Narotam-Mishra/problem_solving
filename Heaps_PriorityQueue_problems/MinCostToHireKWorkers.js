
// Problem link - https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

class MaxHeap {
    constructor() {
        this.heap = [];
    }

    push(val) {
        this.heap.push(val);
        this._heapifyUp();
    }

    pop() {
        const top = this.heap[0];
        const bottom = this.heap.pop();
        if (this.heap.length > 0) {
            this.heap[0] = bottom;
            this._heapifyDown();
        }
        return top;
    }

    size() {
        return this.heap.length;
    }

    _heapifyUp() {
        let index = this.heap.length - 1;
        const element = this.heap[index];
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            const parent = this.heap[parentIndex];
            if (element <= parent) break;
            this.heap[index] = parent;
            index = parentIndex;
        }
        this.heap[index] = element;
    }

    _heapifyDown() {
        let index = 0;
        const length = this.heap.length;
        const element = this.heap[index];
        while (true) {
            let leftChildIndex = 2 * index + 1;
            let rightChildIndex = 2 * index + 2;
            let leftChild, rightChild;
            let swap = null;
            if (leftChildIndex < length) {
                leftChild = this.heap[leftChildIndex];
                if (leftChild > element) swap = leftChildIndex;
            }
            if (rightChildIndex < length) {
                rightChild = this.heap[rightChildIndex];
                if ((swap === null && rightChild > element) || (swap !== null && rightChild > leftChild)) {
                    swap = rightChildIndex;
                }
            }
            if (swap === null) break;
            this.heap[index] = this.heap[swap];
            index = swap;
        }
        this.heap[index] = element;
    }
}

// better approach
let mincostToHireWorkers = function(quality, wage, k) {
    
};

// Better approach 
let mincostToHireWorkers2 = function(quality, minWage, k) {
    const n = quality.length;
    let minCost = Number.MAX_VALUE;

    const workerRatio = new Array(n);

    // create an array of pairs (ratio, quality)
    for(let worker = 0; worker < n; worker++){
        workerRatio[worker] = [minWage[worker] / quality[worker], quality[worker]];
    }

    // sort the workers by their wage-to-quality ratio
    workerRatio.sort((a, b) => a[0] - b[0]);

    // iterate through each worker considering them as the manager
    for(let manager = k-1; manager < n; manager++){
        const managerRatio = workerRatio[manager][0];

        // store worker wage
        const group = [];
        // collect all workers up to the current manager
        for(let worker = 0; worker<=manager; worker++){
            const workerWage = managerRatio * workerRatio[worker][1];
            group.push(workerWage);
        }

        // using a max-heap to get the sum of the smallest k wages
        const pq = new MaxHeap();
        let sumWage = 0;

        for(const wage of group){
            sumWage += wage;
            pq.push(wage);

            if(pq.size() > k){
                sumWage -= pq.pop();
            }
        }

        minCost = Math.min(minCost, sumWage);
    }

    // return the minimum wage cost
    return minCost;
};

// BruteForce Approach
let mincostToHireWorkers1 = function(quality, minWage, k) {
    const n = quality.length;
    let minCost = Number.MAX_VALUE;

    // iterate over each worker to consider them as the manager
    for(let manager = 0; manager < n; manager++){
        // calculate the ratio of minWage to quality for the manager
        const managerRatio = minWage[manager] / quality[manager];
        
        // array to store actual (valid) wages for each worker
        const validWages = [];

        // check each worker's wage when hired by this manager
        for(let worker = 0; worker < n; worker++){
            const workerWage = managerRatio * quality[worker];

            if(workerWage >= minWage[worker]){
                // if the calculated worker's wage is greater than or equal to the worker's minimum wage
                // that will be only valid
                validWages.push(workerWage);
            }
        }

        if(validWages.length < k){
            // if we don't have enough valid workers, 
            // continue to the next manager
            continue;
        }

        // sort the valid wages in ascending order
        // as we need to find the least amount of wage
        validWages.sort((a,b) => a - b);
        let totalWage = 0;

        // sum the smallest k wages
        for(let i=0; i<k; i++){
            totalWage += validWages[i];
        }

        // update the minimum cost if we found a cheaper combination
        minCost = Math.min(minCost, totalWage);
    }
    return minCost;
};

// const quality = [10, 20, 5];
// const minWage = [70, 50, 30];
// const k = 2;

const quality = [3,1,10,10,1], minWage = [4,8,2,2,7], k = 3
console.log(mincostToHireWorkers(quality, minWage, k));