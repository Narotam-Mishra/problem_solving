
// Problem link - https://leetcode.com/problems/final-value-of-variable-after-performing-operations/description/?envType=problem-list-v2&envId=string

let finalValueAfterOperations = function(operations) {
    // step 1 - set initial to 0
    let val = 0;

    // step 2 - iterate on each operation and perform accordingly
    for(let op of operations){
        // perform operation
        if(op === '--X' || op === 'X--'){
            val--
        }else{
            val++;
        }
    }

    // step 3 - return final value after all operations
    return val;
};

// const operations = ["--X","X++","X++"];

// const operations = ["++X","++X","X++"];

const operations = ["X++","++X","--X","X--"];
console.log(finalValueAfterOperations(operations));
