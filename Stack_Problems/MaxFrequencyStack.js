
// Problem link - https://leetcode.com/problems/maximum-frequency-stack/description/

/*

# push() steps :-
1). Increment frequency
2). Update frequency map
3). Update maxFreq if needed
4). Initialize stack for this frequency if not exists
5). Push the element to the stack for this frequency

# pop() steps :-
1). Get the stack with maximum frequency
2). Pop the top element from the stack
3). Decrease maxFreq if the stack becomes empty
4). Update frequency map
5). Return popped element

*/

// Approach - 1 (using two maps)
let FreqStack1 = function() {
    // frequency map to maintain frequency of each elements
    this.freqMap = new Map();
    // elementMap to store stack of elements for each frequency
    this.elementMap = new Map();
    // to track max frequency
    this.maxFreq = 0;
};

/** 
 * @param {number} val
 * @return {void}
 */
FreqStack1.prototype.push = function(val) {
    // increment frequency
    let freq = (this.freqMap.get(val) || 0) + 1;
    // update frequency
    this.freqMap.set(val, freq);

    // update maximum frequency in maxFreq
    if(freq > this.maxFreq) this.maxFreq = freq;

    // Initialize elementMap for this frequency if not exists
    if(!this.elementMap.has(freq)){
        this.elementMap.set(freq, []);
    }

    //push the element to the elementMap for this frequency
    this.elementMap.get(freq).push(val);
};

/**
 * @return {number}
 */
FreqStack1.prototype.pop = function() {
    // get the stack (from elementMap) with maximum frequency
    let maxFrqStack = this.elementMap.get(this.maxFreq);

    // pop the top element from the stack
    let poppedElement = maxFrqStack.pop();

    // decrease maxFreq (from elementMap) if the stack becomes empty
    if(maxFrqStack.length === 0){
        this.maxFreq--;
    }

    // Update frequency map
    this.freqMap.set(poppedElement, this.freqMap.get(poppedElement)-1);

    // Return popped element
    return poppedElement;
};

// Approach - 2 (using object as map)

let FreqStack = function() {
    // frequency map to maintain frequency of each elements
    this.freqMap = {};
    // to track max frequency
    this.maxFreq = 0;
    // elementMap to store stack of elements for each frequency
    this.elementMap = {};
};

/** 
 * @param {number} val
 * @return {void}
 */
FreqStack.prototype.push = function(val) {
    // if val doesn't exist in freqMap then 
    if(!this.freqMap[val]){
        // create entry in freqMap
        this.freqMap[val] = 1;
    }else{
        // val already exist in freqMap , update its frequency
        this.freqMap[val] += 1;
    }

    // update maximum frequency
    this.maxFreq = Math.max(this.maxFreq, this.freqMap[val]);

    // get current frequency
    let curFrq = this.freqMap[val];

    // add current frequency entry in the elementMap if it doesn't exist
    if(!this.elementMap[curFrq]){
        this.elementMap[curFrq] = [val];
    }else{
        // otherwise add current frequency in stack
        this.elementMap[curFrq].push(val); 
    }
};

/**
 * @return {number}
 */
FreqStack.prototype.pop = function() {
    // 1). Get the stack from element map with maximum frequency
    let maxFrqStack = this.elementMap[this.maxFreq];

    // 2). Pop the top element from the stack
    let poppedElement = maxFrqStack.pop();

    //3). decrease maxFreq if the stack becomes empty
    if(maxFrqStack.length === 0){
        delete this.elementMap[this.maxFreq];
        this.maxFreq--;
    }

    //4). Update frequency map
    this.freqMap[poppedElement]--;

    //5). return popped element
    return poppedElement;
};

const freqStack = new FreqStack();
freqStack.push(5);
freqStack.push(7);
freqStack.push(5);
freqStack.push(7);
freqStack.push(4);
freqStack.push(5);
console.log(freqStack.pop()); // Output: 5
console.log(freqStack.pop()); // Output: 7
console.log(freqStack.pop()); // Output: 5
console.log(freqStack.pop()); // Output: 4