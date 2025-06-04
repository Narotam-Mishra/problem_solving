
// Problem link - https://leetcode.com/problems/make-the-string-great/description/?envType=problem-list-v2&envId=string

// utility function to check for bad pairs
function makeBadPair(ch1, ch2){
    // check if they are the same letter (case-insensitive)
    const sameLetterDifferentCase = ch1.toLowerCase() === ch2.toLowerCase();
     // Check if they have different cases (original characters are different)
    const differentCase = ch1 !== ch2;
    
    // above both conditions must be true for a bad pair
    return sameLetterDifferentCase && differentCase;
}

let makeGood = function(s) {
    // step 1 - use stack to perfrom given operation
    let stack = [];

    // step 2 - iterate on each character of the input string `s`
    for(let i=0; i<s.length; i++){
        // get current character
        const currChar = s[i];

        // step 3 - if stack is empty add current character
        if(stack.length === 0){
            stack.push(currChar);
            continue;
        }

        // get last character from stack top
        const lastChar = stack[stack.length - 1];

        // step 4 - check if current char and last char form bad pair 
        if(makeBadPair(currChar, lastChar)){
            // remove bad pair by popping from stack
            stack.pop();
        }else{
            // otherwise push into stack
            stack.push(currChar);
        }
    }

    // step 5 - convert stack to string and return it
    return stack.join('');
};

// const s = "leEeetcode";

// const s = "abBAcC";

const s = "s";
console.log(makeGood(s));
