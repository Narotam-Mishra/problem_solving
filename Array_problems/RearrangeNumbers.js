
// Problem link - https://leetcode.com/problems/rearrange-array-elements-by-sign/


function RearrangeNumbers(arr, len){
    let res = [];
    let pNums = [len/2];
    let nNums = [len/2];

    let i, j;
    i = j = 0;

    for(let num of arr){
        if(num > 0){    
            pNums[i++] = num;
        }else{
            nNums[j++] = num;
        }
    }

    let k = 0;
    for(let l=0; l<len; l+=2){
        res[l] = pNums[k];
        res[l+1] = nNums[k];
        k++;
    }

    return res;
}

let arr = [1,2,3,-4];

console.log(RearrangeNumbers(arr,arr.length));