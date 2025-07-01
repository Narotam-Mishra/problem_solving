
// Problem link - https://leetcode.com/problems/find-the-highest-altitude/description/?envType=problem-list-v2&envId=array

let largestAltitude = function(gain) {
    // store mhighest altitude in `maxAltitude`
    let maxAltitude = 0;

    // step 1 - process each gain/loss in altitude
    let currAltitude = 0;
    for(let num of gain){
        // step 2 - // update current altitude by adding the gain
        currAltitude += num;

        // step 3 - check if this is the highest altitude we've seen so far
        if(currAltitude > maxAltitude){
            // update maxAltitude if current altitude is higher
            maxAltitude = currAltitude;
        }
    }

    // step 4 - return the highest altitude `maxAltitude` encountered during the trip
    return maxAltitude;
};

// const gain = [-5,1,5,0,-7];

const gain = [-4,-3,-2,-1,4,3,2];
console.log(largestAltitude(gain));