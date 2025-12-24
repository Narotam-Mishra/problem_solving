
// Problem link - https://leetcode.com/problems/apple-redistribution-into-boxes/?envType=daily-question&envId=2025-12-24

let minimumBoxes = function(apple, capacity) {
    // step 1 - sort capacity in ascending order
    capacity.sort((a, b) => b - a);

    // step 2 - find sum of all apples
    let applesSum = 0;
    for(let a of apple){
        applesSum += a;
    }

    // step 3 - start distributing apples starting from largest box
    // and maintain box count
    let currApples = 0, boxCount = 0;
    for(let cap of capacity){
        currApples += cap;
        boxCount++;
        if(currApples >= applesSum){
            return boxCount;
        }
    }

    // step 4 - return the minimum number of boxes
    return boxCount;
};

// const apple = [1,3,2], capacity = [4,3,1,5,2];

const apple = [5,5,5], capacity = [2,4,2,7];
console.log(minimumBoxes(apple, capacity));