
// Problem link - https://leetcode.com/problems/add-digits/description/?envType=problem-list-v2&envId=number-theory

function findSum(n){
    let s = 0;
    while(n > 0){
        s += n % 10;
        n = Math.floor(n/10);
    }
    return s;
}

let addDigits = function(num) {
    while(num >= 10){
        num = findSum(num);
    }
    return num;
};

// let num = 199

let num = 38
console.log(addDigits(num));
