
// Problem link - https://leetcode.com/problems/goal-parser-interpretation/description/?envType=problem-list-v2&envId=string

let interpret = function(command) {
    // step 1 - initialize an empty string `res` to store the result
    let res = '';
    let i = 0;

    // step 2 - iterate on input string `command` and scane each character
    while(i < command.length){
        // 'G' remains unchanged
        if(command[i] === 'G'){
            res += 'G';
            i++;
        }else if(command[i] === '('){
            // check if it's "()" or "(al)"
            if(command[i+1] === ')'){
                // "()" will be interprreted as 'o'
                res += 'o';
                i += 2;
            }else{
                // "(al)" is interpreted as "al"
                res += 'al';
                i += 4;
            }
        }
    }

    // step 3 - return result string `res`
    return res;
};

// const command = "G()(al)";

// const command = "G()()()()(al)";

const command = "(al)G(al)()()G";
console.log(interpret(command));
