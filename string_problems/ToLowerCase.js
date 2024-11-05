
// Problem link : https://leetcode.com/problems/to-lower-case/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let toLowerCase1 = function(s) {
    return s.toLowerCase();  
};

let toLowerCase = function(s) {
    let res = '';
    
    for(let char of s){
        // check if character is uppercase using charCode
        // ASCII values for uppercase letters: A-Z (65-90)
        if(char.charCodeAt(0) >= 65 && char.charCodeAt(0) <= 90){
            // convert to lowercase by adding 32
            res += String.fromCharCode(char.charCodeAt(0) + 32);
        }else{
            res += char;
        }
    }
    return res;
};

let str = "Hello World";

// let str = "here";

// let str = "LOVELY";
console.log(toLowerCase(str));
