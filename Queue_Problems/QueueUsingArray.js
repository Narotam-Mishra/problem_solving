
// Design your own Queue using Array

class Queue {
    // private properties
    #queue;

    constructor(len) {
        this.size = len;
        this.#queue = new Array(this.size);
        this.front = this.back = 0;
    }

    // insert element into queue (back)
    enqueue(element){
        //before insertion, check queue is full or not
        if(this.size === this.back){
            console.log("Queue size is full!");
            return;
        }else{
            // otherwise insert eleemnt from back of queue
            this.#queue[this.back] = element;
            this.back++;
        }
    }

    // delete element from queue and return deleted element (front)
    dequeue(){
        // check queue is empty or not before deletion
        if(this.front === this.back){
            // queue is empty
            console.log("Queue size is full!");
            return;
        }else{
            let deletedElement = this.#queue[this.front];
            // shift elements towards the front of the queue
            for(let i=0; i<this.back-1; i++){
                this.#queue[i] = this.#queue[i+1];
            }
            // Store 0 at back indicating there's no element
            if(this.back < this.size){
                this.#queue[this.back] = 0;
            }
            // reset the last element and decrement back
            this.#queue[--this.back] = undefined;
            return deletedElement;
        }
        return;
    }

    getFront(){
        // check queue is empty or not before getting front element
        if(this.front === this.back){
            // queue is empty
            console.log("Queue size is full!");
            return;
        }
        return this.#queue[this.front];
    }

    getBack(){
        // check queue is empty or not before getting back element
        if(this.front === this.back){
            // queue is empty
            console.log("Queue size is full!");
            return;
        }
        return this.#queue[this.back - 1];
    }

    isEmpty(){
        return this.front === this.back;
    }

    displayData(){
        let i;
        if(this.front === this.back){
            // queue is empty
            console.log("Queue size is full!");
            return;
        }
        for(i = this.front; i<this.back; i++){
            console.log(this.#queue[i]);
        }
    }
}

let q = new Queue(9);

q.enqueue(1);
q.enqueue(2);
q.enqueue(3);
q.enqueue(4);
q.enqueue(5);
q.enqueue(6);
q.enqueue(7);
q.enqueue(8);
q.enqueue(9);

q.dequeue();
q.dequeue();
q.dequeue();


console.log("Is Queue empty:",q.isEmpty());
console.log("Front:", q.getFront()); // Output - 1
console.log("Back:", q.getBack()); //Output - 3

console.log("Queue Elements:");
q.displayData();
console.log("Is Queue empty:",q.isEmpty());