// Problem link - https://www.codingninjas.com/studio/problems/find-unique_625159?leftPanelTabValue=PROBLEM

function findUniqueNumber(arr,len){
    let ans = 0;
    for(let i=0; i<len; i++){
        ans = ans^arr[i];
    }
    return ans;
}

let arr = [1, 3, 1, 3, 6, 6, 7, 10, 7];
console.log(findUniqueNumber(arr,arr.length));