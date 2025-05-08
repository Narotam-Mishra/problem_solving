
// Problem link - https://leetcode.com/problems/increasing-decreasing-string/description/?envType=problem-list-v2&envId=string

let sortString = function(s) {
    // step 1 - use frequency array to count frquency of each character
    const freq = new Array(26).fill(0);

    // step 2 - count frequency of each character of `s`
    for(let ch of s){
        freq[ch.charCodeAt(0) - 97]++;
    }

    // step 3 - store result in `res`
    const res = [];
    const n = s.length;

    // step 4 - complete the operation as state in algorithm
    while(res.length < n){
        // follow step 1 to 3 of given algorithm
        for(let i=0; i<26; i++){
            if(freq[i] > 0){
                res.push(String.fromCharCode(i + 97));
                freq[i]--;
            }
        }

        // follow step 4 to 6 of given algorithm
        for(let i=25; i>=0; i--){
            if(freq[i] > 0){
                res.push(String.fromCharCode(i + 97));
                freq[i]--;
            }
        }
    }

    // step 5 - return result `res`
    return res.join('');
};

// const s = "aaaabbbbcccc";

const s = "rat";
console.log(sortString(s));