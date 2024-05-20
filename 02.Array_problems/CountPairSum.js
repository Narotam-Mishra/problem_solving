
function countPairSum(arr,x,len){
    let count = 0;
    
    for(let i=0; i<len; i++){
        for(let j=i+1; j<len; j++){
            if(arr[i]+arr[j] == x){
                count++;
            }
        }
    }
    return count;
}

let arr = [4,6,3,5,8,2];
let x = 7
console.log(countPairSum(arr,x,arr.length));