
// Problem link - https://leetcode.com/problems/furthest-point-from-origin/description/?envType=problem-list-v2&envId=string

let furthestDistanceFromOrigin = function(moves) {
    // step 1 - initialize counters
    let left = 0, right = 0, dash = 0;

    // step 2 - traverse each character of moves
    for(let move of moves){
        // step 3 - count left, right & dashed (-)
        if(move === 'L'){
            left++;
        }else if(move === 'R'){
            right++;
        }else{
            dash++;
        }
    }

    // step 4 - assign all dash to the left
    let op1 = Math.abs((left + dash) - right);

    // step 5 - assign all dash to the right
    let op2 = Math.abs((right + dash) - left);

    // step 6 - return maximum distance from origin
    return Math.max(op1, op2);
};

// const moves = "L_RL__R";

// const moves = "_R__LL_";

const moves = "_______";
console.log(furthestDistanceFromOrigin(moves));
