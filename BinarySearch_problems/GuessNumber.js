
// Problem link - https://leetcode.com/problems/guess-number-higher-or-lower/

let guessNumber = function(n) {
    let s = 1, e = n;
    
    while(s <= e){
        let mid = s + Math.floor((e - s)/2);
        let val = guess(mid);
        if(val === 0){
            return mid;
        }else if(val === 1){
            s = mid + 1;
        }else{
            e = mid - 1;
        }
    }
};