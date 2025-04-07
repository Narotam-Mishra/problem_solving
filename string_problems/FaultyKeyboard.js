
// Problem link - https://leetcode.com/problems/faulty-keyboard/description/?envType=problem-list-v2&envId=string

let finalString = function(s) {
    // step 1 - store final string to screen
    let screen = [];

    // step 2 - loop through each character typed  on character
    for(let ch of s){
        if(ch === 'i'){
            // step 3 - faulty behaviour : reverse the screen
            screen.reverse();
        }else{
            // step 4 - normal behaviour : add character to screen
            screen.push(ch);
        }
    }

    // step 5 - convert the character array to a string
    return screen.join('');
};

// const s = "string";

const s = "poiinter";
console.log(finalString(s));
