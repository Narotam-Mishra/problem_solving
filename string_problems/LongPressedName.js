
// Problem link : https://leetcode.com/problems/long-pressed-name/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let isLongPressedName = function(name, typed) {
    // using two-pointers approach
    // pointer i for name, 
    let i = 0;

    // pointer j for typed
    let j = 0;

    // traverse through typed characters
    while(j < typed.length){
        // case 1 : character match case in both name and typed strings
        if(i < name.length && name[i] === typed[j]){
            i++;
            j++;
        // case 2 : long-pressed scneario
        }else if(typed[j] === typed[j-1] && j > 0){
            // current character in typed matched previous character
            j++;
        // case 3 : invalid scenario, character in typed doesn't match
        }else{
            // name's current character or isn't a long press
            return false;
        }
    }
    
    // after processing typed, ensure all characters in name matched
    return i === name.length;
};

// let name = "alex", typed = "aaleex";

let name = "saeed", typed = "ssaaedd";
console.log(isLongPressedName(name, typed));
