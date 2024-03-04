
// sort array's numbers using selection sort algorithm
// Time Complexity --> O(n^2)

function findMinIndex(arr,i){
    //let us assume initally the first number is minimum
    let minIndex = i;
    for(let j=i+1; j<arr.length; j++){
        if(arr[j] < arr[minIndex]){
            minIndex = j;
        }
    }
    return minIndex;
}

function selectionSort(arr){
    for(let i=0; i<arr.length; i++){
        let minIndex = findMinIndex(arr,i);
        if(minIndex !== i){
            let tem = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = tem;
        }
    }
}

let arr = [7,2,5,1,4,3];
console.log("Unsorted Array: ",arr);
selectionSort(arr);
console.log("Sorted Array: ",arr);