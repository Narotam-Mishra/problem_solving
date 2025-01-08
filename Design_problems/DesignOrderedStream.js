
// Problem link : https://leetcode.com/problems/design-an-ordered-stream/description/?envType=problem-list-v2&envId=design

/**
 * @param {number} n
 */
let OrderedStream = function(n) {
    // array to store values, indexed by idKey - 1
    this.stream = new Array(n).fill(null);

    // pointer to track the smallest unprocessed ID
    this.ptr = 0;
};

/** 
 * @param {number} idKey 
 * @param {string} value
 * @return {string[]}
 */
OrderedStream.prototype.insert = function(idKey, value) {
    // convert idKey to zero-based index
    const index = idKey - 1;
    
    // store the value at the correct position
    this.stream[index] = value;

    // store result in `result` array
    const result = [];

    // collect contiguous values starting from `ptr`
    while(this.ptr < this.stream.length && this.stream[this.ptr] !== null){
        // add the value to the result
        result.push(this.stream[this.ptr]);

        // move the pointer to the next unprocessed ID
        this.ptr++;
    }

    // return the collected chunk
    return result;
};

const os = new OrderedStream(5);
console.log(os.insert(3, "cc")); // []
console.log(os.insert(1, "aa")); // ["aa"]
console.log(os.insert(2, "bb")); // ["bb", "cc"]
console.log(os.insert(5, "ee")); // []
console.log(os.insert(4, "dd")); // ["dd", "ee"]