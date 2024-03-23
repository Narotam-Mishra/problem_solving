
// Problem link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

function canShipMidWeightsInDdays(arr, mid, days){
    let dc = 0, tw = 0;
    for(let i=0; i<arr.length; i++){
        if(arr[i] + tw > mid){
            dc++;
            tw = 0;
        }
        tw += arr[i];
    }
    dc++;
    return dc <= days;
}

let shipWithinDays = function(weights, days) {
    let maxWeight = -1, totalWeight = 0;

    for(let w of weights){
        totalWeight += w;
        maxWeight = Math.max(maxWeight, w);
    }
    // since we may not load more weight than the maximum weight capacity of the ship.
    //hence search space will be from start = maxweight to end = totalWeight
    
    let start = maxWeight, end = totalWeight;
    let ans = -1;
    while(start <= end){
        let mid = start + Math.floor((end - start)/2);
        if(canShipMidWeightsInDdays(weights, mid, days)){
            // we got first probable answer
            ans = mid;
            // since we have to find least weight capacity, hence we discard right half
            end = mid - 1;
        }else{
            // otherwise discard left half
            start = mid + 1
        }
    }
    return ans;
};

// let arr = [1,2,3,4,5,6,7,8,9,10];
// let days = 5;

let arr = [3,2,2,4,1,4];
let days = 3;
let ans = shipWithinDays(arr,days);
console.log(ans);