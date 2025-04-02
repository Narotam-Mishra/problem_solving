
// Problem link - https://leetcode.com/problems/snake-in-matrix/description/?envType=problem-list-v2&envId=string

let finalPositionOfSnake = function(n, commands) {
    // step 1 - initial position at top left corner (0, 0)
    let row = 0;
    let col = 0;

    // step 2 - iterate through each comamnd
    for(let command of commands){
        // move one row up 
        if(command === "UP") row--;

        // move one row down
        else if(command === "DOWN") row++;

        // move one column left
        else if(command === "LEFT") col--;

        // move one column right
        else col++;
    }

    // step 3 - return final grid position 
    return (row * n) + col;
};

// const n = 2, commands = ["RIGHT","DOWN"];

const n = 3, commands = ["DOWN","RIGHT","UP"];
console.log(finalPositionOfSnake(n, commands));
