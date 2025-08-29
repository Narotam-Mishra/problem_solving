
// Problem link - https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/?envType=daily-question&envId=2025-08-29

let flowerGame = function(n, m) {
    // Alice wins when (x + y) is odd
    // this happens when one number is odd and the other is even

    // step 1 - count odd and even numbers in range [1, n]
    const oddN = Math.floor((n + 1)/2);
    const evenN = Math.floor(n/2);

    // step 2 - count odd and even numbers in range [1, m]
    const oddM = Math.floor((m + 1)/2);
    const evenM = Math.floor(m/2);

    // Alice wins when :-
    // x is odd and y is even or
    // x is even or y is odd

    // step 3 - find total number of pairs where `x` is odd and `y` is even
    const np1 = oddN * evenM

    // step 4 - find number of pairs where `x` is even and `y` is odd
    const np2 = evenN * oddM;

    // step 5 - return total count
    return np1 + np2;
};

// const n = 3, m = 2;

const n = 1, m = 1;
console.log(flowerGame(n, m));