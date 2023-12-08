
function lastOccuranceIndex(arr,x,len){
    lastIndex = -1;
    for(let i=0; i<len; i++){
        if(arr[i] == x){
            lastIndex = i;
        }
    }
    return lastIndex;
}

let arr = [4,6,9,7,8,7,3,7,2,];
let x = 7;
console.log(lastOccuranceIndex(arr,x,arr.length));