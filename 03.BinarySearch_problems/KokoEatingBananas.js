
// Problem link - https://leetcode.com/problems/koko-eating-bananas/description/

function canEatAllBananasInMidSpeed(piles, mid, h){
    // time taken to eat a pile of banans = ceil value of(piles[i]/mid)
    // where piles[i] is number of bananas in ith pile and 'mid' is speed
    let totalHrs = 0;
    for(let i=0; i<piles.length; i++){
        // total time to finish ith pile
        totalHrs += Math.ceil(piles[i]/mid);  
    }
    // check if total bananas finished within h hours
    return totalHrs <= h;
}

let minEatingSpeed = function(piles, h) {
    // define the search space to determine minimum speed k
    // minimum 1 and maximum max number of piles to determine search space
    let maxBanana = Math.max(...piles);
    // let us assume ans i.e minimum speed is 1
    let s = 1, e = maxBanana, ans = 1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        // check if Koko can eat all bananas at mid speed within 'h' hrs
        if(canEatAllBananasInMidSpeed(piles, mid, h)){
            // we get a potential ans as mid
            ans = mid;
            // since we need to find minimum speed 'k' hence we discard right half of array
            e = mid - 1;
        }else{
            // otherwise discard left half of array
            s = mid + 1;
        }
    }
    return ans;
};

let arr = [30,11,23,4,20];
let h = 6;

let ans = minEatingSpeed(arr,h);
console.log(ans);