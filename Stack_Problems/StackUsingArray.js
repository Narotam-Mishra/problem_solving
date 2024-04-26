
// Design your own stack using Array

class Stack {
    // private properties
    #arr;

    constructor() {
        this.#arr = [];
    }

    push(element){
        this.#arr.push(element);
    }

    pop(){
        this.#arr.pop();
    }

    top(){
        return this.#arr[this.#arr.length - 1];
    }

    isEmpty(){
        return this.#arr.length === 0;
    }

}

let s = new Stack();
s.push(10);
s.push(20);
s.push(40);
s.push(50);
s.push(70);
console.log(s.top());
s.pop();
console.log(s.top());
console.log(s.isEmpty());
