
// Problem link - https://leetcode.com/problems/convert-integer-to-the-sum-of-two-no-zero-integers/description/?envType=daily-question&envId=2025-09-08

let getNoZeroIntegers = function(n) {

    // utility function whether number `num` has zero or not
    const hasZero = (num) => {
        return num.toString().includes('0');
    }

    // step 1 - start with a = 1 and b = n-1
    let a = 1;
    let b = n - 1;

    // step 2 - keep searching until we find a valid pair
    // since a solution is guaranteed, this loop will terminate
    while(hasZero(a) || hasZero(b)){
        // try next value of `a`
        a++;

        // update `b` to maintain sum
        b = n - a;
    }

    // step 3 - return required numbers `a` and `b`
    return [a, b];
};

// const n = 11;

const n = 2;
console.log(getNoZeroIntegers(n));