
// Problem link - https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room/description/?envType=problem-list-v2&envId=string

let minimumChairs = function(s) {
    // step 1 - intialize all necessary variables
    let currentOccupancy = 0;
    let maxNumberOfChairs = 0;

    // step 2 - iterate on each character of input `s`
    for(let ch of s){
        if(ch === 'E'){
            // step 3 - increment current occupancy for each entry
            currentOccupancy++;

            // step 4 - update max chairs needed if current occupancy exceed
            if(currentOccupancy > maxNumberOfChairs){
                maxNumberOfChairs = currentOccupancy;
            }
        }else{
            // step 5 - decrement current occupancy for each leave
            currentOccupancy--;
        }
    }

    // step 6 - return max number of chairs
    return maxNumberOfChairs;
};

// const s = "EEEEEEE";

// const s = "ELELEEL";

const s = "ELEELEELLL";
console.log(minimumChairs(s));
