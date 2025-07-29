
// Problem link - https://leetcode.com/problems/maximum-height-of-a-triangle/?envType=problem-list-v2&envId=array

#include<bits/stdc++.h>
using namespace std;

// step 1 - create helper function to calculate maximum height starting with a specific color
int getMaximumHeight(int firstColor, int secondColor) {
    // calculate height
    int height = 0;

    // start from 1st row 
    int currentRow = 1;

    // track remaining number of balls
    int remainingFirstBall = firstColor;
    int remainingSecondBall = secondColor;

    // start forming triangle and paralley calculate its height
    while (true) {
        if (currentRow % 2 == 1) {
            if (remainingFirstBall >= currentRow) {
                remainingFirstBall -= currentRow;
                height++;
            }
            else {
                break;
            }
        }
        else {
            if (remainingSecondBall >= currentRow) {
                remainingSecondBall -= currentRow;
                height++;
            }
            else {
                break;
            }
        }
        currentRow++;
    }

    // return calculated height
    return height;
}

int maxHeightOfTriangle(int red, int blue) {
    // step 2 - try both possibilities: starting with red or starting with blue
        // case 1 - start with `red` as first color
    int maxHeightUsingRed = getMaximumHeight(red, blue);

    // case 2 - start with `blue` as first color
    int maxHeightUsingBlue = getMaximumHeight(blue, red);

    // step 3 - return the maximum height achievable from both cases
    return max(maxHeightUsingRed, maxHeightUsingBlue);
}

int main(){
    // int red = 2, blue = 4;

    // int red = 2, blue = 1;

    // int red = 1, blue = 1;

    int red = 10, blue = 1;
    cout<<maxHeightOfTriangle(red, blue);
    return 0;
}