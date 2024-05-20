
function findFirstRepeatingValue(arr,len){
    for(let i=0; i<len; i++){
        for(let j=i+1; j<len; j++){
            if(arr[i] === arr[j]){
                return arr[i];
            }
        }
    }
    return -1;
}

// let arr = [3,4,5,6,7,9];
let arr = [12,9,7,11,12,4,5,12];
console.log(findFirstRepeatingValue(arr,arr.length));