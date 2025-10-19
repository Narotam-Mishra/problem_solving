
// Problem link - https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/?envType=daily-question&envId=2025-10-19

// helper function to rotate string to the RIGHT by b positions
function rotateString(str, b) {
    const n = str.length;
    
    // convert string to array for easier manipulation
    let chars = str.split('');
    
    // step 1: Reverse entire array
    reverse(chars, 0, n - 1);
    
    // step 2: Reverse first b characters
    reverse(chars, 0, b - 1);
    
    // step 3: Reverse remaining characters
    reverse(chars, b, n - 1);
    
    return chars.join('');
}

// helper function to reverse a portion of array
function reverse(arr, start, end) {
    while (start < end) {
        [arr[start], arr[end]] = [arr[end], arr[start]];  // ES6 destructuring swap
        start++;
        end--;
    }
}


let findLexSmallestString = function(s, a, b) {
    // initialize result with the original string
    let res = s;
    
    // BFS to explore all possible states
    const queue = [];
    const visited = new Set();
    
    // step 1 - start BFS from the original string
    queue.push(s);
    visited.add(s);
    
    while (queue.length > 0) {
        // step 2 - get current string state from queue
        const currStr = queue.shift();
        
        // step 3 - update result if current string is lexicographically smaller
        if (currStr < res) {
            res = currStr;
        }
        
        // OPERATION 1: Add 'a' to all odd indices (1, 3, 5, ...)
        let temp = currStr.split('');
        for (let i = 1; i < temp.length; i += 2) {
            // add 'a' to digit at odd index and cycle back using modulo 10
            const digit = parseInt(temp[i]);
            temp[i] = String((digit + a) % 10);
        }
        const addResult = temp.join('');
        
        // step 4 - if this state hasn't been visited, add to queue for exploration
        if (!visited.has(addResult)) {
            visited.add(addResult);
            queue.push(addResult);
        }
        
        // OPERATION 2: Rotate string to the RIGHT by 'b' positions
        const rotateResult = rotateString(currStr, b);
        
        // step 5 - if this state hasn't been visited, add to queue for exploration
        if (!visited.has(rotateResult)) {
            visited.add(rotateResult);
            queue.push(rotateResult);
        }
    }
    
    // step 6 - return the lexicographically smallest string found
    return res;
};

// const s = "5525", a = 9, b = 2;

// const s = "74", a = 5, b = 1;

const s = "0011", a = 4, b = 2;
console.log(findLexSmallestString(s, a, b));