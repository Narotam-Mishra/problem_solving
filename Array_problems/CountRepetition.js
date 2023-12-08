
function countOccuranceInArray(arr, x, len){
    let count = 0;
    
    for(let i=0; i<len; i++){
        if(arr[i] === x){
            count++;
        }
    }
    return count;
}

let arr = [2,5,7,6,7,9,7,6,7];
let x = 7;
console.log(countOccuranceInArray(arr,x,arr.length));

// CountRepetition.js