
/*
Given an array sorted in increasing order of size n and an integer x, find if there exists a 
pair in the array whose absolute difference is exactly x.(n>1) 

N = 5
Arr = [5,10,15,20,26]
x = 10

Expecated Output : Yes

*/

function findAbsoluteDifference(arr,len,x){
    for(let i=0; i<len; i++){
        for (let j=i+1; j<len; j++){
            if(arr[j] - arr[i] === x){
                console.log("Yes");
                return;
            }
        }
    }
    console.log("No");
}

let arr = [5,10,15,20,26];
let x = 10;

findAbsoluteDifference(arr, arr.length, x);