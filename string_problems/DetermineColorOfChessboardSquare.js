
// Problem link - https://leetcode.com/problems/determine-color-of-a-chessboard-square/description/?envType=problem-list-v2&envId=string

let squareIsWhite = function(coordinates) {
    // step 1 - extract character and number from coordinates
    let char = coordinates[0];
    let num = coordinates[1];

    // step 2 - find sum of both co-ordinates by converting the character into corresponding numeric value 
    let sum = (char.charCodeAt(0) - 'a'.charCodeAt(0) + 1) + Number(num);
    
    // step 3 - check whether sum is odd or even and return true and false accordingly
    if(sum % 2 === 0){
        // return false for even sum
        return false;
    }else{
        // return true for odd sum
        return true;
    }
};

// const coordinates = "a1";

// const coordinates = "b3";

const coordinates = "c7";
console.log(squareIsWhite(coordinates));
