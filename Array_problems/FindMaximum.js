
function findMaximuInArray(arr,n){
    let maxNum = arr[0];
    
    for(let i=1; i<n; i++){
        if(arr[i] > maxNum){
            maxNum = arr[i];
        }
    }
    return maxNum;
}

let arr = [12, 7, 41, 22, 9, -11];
console.log(findMaximuInArray(arr, arr.length));
