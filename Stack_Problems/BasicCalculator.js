
// Problem link - https://leetcode.com/problems/basic-calculator/description/?envType=problem-list-v2&envId=string

let calculate = function(s) {
    // step 1 - use stack to evalute the expression
    let stack = [];

    // step 2 - intialize all necessary variables
    let num = 0;
    let res = 0;
    let sign = 1;

    // step 3 - iterate on each character of input string `s` and evalute expression
    for(let ch of s){
        // if current character is number then format it
        if(ch >= '0' && ch <= '9'){
            num = (num * 10) + parseInt(ch);
        }else if(ch === '+'){
            // evalutate the expression from left for '+'
            res += sign * num;

            // save recent sign
            sign = 1;
            
            // reset the number `num`
            num = 0;
        }else if(ch === '-'){
            // evalutate the expression from left for '+'
            res += sign * num;

            // save recent sign
            sign = -1;

            // reset the number `num`
            num = 0;
        }else if(ch === '('){
            // push result `res` and `sign` onto stack for `(`
            stack.push(res);
            stack.push(sign);

            // reset sign and result `res` for new expression
            res = 0;
            sign = 1;
        }else if(ch === ')'){
            // evaluate current expression
            res += sign * num

            // `)` marks end of expression so pop from stack for sign of expression
            res *= stack.pop();

            // add result for expression
            res += stack.pop();

            // reset number `num`
            num = 0;
        }
    }

    // step 4 - add and return last number to result `res`
    return res + (sign * num);
};

const s = "1 + 1";

// const s = "2-1 + 2 ";

// const s = "(1+(4+5+2)-3)+(6+8)";
console.log(calculate(s));
