
// Problem Link - https://www.interviewbit.com/problems/painters-partition-problem/

/*

param A : integer (No. of painters)
param B : integer (time taken by each painter)
param C : array of integers (length of ith board.)
return an integer

*/

function isPossibleToPaintWithMidTime(A,B,C, mid){
    // start with one pointer and time taken 
    // Initialize current time to 0 (time taken by the current painter)
    let totalPainters = 1, currentTime = 0;

    // Loop through each board length in the array C
    for(let len of C){
        // if adding time to paint this board exceed the mid time limit
        if(currentTime + len*B > mid){
            // increment total painter as new painter is needed
            totalPainters++;
            // reset current time
            currentTime = 0;

            // if total painters exceed the no of avaialable painter(A) then return false
            if(totalPainters > A){
                return false;
            }
        }
        // Add the time taken to paint this board by the current painter
        currentTime += len * B;
    }
    // If all boards can be painted within the given 'mid' time limit, return true
    return true;
}

let paintBoard = function(A, B, C){
    let maxNum = Math.max(...C) * B;
    let totalSum = C.reduce((acc, cur) => acc + cur, 0) * B;

    let low = maxNum, high = totalSum;
    let ans = -1;
    while(low <= high){
        let mid = low + Math.floor((high - low)/2);
        if(isPossibleToPaintWithMidTime(A,B,C, mid)){
            // found probable answer as mid
            ans = mid;
            // since we have to find minimum time required to paint all boards
            // hence discard right half of array
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans % 10000003 !== -1 ? ans % 10000003 : -1;
}

// let A = 2
// let B = 5
// let C = [1,10];

let A = 10
let B = 1
let C = [1,8,11,3];

let ans = paintBoard(A,B,C);
console.log(ans);