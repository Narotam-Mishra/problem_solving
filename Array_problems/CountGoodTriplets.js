
// Problem link - https://leetcode.com/problems/count-good-triplets/description/?envType=problem-list-v2&envId=array

let countGoodTriplets = function(arr, a, b, c) {
    // store count of good triplets
    let count = 0;
    const n = arr.length;

    // step 1 - use three nested loops to generate all possible triplets
    // where i < j < k (maintaining the required order)
    for(let i=0; i<n-2; i++){
        for(let j=i+1; j<n-1; j++){
            for(let k=j+1; k<n; k++){

                // step 2 - check all three conditions for current triplet
                // condition-1
                let diff1 = Math.abs(arr[i] - arr[j]);
                
                // condition-2
                let diff2 = Math.abs(arr[j] - arr[k]);
                
                // condition-3
                let diff3 = Math.abs(arr[i] - arr[k]);

                // step 3 - if all conditions are satisfied, increment count
                if(diff1<=a && diff2<=b && diff3<=c){
                    count++;
                }
            }
        }
    }

    // step 4 - return count of good triplets
    return count;
};

// const arr = [3,0,1,1,9,7], a = 7, b = 2, c = 3;

const arr = [1,1,2,2,3], a = 0, b = 0, c = 1;
console.log(countGoodTriplets(arr,a,b,c));