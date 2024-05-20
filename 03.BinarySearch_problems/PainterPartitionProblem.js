
// Problem link - https://www.naukri.com/code360/problems/painter-s-partition-problem_1089557?utm_source=youtube&utm_medium=affiliate&utm_campaign=codestudio_Striver_BinarySeries&leftPanelTabValue=PROBLEM

function isPossibleToPaintWithMidTime(C, k, mid){
    // start with one pointer and time taken 
    // Initialize current time to 0 (time taken by the current painter)
    let totalPainters = 1, currentTime = 0;

    // Loop through each board length in the array C
    for(let len of C){
        // if adding time to paint this board exceed the mid time limit
        if(currentTime + len > mid){
            // increment total painter as new painter is needed
            totalPainters++;
            // reset current time
            currentTime = 0;

            // if total painters exceed the no of avaialable painter(A) then return false
            if(totalPainters > k){
                return false;
            }
        }
        // Add the time taken to paint this board by the current painter
        currentTime += len;
    }
    // If all boards can be painted within the given 'mid' time limit, return true
    return true;
}

let paintBoard = function(boards, k){
    let maxNum = Math.max(...boards);
    let totalSum = boards.reduce((acc, cur) => acc + cur, 0);

    let low = maxNum, high = totalSum;
    let ans = -1;

    while(low <= high){
        let mid = low + Math.floor((high - low)/2);
        if(isPossibleToPaintWithMidTime(boards, k, mid)){
            // found probable answer as mid
            ans = mid;
            // since we have to find minimum time required to paint all boards
            // hence discard right half of array
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

// let boards = [2, 1, 5, 6, 2, 3];
// let k = 2;

let boards = [10,20,30,40];
let k = 2;

let ans = paintBoard(boards, k);
console.log(ans);