
// Problem link - https://leetcode.com/problems/design-hashmap/

let MyHashMap = function() {
    // intialize the buckets array with a fixed size
    this.size = 1000;
    this.buckets = Array.from({ length: this.size }, () => []);
};

/** 
 * utility hash function to compute the bucket index for a given key
 * @param {number} key 
 * @return {number}
 */
MyHashMap.prototype.hash = function(key) {
    return key % this.size;
}

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
MyHashMap.prototype.put = function(key, value) {
    // get index using hash function
    const index = this.hash(key);
    
    // iterate on existing key value pairs
    for(let pairs of this.buckets[index]){
        // edge case:
        if(pairs[0] === key){
            pairs[1] = value;
            return;
        }
    }
    this.buckets[index].push([key, value]);
};

/** 
 * @param {number} key
 * @return {number}
 */
MyHashMap.prototype.get = function(key) {
    // get index using hash function
    const index = this.hash(key);
    
    // iterate on existing key value pairs
    for(let pairs of this.buckets[index]){
        // edge case:
        if(pairs[0] === key){
            return pairs[1];
        }
    }
    // if key doesn't exist , then return -1
    return -1;
};

/** 
 * @param {number} key
 * @return {void}
 */
MyHashMap.prototype.remove = function(key) {
    // get index using hash function
    const index = this.hash(key);

    // remove key,value pair entry
    this.buckets[index] = this.buckets[index].filter(pair => pair[0] !== key);
};

function main(){
    console.log("Running test cases...");
    const hashMap = new MyHashMap();

    console.log("Test 1: Insert (1, 1) and (2, 2)");
    hashMap.put(1, 1); // Insert (1, 1)
    hashMap.put(2, 2); // Insert (2, 2)
    console.log(hashMap.get(1)); // Expected output: 1
    console.log(hashMap.get(2)); // Expected output: 2

    console.log("Test 2: Retrieve non-existent key (3)");
    console.log(hashMap.get(3)); // Expected output: -1 (not found)

    console.log("Test 3: Update value for existing key (2, 3)");
    hashMap.put(2, 3); // Update the value for key 2
    console.log(hashMap.get(2)); // Expected output: 3

    console.log("Test 4: Remove key (2)");
    hashMap.remove(2); // Remove key 2
    console.log(hashMap.get(2)); // Expected output: -1 (not found)

    console.log("Test 5: Collision handling");
    hashMap.put(1001, 10); // Collision with key 1 (same bucket)
    hashMap.put(2001, 20); // Collision with key 1 (same bucket)
    console.log(hashMap.get(1001)); // Expected output: 10
    console.log(hashMap.get(2001)); // Expected output: 20

    console.log("All tests completed.");
}

main();
