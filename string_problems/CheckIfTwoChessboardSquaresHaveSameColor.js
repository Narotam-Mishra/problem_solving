
// Problem link - https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/description/?envType=problem-list-v2&envId=string

let checkTwoChessboards = function(coordinate1, coordinate2) {
    // step 1 - extract character and number from coordinate1 & coordinate1 
    let char1 = coordinate1[0];
    let num1 = coordinate1[1];

    let char2 = coordinate2[0];
    let num2 = coordinate2[1];

    // step 2 - find sum of both co-ordinates by converting the character into corresponding numeric value 
    let sum1 = (char1.charCodeAt(0) - 'a'.charCodeAt(0) + 1) + Number(num1);

    let sum2 = (char2.charCodeAt(0) - 'a'.charCodeAt(0) + 1) + Number(num2);
    
    // step 3 - check if both sum are either even or odd then return true, otherwise return false
    if(sum1 % 2 === 0 && sum2 % 2 === 0){
        return true;
    }else if(sum1 % 2 !== 0 && sum2 % 2 !== 0){
        return true;
    }else{
        return false;
    }
};

// const coordinate1 = "a1", coordinate2 = "c3";

const coordinate1 = "a1", coordinate2 = "h3";
console.log(checkTwoChessboards(coordinate1, coordinate2));
