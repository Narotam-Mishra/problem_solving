
function linearSearch(arr,len,key){
    if(len === 0){
        return -1;
    }
    
    for(let i=0; i<len; i++){
        if(arr[i] === key){
            return i;
        }
    }
    return -1;
}

let arr = [23,11,41,43,9,7,13];
let key = 13;
console.log(linearSearch(arr,arr.length,key));