
// Problem link - https://leetcode.com/problems/sqrtx/description/

let mySqrt = function(x) {
    let s = 1, e = x;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2)

        if(mid * mid < x){
            // discard left half
            s = mid + 1;
        }else if(mid * mid > x){
            // otherwise discard right half
            e = mid - 1;
        }else{
            return mid;
        }
    }
    return e;
};