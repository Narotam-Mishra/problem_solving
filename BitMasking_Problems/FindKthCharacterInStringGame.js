
// Problem link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=problem-list-v2&envId=bit-manipulation

function countSetBits(num){
    let setBits = 0;
    while(num > 0){
        setBits += num & 1;
        num = num >> 1;
    }
    return setBits;
}

let kthCharacter = function(k) {
    // get number of set bits in the binary representation of (k - 1)
    let flips = countSetBits(k-1);
    
    // final character is determined by how many flips (bit counts) have occurred
    // we start with 'a' and move ahead in the alphabet by the number of flips
    return String.fromCharCode('a'.charCodeAt(0) + flips);
};

let kthCharacter1 = function(k) {
    let str = "a";
    let res = "";

    res = str;
    // form string as per given condition by using infinite looping
    while(true){
        // iterate over the current string
        for(let i=0; i<str.length; i++){
            // increment character by 1 and append to res
            res += String.fromCharCode(str.charCodeAt(i) + 1)
        }

        // store transformed string to original string
        str = res;

        if(str.length >= k){
            // stop when length of the string exceeds or equals k
            break;
        }
    }
    // return kth character
    return res.charAt(k-1);
};

// let k = 5;

// let k = 10;

// let k = 100;

let k = 500;
console.log(kthCharacter(k));