
// Problem link - https://leetcode.com/problems/find-indices-of-stable-mountains/description/?envType=problem-list-v2&envId=array

let stableMountains = function(height, threshold) {
    // store stable mountain indices in `stableMountains`
    const stableMountains = [];

    // step 1 - start from index 1 since mountain 0 cannot be stable
    // as no mountain exists before index 0
    for(let i=1; i<height.length; i++){
        // step 2 - check if the previous mountain is stable
        if(height[i-1] > threshold){
            // step 3 - add current mountain's index to result
            stableMountains.push(i);
        }
    }

    // step 4 - return stable mountain indices
    return stableMountains;
};

// const height = [1,2,3,4,5], threshold = 2;

// const height = [10,1,10,1,10], threshold = 3;

const height = [10,1,10,1,10], threshold = 10;
console.log(stableMountains(height, threshold));