
// Problem link - https://leetcode.com/problems/arranging-coins/description/

// Approach - 1 (using binary search)
// TC - O(logN)
let arrangeCoins = function(n) {
    let s = 1, e = n;
    let ans = 1;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        let val = Math.floor((mid * (mid+1))/2);

        if(val <= n){
            // we get the first potential ans in val
            ans = mid;
            // if we find potential ans then we can better ans in right half of array,
            // because we have of find maximum number of i.e k (mid) such k<=n
            // discard left half of array
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
    return ans;
}

// Approach - 2 (using Maths formula)
// TC - O(1)

