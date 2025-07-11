
// Problem link - https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/description/?envType=problem-list-v2&envId=array

let kidsWithCandies = function(candies, extraCandies) {
    // store result in `res` array
    const res = [];

    // step 1 - find maximum number of candies
    let maxNumCancy = Math.max(...candies);

    // step 2 - iterate on each candy from `candies`
    for(let numCandy of candies){
        // step 3 - check if kid has greatest number of candies among all or not
        if(numCandy + extraCandies >= maxNumCancy){
            // add true 
            res.push(true);
        }else{
            // otherwise add false
            res.push(false);
        }
    }

    // step 4 - return resultant array `res`
    return res;
};

// const candies = [2,3,5,1,3], extraCandies = 3;

// const candies = [4,2,1,1,2], extraCandies = 1;

const candies = [12,1,12], extraCandies = 10;
console.log(kidsWithCandies(candies, extraCandies));