
// Problem link - https://leetcode.com/problems/trapping-rain-water/description/

let trap = function(height) {
    const n = height.length;

    // step 1 - find left max
    const leftMax = new Array(n);
    leftMax[0] = height[0];
    for(let i=1; i<n; i++){
        leftMax[i] = Math.max(leftMax[i-1], height[i]);
    }

    // step 2 - find right max
    const rightMax = new Array(n);
    rightMax[n-1] = height[n-1];
    for(let i=n-2; i>=0; i--){
        rightMax[i] = Math.max(rightMax[i+1], height[i]);
    }

    // step 3 - find total water stored 
    let totalWaterStored = 0;
    for(let i=0; i<n; i++){
        let h = Math.min(leftMax[i], rightMax[i]) - height[i];
        totalWaterStored += h;
    }

    // step 4 - return total water stored
    return totalWaterStored;
};

// const height = [0,1,0,2,1,0,1,3,2,1,2,1];

const height = [4,2,0,3,2,5];
console.log(trap(height));