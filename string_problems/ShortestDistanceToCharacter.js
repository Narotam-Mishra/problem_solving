
// Problem link : https://leetcode.com/problems/shortest-distance-to-a-character/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

let shortestToChar = function(s, c) {
    let len = s.length;
    
    // initialize result array with Infinity
    let res = new Array(len).fill(Infinity);
    
    // represents the last seen position of 'c' (left to right)
    let prev = Infinity;

    // traverse from left to right
    for(let i=0; i<len; i++){
        if(s[i] === c){
            // update the position of 'c'
            prev = i;
        }
        // calculate distance from the nearest 'c' so far
        res[i] = Math.abs(i - prev);
    }

    // reset prev for the second pass
    prev = Infinity;

    // traverse from right to left
    for(let i=len-1; i>=0; i--){
        if(s[i] === c){
            prev = i;
        }
        // take smaller absolute distance
        res[i] = Math.min(res[i], Math.abs(i - prev));
    }
    // return the result array
    return res;
};

// let s = "loveleetcode", c = "e";

let s = "aaab", c = "b";
console.log(shortestToChar(s, c));
