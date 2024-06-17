
// Implement your own Priority Queue

class PriorityQueue {
    constructor(){
        this.heap = [];
    }

    // helper methods to get parent and children indices
    getParentIndex(idx){
        return Math.floor((idx - 1) / 2);
    }

    getLeftChildIndex(idx){
        return 2*idx + 1;
    }

    getRightChildIndex(idx){
        return 2*idx + 2;
    }

    // utility bubbleUp() method to maintain priority queue property
    bubbleUp(){
        let index = this.heap.length - 1;
        while(index > 0){
            let parentIdx = this.getParentIndex(index);
            if(this.heap[index].priority >= this.heap[parentIdx].priority){
                break;
            }
            // swapping
            [this.heap[index], this.heap[parentIdx]] = [this.heap[parentIdx], this.heap[index]];
            index = parentIdx;
        }
    }

    // utility bubbleDown() method to maintain priority queue property
    bubbleDown(){
        let index = 0;
        while(true){
            let lcIdx = this.getLeftChildIndex(index);
            let rcIdx = this.getRightChildIndex(index);
            let smallestIdx = index;

            if(lcIdx < this.heap.length && this.heap[lcIdx].priority < this.heap[smallestIdx].priority){
                smallestIdx = lcIdx;
            }

            if(rcIdx < this.heap.length && this.heap[rcIdx].priority < this.heap[smallestIdx].priority){
                smallestIdx = rcIdx;
            }

            if(smallestIdx === index){
                break;
            }

            // swapping
            [this.heap[index], this.heap[smallestIdx]] = [this.heap[smallestIdx], this.heap[index]];
            index = smallestIdx;
        }
    }

    // utility method to insert into priority queue
    enqueue(value, priority){
        this.heap.push({ value, priority });
        this.bubbleUp();
    }

    // utility method to remove element from priority queue
    dequeue(){
        // corner case:
        if(this.heap.length === 0) return null;

        const root = this.heap[0];
        const lastElement = this.heap.pop();
        if(this.heap.length > 0){
            this.heap[0] = lastElement;
            this.bubbleDown();
        }
        return root.value;
    }

    //utility method check if the priority queue is empty
    isEmpty(){
        return this.heap.length === 0;
    }

    //utility method to get peek at the element with the highest priority without removing it
    peek(){
        return this.heap.length === 0 ? null : this.heap[0].value;
    }
}

// using class
const pq = new PriorityQueue();

// lower number with highest priority 
// higher number with lowest priority
pq.enqueue("task1", 1);
pq.enqueue("task5", 3);
pq.enqueue("task2", 2);
pq.enqueue("task3", 0);
pq.enqueue("task4", 4);

console.log(pq.dequeue()); // task3
console.log(pq.dequeue()); // task1
console.log(pq.dequeue()); // task2
console.log(pq.dequeue()); // task5