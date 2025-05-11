
// Problem link - https://leetcode.com/problems/robot-return-to-origin/description/?envType=problem-list-v2&envId=string

let judgeCircle = function(moves) {
    // step 1 - intilaize variables to keep track of position
    let x = 0, y = 0;

    // step 2 - iterate on each move
    for(let move of moves){
        // step 3 - incremnt / decremnt position as per its move
        // for Up (U) and Right (R) moves increment its position
        // for Down (D) and Left (L) moves decrement its position
        if(move === 'U'){
            y++;
        }else if(move === 'D'){
            y--;
        }else if(move === 'R'){
            x++;
        }else{
            x--;
        }
    }

    // step 4 - check whether Robot returns to its origin or not
    return x === 0 && y === 0;
};

const moves = "UD";

// const moves = "LL";

// const moves = "RRDD"
console.log(judgeCircle(moves));
