
// Problem link : https://leetcode.com/problems/unique-number-of-occurrences/description/?envType=problem-list-v2&envId=hash-table

let uniqueOccurrences = function(arr) {
    // step 1: create a map to count the occurrences of each element
    let map = new Map();;

    for(let num of arr){
        // increment the count for each number in the array
        map.set(num, map.get(num) + 1 || 1);
    }

    // step 2 - create a Set to store the unique frequencies
    const frqSet = new Set(map.values());

    // step 3: compare the size of the Set with the size of the Map
    // if the sizes match, it means all frequencies are unique
    return frqSet.size === map.size;
};

const arr = [1,2,2,1,1,3];

// const arr = [-3,0,1,-3,1,1,1,-3,10,0];

// const arr = [1, 2];
console.log(uniqueOccurrences(arr));
