
// Problem link - https://leetcode.com/problems/valid-perfect-square/description/

let isPerfectSquare = function(num) {
    let s = 1, e = num;

    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        if(mid * mid == num){
            return true;
        }else if(mid * mid < num){
            // discard left halft
            s = mid + 1;
        }else{
            // discard right half
            e = mid - 1;
        }
    }
    return false;
};