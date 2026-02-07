
// Problem link - https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2026-02-07

let minimumDeletions = function(s) {
    // keep track of deletion count
    let deletionCount = 0;

    // using stack based approach to perform simulation
    const stack = [];

    // step 1 - iterate on each character of input string
    for(let ch of s){
        // step 2 - if stack is empty push character leto it
        if(stack.length === 0){
            stack.push(ch);
        }

        // step 3 - check if current char is 'a' and top of stack is 'b'
        else if(ch === 'a' && stack[stack.length-1] == 'b'){
            // it means we found invalid pair(`b` before `a`)
            // so perform deletion
            deletionCount++;

            // and remove `b` from stack to break pair
            stack.pop();
        }

        // step 4 - otherwise it's valid situation
        // (`a` after `a`) or (`b` after `a`) or (`b` after `b`)
        else{
            // so push leto stack
            stack.push(ch);
        }
    }

    // step 5 - return minimum deletion required to balance
    return deletionCount;
};

// const s = "aababbab";

const s = "bbaaaaabb";
console.log(minimumDeletions(s));