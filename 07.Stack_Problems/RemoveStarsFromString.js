
// Problem link - https://leetcode.com/problems/removing-stars-from-a-string/description/

let removeStars = function(s) {
    let stack = [];
    for(let i=0; i<s.length; i++){
        if(s[i] !== '*'){
            stack.push(s[i]);
        }else{
            stack.pop();
        }
    }
    return stack.join('');
};

let str = "leet**cod*e";
let ans = removeStars(str);
console.log(ans);