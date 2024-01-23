
/*

Given the arrival and departure times of all trains that reach a railway station, the task is to find the minimum number of platforms required for the railway station so that no train waits. We are given two arrays that represent the arrival and departure times of trains that stop.

Input: arr[] = {9:00, 9:40, 9:50, 11:00, 15:00, 18:00}, dep[] = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00} 
Output: 3 
Explanation: There are at-most three trains at a time (time between 9:40 to 12:00)

*/

function findPlatform(arr, dep, n){
    let numOfPlatform = 1;
    let res = 1;

    for(let i=0; i<n; i++){
        numOfPlatform = 1;
        for(let j=0; j<n; j++){
            // checking for time overlap
            if(i !== j){
                if(arr[i] >= arr[j] && dep[j] >= arr[i]){
                    numOfPlatform++;
                }
            }
        }
        res = Math.max(numOfPlatform, res);
    }
    return res;
}

let arr = [900, 940, 950, 1100, 1500, 1800]
let dep = [910, 1200, 1120, 1130, 1900, 2000];
let n = 6;

// let arr = [900, 940]
// let dep = [910, 1200];
// let n = 2;

console.log(findPlatform(arr,dep,n));