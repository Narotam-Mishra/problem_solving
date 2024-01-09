
function swap(arr, i, j){
    let temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

function reverseArray(arr, s ,e){
    while(s<e){
        swap(arr,s,e);
        s++;
        e--;
    }
}

function printArray(arr){
    for(let i=0; i<arr.length; i++){
        process.stdout.write(arr[i] + " ");
    }
}
function roatateArrayInPlace(arr, k){
    let len = arr.length;
    k = k % len;
    reverseArray(arr, 0, len-k-1);
    reverseArray(arr, len-k, len-1);
    reverseArray(arr, 0, len-1);
    printArray(arr);
}

let arr = [1,2,3,4,5,6,7,8,9];

roatateArrayInPlace(arr, 4);