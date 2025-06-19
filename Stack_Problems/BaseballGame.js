
// Problem link - https://leetcode.com/problems/baseball-game/description/?envType=problem-list-v2&envId=array

let calPoints = function(operations) {
    // using stack to perform each operation
    const score = [];

    // step 1 - iterate on each operation `op`
    for(let op of operations){
        // step 2 - perform each operation in stack `score`
        if(op === '+'){
            // for `+` add sum of previous two scores
            const n = score.length;
            const newScore = score[n-1] + score[n-2];
            score.push(newScore);
        }else if(op === 'C'){
            // cancel (remove) the previous score
            score.pop()
        }else if(op === 'D'){
            // add double of previous score
            const newScore = score[score.length - 1] * 2;
            score.push(newScore);
        }else{
            // it's an integer - add new score to stack `score` record
            score.push(parseInt(op))
        }
    }

    // step 3 - return sum of all scores
    return score.reduce((sum, sc) => sum+=sc, 0);
};

// const ops = ["5","2","C","D","+"];

// const ops = ["5","-2","4","C","D","9","+","+"];

const ops = ["1","C"];
console.log(calPoints(ops));