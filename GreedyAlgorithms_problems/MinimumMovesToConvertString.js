
// Problem link : https://leetcode.com/problems/minimum-moves-to-convert-string/description/

let minimumMoves = function(s) {
    // counter for the number of moves required
    let moves = 0;

    // pointer to iterate through the string
    let i = 0;

    // iterate through the string
    while(i < s.length){
        // if we find an 'X', we need to make a move
        if(s[i] === 'X'){
            // make a move, even if some of them are already 'O', it doesn't matter
            moves++;

            // skip the next two characters, as they are included in the current move
            i += 3
        }else{
            // if the character is 'O', just move to the next character
            i++;
        }
    }

    // return the total number of moves required
    return moves;
};

// let str = "XXX";

// let str = "XXOX"

let str = "OOOO"
console.log(minimumMoves(str));
