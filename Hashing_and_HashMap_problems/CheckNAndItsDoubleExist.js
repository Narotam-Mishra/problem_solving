
// Problem link : https://leetcode.com/problems/check-if-n-and-its-double-exist/description/?envType=problem-list-v2&envId=hash-table

let checkIfExist1 = function(arr) {
    // step 1 - iterate through input array
    for(let i = 0; i < arr.length; i++) {
        // step 2 - check if double of current element exists in array
        if(arr.indexOf(arr[i] * 2) !== -1 && arr.indexOf(arr[i] * 2) !== i) {
            return true;
        }
    }
    // step 3 - otherwise return false
    return false;
};

let checkIfExist = function(arr) {
    // step 1 - initialize a Set to store elements we have seen so far
    const seen = new Set();

    // step 2 - iterate through the array
    for(const num of arr){
        // step 2.1 - check if num / 2 exists in the set (for arr[i] = 2 * arr[j])
        if(seen.has(num/2)){
            return true;
        }

        // step 2.2 - check if 2 * num exists in the set (for arr[j] = num / 2)
        if(seen.has(num * 2)){
            return true;
        }

        // step 3 - add the current number to the set
        seen.add(num);
    }

    // step 4 - if no such pair is found, return false
    return false;
};

const arr = [10,2,5,3];

// const arr = [3,1,7,11];
console.log(checkIfExist(arr));
