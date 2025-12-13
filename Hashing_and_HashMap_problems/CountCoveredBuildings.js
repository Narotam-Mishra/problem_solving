
// Problem link - https://leetcode.com/problems/count-covered-buildings/description/

/**
 * @param {number} n
 * @param {number[][]} buildings
 * @return {number}
 */
let countCoveredBuildings = function (n, buildings) {
    // row (y) -> [minX, maxX]
    const yMinMaxX = new Map();

    // column (x) -> [minY, maxY]
    const xMinMaxY = new Map();

    // step 1 - build min-max maps
    for (const [x, y] of buildings) {

        if (!yMinMaxX.has(y)) {
            yMinMaxX.set(y, [Infinity, -Infinity]);
        }

        if (!xMinMaxY.has(x)) {
            xMinMaxY.set(x, [Infinity, -Infinity]);
        }

        // update row minX and maxX
        yMinMaxX.get(y)[0] = Math.min(yMinMaxX.get(y)[0], x);
        yMinMaxX.get(y)[1] = Math.max(yMinMaxX.get(y)[1], x);

        // update column minY and maxY
        xMinMaxY.get(x)[0] = Math.min(xMinMaxY.get(x)[0], y);
        xMinMaxY.get(x)[1] = Math.max(xMinMaxY.get(x)[1], y);
    }

    // step 2 - check coverage
    let coveredCount = 0;

    for (const [x, y] of buildings) {
        const row = yMinMaxX.get(y);
        const col = xMinMaxY.get(x);

        // step 3 - check four directions
        const left  = row[0] < x;
        const right = row[1] > x;
        const down  = col[0] < y;
        const up    = col[1] > y;

        // step 4 - count if covered
        if (left && right && up && down) {
            coveredCount++;
        }
    }

    // step 5 - return the count of covered buildings
    return coveredCount;
};

// const n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]];

// const n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]];

const n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]];
console.log(countCoveredBuildings(n, buildings));
