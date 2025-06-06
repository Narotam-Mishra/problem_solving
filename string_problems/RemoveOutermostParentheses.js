
// Problem link - https://leetcode.com/problems/remove-outermost-parentheses/description/?envType=problem-list-v2&envId=string

let removeOuterParentheses = function(s) {
    // step 1 - store resultant string in `res`
    let res = '';

    // track balance of parentheses using `balance`
    let balance = 0;

    // step 2 - iterate on each parentheses
    for(let ch of s){
        // step 3 - increment balance for opening part
        if(ch === '('){
            balance++;

            // only add '(' if it's NOT the outermost opening parenthesis
            // the outermost '(' is when balance was 0 and becomes 1
            if(balance > 1){
                res += ch;
            }
        }else{
            // step 4 - decrement balance for closing part
            balance--;

            // only add ')' if it's NOT the outermost closing parenthesis
            // the outermost ')' is when balance becomes 0
            if(balance > 0){
                res += ch;
            }
        }
    }

    // step 5 - return the result `res`
    return res;
};

// const s = "(()())(())";

// const s = "(()())(())(()(()))";

const s = "()()";
console.log(removeOuterParentheses(s));
