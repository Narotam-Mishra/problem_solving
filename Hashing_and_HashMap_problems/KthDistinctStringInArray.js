
// Problem link : https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=problem-list-v2&envId=hash-table

let kthDistinct1 = function(arr, k) {
    // step 1 - count the frequency of each string using a object (map)
    const freqMap = {};
    for(let str of arr){
        freqMap[str] = (freqMap[str] || 0) + 1;
    }

    // step 2 - collect distinct strings in the order they appear
    const distinctStrs = Object.keys(freqMap).filter(str => freqMap[str] === 1);

    // step 3 - return the kth distinct string (1-based index)
    return distinctStrs.length >= k ? distinctStrs[k-1] : ""; 
};

let kthDistinct = function(arr, k) {
    // step 1 - count the frequency of each string using a object (map)
    const freqMap = {};
    for(let str of arr){
        freqMap[str] = (freqMap[str] || 0) + 1;
    }

    // step 3 - return the kth distinct string (1-based index)
    for(let str of arr){
        if(freqMap[str] === 1){
            k--;
        }
        if(k == 0){
            return str;
        }
    }
    return "";
};

// const arr = ["d","b","c","b","c","a"], k = 2;

// const arr = ["aaa","aa","a"], k = 1;

const arr = ["a","b","a"], k = 3;
console.log(kthDistinct(arr, k)); 
