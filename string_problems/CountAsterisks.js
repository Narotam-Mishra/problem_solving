
// Problem link - https://leetcode.com/problems/count-asterisks/description/?envType=problem-list-v2&envId=string

let countAsterisks = function(s) {
    // step 1 - initialize counter to count `*`
    let count = 0;

    // step 2 - track whether we are inside `|` pair or not
    let insidePair = false;

    // step 3 - iterate on each character of input `s`
    for(let ch of s){
        if(ch === '|'){
            // step 4 - toggle the insidePair flag whenever we see `|`
            insidePair = !insidePair;
        }else if(ch === '*' && !insidePair){
            // step 5 - only count `*` if we are outside of `|` pair
            count++;
        }
    }

    // step 6 - return count 
    return count;
};

// const s = "l|*e*et|c**o|*de|";

// const s = "iamprogrammer";

const s = "yo|uar|e**|b|e***au|tifu|l";
console.log(countAsterisks(s));
