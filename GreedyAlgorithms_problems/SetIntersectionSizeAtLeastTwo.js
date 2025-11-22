
// Problem link - https://leetcode.com/problems/set-intersection-size-at-least-two/description/

let intersectionSizeTwo = function(intervals) {
    const n = intervals.length;

    // step 1 - sort intervals
    intervals.sort((a, b) => {
        if (a[1] !== b[1]) {
            // sort by second point ascending
            return a[1] - b[1]; 
        }
        //  if equal, sort by first point descending
        return b[0] - a[0];    
    });

    // store final result in `res`
    let res = 0;

    // two selected points
    let f = -1, s = -1;

    // step 2 - process each interval
    for (let i = 0; i < n; i++) {
        const [l, r] = intervals[i];

        if (l <= f) continue;

        if (l > s) {
            // need two points
            res += 2;
            s = r;
            f = r - 1;
        } else {
            // need one point
            res += 1;
            f = s;
            s = r;
        }
    }

    // step 3 - return final result `res`
    return res;
};

// const intervals = [[1,3],[3,7],[8,9]];

// const intervals = [[1,3],[1,4],[2,5],[3,5]];

const intervals = [[1,2],[2,3],[2,4],[4,5]];
console.log(intersectionSizeTwo(intervals));