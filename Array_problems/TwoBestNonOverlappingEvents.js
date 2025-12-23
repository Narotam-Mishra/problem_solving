
// Problem link - https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2025-12-23

let maxTwoEvents = function(events) {
    const n = events.length;

    // sort events by start time
    events.sort((a, b) => a[0] - b[0]);

    // memo[i][count] = max value from index i with count events taken
    const memo = Array.from({ length: n }, () => Array(3).fill(-1));

    // binary search to find next event whose start time > endTime
    function binarySearch(endTime) {
        let s = 0, e = n - 1;
        let res = n;

        while (s <= e) {
            const mid = Math.floor(s + (e - s) / 2);
            if (events[mid][0] > endTime) {
                res = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }
        return res;
    }

    function solveRec(i, count) {
        // base case
        if (count === 2 || i >= n) {
            return 0;
        }

        // already computed
        if (memo[i][count] !== -1) {
            return memo[i][count];
        }

        // next valid event index
        const nextValidIdx = binarySearch(events[i][1]);

        // option 1: attend current event
        const attend =
            events[i][2] + solveRec(nextValidIdx, count + 1);

        // option 2: skip current event
        const skip = solveRec(i + 1, count);

        memo[i][count] = Math.max(attend, skip);
        return memo[i][count];
    }

    return solveRec(0, 0);
};
