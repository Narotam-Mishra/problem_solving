
// Problem link : https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/?envType=problem-list-v2&envId=bit-manipulation

let kthCharacter = function(k) {
    let str = "a";
    let res = "";

    res = str;
    while(true){
        for(let i=0; i<str.length; i++){
            res += String.fromCharCode(str.charCodeAt(i) + 1)
        }
        str = res;
        if(str.length >= k){
            break;
        }
    }
    return res.charAt(k-1);
};

// let k = 5;

// let k = 10;

// let k = 100;

let k = 500;
console.log(kthCharacter(k));