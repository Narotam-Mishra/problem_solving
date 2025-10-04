
// Problem link - https://leetcode.com/problems/trapping-rain-water-ii/description/?envType=daily-question&envId=2025-10-03

/**
 * Min-Priority Queue implementation using binary heap
 */
class MinPriorityQueue {
    constructor() {
        this.heap = [];
    }
    
    enqueue(element) {
        this.heap.push(element);
        this.bubbleUp(this.heap.length - 1);
    }
    
    dequeue() {
        if (this.heap.length === 1) return this.heap.pop();
        
        const min = this.heap[0];
        this.heap[0] = this.heap.pop();
        this.bubbleDown(0);
        return min;
    }
    
    bubbleUp(index) {
        while (index > 0) {
            const parentIndex = Math.floor((index - 1) / 2);
            
            // Compare by height (first element of array)
            if (this.heap[index][0] >= this.heap[parentIndex][0]) break;
            
            [this.heap[index], this.heap[parentIndex]] = 
                [this.heap[parentIndex], this.heap[index]];
            index = parentIndex;
        }
    }
    
    bubbleDown(index) {
        while (true) {
            let smallest = index;
            const leftChild = 2 * index + 1;
            const rightChild = 2 * index + 2;
            
            if (leftChild < this.heap.length && 
                this.heap[leftChild][0] < this.heap[smallest][0]) {
                smallest = leftChild;
            }
            
            if (rightChild < this.heap.length && 
                this.heap[rightChild][0] < this.heap[smallest][0]) {
                smallest = rightChild;
            }
            
            if (smallest === index) break;
            
            [this.heap[index], this.heap[smallest]] = 
                [this.heap[smallest], this.heap[index]];
            index = smallest;
        }
    }
    
    isEmpty() {
        return this.heap.length === 0;
    }
}

let trapRainWater = function(heightMap) {
    // edge cases: empty map or too small to trap water
    if (!heightMap || heightMap.length < 3 || heightMap[0].length < 3) {
        return 0;
    }

    // find row and column size of heightMap
    const m = heightMap.length;
    const n = heightMap[0].length;
    
    // min-heap to process cells by height (smallest first)
    // each element: [height, row, col]
    const minHeap = new MinPriorityQueue();
    
    // track visited cells to avoid reprocessing
    const visited = Array.from({ length: m }, () => Array(n).fill(false));

    // directions for exploring neighbors: up, down, left, right
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    // step 1: Add all boundary cells to the heap
    // these are our initial "walls" that contain water
    
    // top and bottom rows
    for (let col = 0; col < n; col++) {
        minHeap.enqueue([heightMap[0][col], 0, col]);
        minHeap.enqueue([heightMap[m - 1][col], m - 1, col]);
        visited[0][col] = true;
        visited[m - 1][col] = true;
    }
    
    // left and right columns (excluding corners already added)
    for (let row = 1; row < m - 1; row++) {
        minHeap.enqueue([heightMap[row][0], row, 0]);
        minHeap.enqueue([heightMap[row][n - 1], row, n - 1]);
        visited[row][0] = true;
        visited[row][n - 1] = true;
    }

    // current water level (highest boundary seen so far)
    let maxHeight = 0; 
    
    // step 2: process cells from lowest to highest height
    let waterVolume = 0;
    while (!minHeap.isEmpty()) {
        // get the cell with minimum height from boundary
        const [height, row, col] = minHeap.dequeue();
        
        // update the water level - it can only increase or stay same
        // this represents the minimum barrier height to reach the boundary
        maxHeight = Math.max(maxHeight, height);
        
        // step 3: explore all 4 neighbors
        for (const [dr, dc] of directions) {
            const newRow = row + dr;
            const newCol = col + dc;
            
            // check if neighbor is within bounds and not visited
            if (newRow >= 0 && newRow < m && 
                newCol >= 0 && newCol < n && 
                !visited[newRow][newCol]) {
                
                visited[newRow][newCol] = true;
                
                const neighborHeight = heightMap[newRow][newCol];
                
                // step 4: calculate trapped water
                // if neighbor is lower than current water level, it traps water
                if (neighborHeight < maxHeight) {
                    waterVolume += maxHeight - neighborHeight;
                }
                
                // add neighbor to heap for future processing
                // we add the actual height (not water level) because
                // this cell becomes a new boundary for its unvisited neighbors
                minHeap.enqueue([neighborHeight, newRow, newCol]);
            }
        }
    }
    
    // step 5 - return the volume of water it can trap after raining
    return waterVolume;
};

// const heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]];

const heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]];
console.log(trapRainWater(heightMap));