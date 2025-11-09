
// Problem link - https://leetcode.com/problems/count-operations-to-obtain-zero/description/?envType=daily-question&envId=2025-11-09

let countOperations1 = function(num1, num2) {
    // store required number of operations in `count`
    let count = 0;

    // step 1 - stop when either num1 or num2 becomes 0.
    while (num1 !== 0 && num2 !== 0) {
        // step 2 - perform the given operation
        if (num1 >= num2) {
            num1 = num1 - num2;
        } else {
            num2 = num2 - num1;
        }

        // step 3 - increment count
        count++;
    }

    // step 4 - return count
    return count;
};

let countOperations = function(num1, num2) {
    // store required number of operations in `count`
    let count = 0;

    // step 1 - stop when either num1 or num2 becomes 0.
    while (num1 > 0 && num2 > 0) {
        // step 2 - if num1 >= num2 we will subtract num2 repeatedly from
        // num1. number of such single subtractions equals num1 / num2.
        count += Math.floor(num1 / num2);

        // step 3 - after subtracting num2 (num1 / num2) times,
        // so, num1 becomes the remainder.
        num1 = num1 % num2;

        // step 4 - swap roles so the larger value is always in num1 for next iteration
        let temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // step 5 - return count
    return count;
};

const num1 = 2, num2 = 3;

// const num1 = 10, num2 = 10;
console.log(countOperations(num1, num2));