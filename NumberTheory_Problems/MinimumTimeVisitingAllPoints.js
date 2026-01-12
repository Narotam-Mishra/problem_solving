
// Problem link - https://leetcode.com/problems/minimum-time-visiting-all-points/?envType=daily-question&envId=2026-01-12

let minTimeToVisitAllPoints = function(points) {
    // keep track of minimum time
    let steps = 0;

    // step 1 - loop through consecutive points
    for (let i = 0; i < points.length - 1; i++) {
        // current point
        let [x1, y1] = points[i];

        // next point
        let [x2, y2] = points[i + 1];

        // step 2 - find Absolute differences
        let dx = Math.abs(x2 - x1);
        let dy = Math.abs(y2 - y1);

        /*
         * Use diagonal moves as much as possible,
         * then move straight for remaining distance
         */

        // step 3 - calculate time to visit all points
        steps += Math.min(dx, dy) + Math.abs(dx - dy);
    }

    // step 4 - return minimum time
    return steps;
};

// const points = [[1,1],[3,4],[-1,0]];

const points = [[3,2],[-2,2]];
console.log(minTimeToVisitAllPoints(points));