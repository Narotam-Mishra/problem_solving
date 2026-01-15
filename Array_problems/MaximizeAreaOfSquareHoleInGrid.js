
// Problem link - https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/?envType=daily-question&envId=2026-01-15

let maximizeSquareHoleArea = function (n, m, hBars, vBars) {
    // sort the input arrays
    hBars.sort((a, b) => a - b);
    vBars.sort((a, b) => a - b);

    // keep track of longest consecutive horizontal and vertical bars
    let maxConsecutiveHBar = 1, maxConsecutiveVBar = 1;

    // step 1 - first find length of longest consecutive horizontal bars
    let currConsecutiveHBars = 1;
    for (let i = 1; i < hBars.length; i++) {
        if (hBars[i] - hBars[i - 1] == 1) {
            currConsecutiveHBars++;
        } else {
            currConsecutiveHBars = 1;
        }
        maxConsecutiveHBar = Math.max(maxConsecutiveHBar, currConsecutiveHBars);
    }

    // step 2 - first find length of longest consecutive vertical bars
    let currConsecutiveVBars = 1;
    for (let i = 1; i < vBars.length; i++) {
        if (vBars[i] - vBars[i - 1] == 1) {
            currConsecutiveVBars++;
        } else {
            currConsecutiveVBars = 1;
        }
        maxConsecutiveVBar = Math.max(maxConsecutiveVBar, currConsecutiveVBars);
    }

    // step 3 - find side square formed
    let side = Math.min(maxConsecutiveHBar, maxConsecutiveVBar) + 1;

    // step 4 - return maximum area
    return side * side;
};

const n = 2, m = 1, hBars = [2,3], vBars = [2];
console.log(maximizeSquareHoleArea(n,m,hBars,vBars));