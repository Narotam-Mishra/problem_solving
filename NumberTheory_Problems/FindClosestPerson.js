
// Problem link - https://leetcode.com/problems/find-closest-person/?envType=daily-question&envId=2025-09-04

let findClosest = function(x, y, z) {
    // step 1 - find absolute difference (distance)
    // between `x` & `z` and `y` & `z`
    let distX = Math.abs(z - x);
    let distY = Math.abs(z - y);

    // step 2 - compare each speed and return  
    if(distX < distY){
        return 1;
    }else if(distY < distX){
        return 2;
    }else{
        return 0;
    }
};

// const x = 2, y = 7, z = 4;

// const x = 2, y = 5, z = 6;

const x = 1, y = 5, z = 3;
console.log(findClosest(x,y,z));