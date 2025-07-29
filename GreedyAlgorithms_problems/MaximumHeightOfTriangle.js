
// Problem link - https://leetcode.com/problems/maximum-height-of-a-triangle/description/?envType=problem-list-v2&envId=array

let maxHeightOfTriangle = function(red, blue) {
    // step 1 - create helper function to calculate maximum height starting with a specific color
    function getMaximumHeight(firstColor, secondColor){
        // calculate height
        let height = 0;

        // start from 1st row 
        let currentRow = 1;

        // track remaining number of balls
        let remainingFirstBall = firstColor;
        let remainingSecondBall = secondColor;

        // start forming triangle and paralley calculate its height
        while(true){
            if(currentRow % 2 === 1){
                if(remainingFirstBall >= currentRow){
                    remainingFirstBall -= currentRow;
                    height++;
                }else{
                    break;
                }
            }else{
                if(remainingSecondBall >= currentRow){
                    remainingSecondBall -= currentRow;
                    height++;
                }else{
                    break;
                }
            }
            currentRow++;
        }

        // return calculated height
        return height;
    }

    // step 2 - try both possibilities: starting with red or starting with blue
    // case 1 - start with `red` as first color
    let heightWithRed = getMaximumHeight(red, blue);

    // case 2 - start with `blue` as first color
    let heightWithBlue = getMaximumHeight(blue, red);

    // step 3 - return the maximum height achievable from both cases
    return Math.max(heightWithRed, heightWithBlue);
};

// const red = 2, blue = 4;

// const red = 2, blue = 1;

// const red = 10, blue = 1;

const red = 1, blue = 1;
console.log(maxHeightOfTriangle(red, blue));