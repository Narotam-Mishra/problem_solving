
function findMaximum(arr,len){
    let maxNum = Number.MIN_VALUE;
    for(let i=0; i<len; i++){
        if(arr[i] > maxNum){
            maxNum = arr[i];
        }
    }
    return maxNum;
}

function findSecondMaximum(arr,len){
    let maxVal = findMaximum(arr,len);

    // traverse the array and mark the maximum val as minus infinity
    for(let i=0; i<len; i++){
        if(arr[i] === maxVal){
            arr[i] = Number.MIN_VALUE;
        }
    }

    let secondMax = findMaximum(arr,len);
    return secondMax;
}

let arr = [12,9,7,11,12,4,5,12];
console.log(findSecondMaximum(arr, arr.length));