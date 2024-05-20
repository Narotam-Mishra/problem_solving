
const findMax = require('./FindMaximum');

function findSecondMaximum(arr,len){
    let maxNum = findMax(arr,len);

    for(let i=0; i<len; i++){
        if(arr[i] === maxNum){
            arr[i] = Number.MIN_VALUE;
        }
    }

    let secMaxNum = findMax(arr,len);
    return secMaxNum;
}

let arr = [19,5,6,7,15,19,8,3,19];
console.log(findSecondMaximum(arr,arr.length));