
function rotateArrayByK(arr:number[],k:number): number[]{
    let n = arr.length; k = k%n;
    let res:number[] = [];
    
    for(let i=n-k; i<n; i++){
        res.push(arr[i]);
    }

    for(let i=0; i<n-k; i++){
        res.push(arr[i]);
    }

    return res;
}

let arr:number[] = [1,2,3,4,5,6,7];
let k:number = 3;

console.log(rotateArrayByK(arr,k));
