
// Problem link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/?envType=daily-question&envId=2026-01-31

let nextGreatestLetter = function(letters, target) {
    // find size of letters
    const n = letters.length;

    // step 1 - apply binary search and find result
    let s = 0, e = n-1;

    let ansPos = -1;
    while(s <= e){
        let mid = Math.floor((s + e) / 2);

        if(letters[mid] > target){
            ansPos = mid;
            e = mid-1;
        }else{
            s = mid + 1;
        }
    }

    // step 2 - return first character if no target exist
    // otherwise return required result
    return ansPos == -1 ? letters[0] : letters[ansPos];
};

// const letters = ["c","f","j"], target = "a";

// const letters = ["c","f","j"], target = "c";

const letters = ["x","x","y","y"], target = "z";
console.log(nextGreatestLetter(letters, target));