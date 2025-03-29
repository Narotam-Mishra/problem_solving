
// Problem link - https://leetcode.com/problems/generate-a-string-with-characters-that-have-odd-counts/description/?envType=problem-list-v2&envId=string

let generateTheString = function(n) {
    // step 1 - if `n` is odd then generate `n` characters 
    if(n % 2 === 1){
        return 'a'.repeat(n)
    }else{
        // step 2 - if `n` is even then generate `n-1` characters first and one different character
        return 'a'.repeat(n-1) + 'b';
    }
};

// const n = 4;

// const n = 2;

const n = 7;
console.log(generateTheString(n));
