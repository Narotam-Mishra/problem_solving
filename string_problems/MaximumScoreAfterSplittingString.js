
// Problem link - https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=problem-list-v2&envId=string

let maxScore1 = function(s) {
    // step 1 - store maximum score in `maxScore`
    let maxScore = 0;

    // maintain count of 1's and 0's
    let oneCount = 0, zeroCount = 0;

    // step 2 - get total number of 1's in string `s`
    let totalOnes = [...s].filter((char) => char === '1').length;
    
    // step 3 - iterate on each character of binary string `s`
    // go upto s.length - 1 to ensure right substring is not empty
    for(let i=0; i<s.length-1; i++){
        // count 0's 
        if(s[i] === '0'){
            zeroCount++
        }else{
            // count 1's
            oneCount++;
        }

        // step 4 - calculate score on basis of counts of 1's and 0's
        let score = zeroCount + (totalOnes - oneCount);
        
        // step 5 - update maximum score
        maxScore = Math.max(score, maxScore);
    }

    // step 6 - return maximum score `maxScore`
    return maxScore;
};

let maxScore = function(s) {
    // step 1 - store maximum score in `maxScore`
    let maxScore = 0;

    // step 2 - get total number of 1's in string `s`
    let totalOnes = [...s].filter((char) => char === '1').length;
    
    // maintain count of 1's and 0's
    let oneCount = totalOnes, zeroCount = 0;

    // step 3 - iterate on each character of binary string `s`
    // go upto s.length - 1 to ensure right substring is not empty
    for(let i=0; i<s.length-1; i++){
        // count 0's 
        if(s[i] === '0'){
            zeroCount++
        } else {
            oneCount--;
        }

        // step 4 - calculate maximum score `maxScore` on basis of counts of 1's and 0's
        maxScore = Math.max(maxScore, zeroCount + oneCount);
    }

    // step 5 - return maximum score `maxScore`
    return maxScore;
};

// const s = "011101";

// const s = "00111";

// const s = "1111";

const s = "00";
console.log(maxScore(s));
