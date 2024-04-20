
// Problem link - https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

function findMissingAndRepeatingNumber(arr){
    let missingNum, repeatingNum;

    let n = arr.length;
    let frqMap = Array(n+1).fill(0);

    for(let i=0; i<n; i++){
        frqMap[arr[i]]++;
    }

    for(let i=1; i<=n; i++){
        if(frqMap[i] === 0){
            missingNum = i;
        }else if(frqMap[i] === 2){
            repeatingNum = i;
        }
    }

    return [repeatingNum, missingNum];
}

let arr = [1,3,3];
let ans = findMissingAndRepeatingNumber(arr);
console.log(...ans);