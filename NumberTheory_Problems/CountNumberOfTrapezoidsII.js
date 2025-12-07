
// Problem link - https://leetcode.com/problems/count-number-of-trapezoids-ii/description/

let countTrapezoids = function(points) {
    const n = points.length;
    
    // Map: slope -> array of intercepts
    const slopeIntercepts = new Map();
    
    // Map: midpoint key -> array of slopes (for parallelogram detection)
    const midPointsMap = new Map();
    
    let res = 0;
    
    // step 1 - generate all line segments from pairs of points
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const [x1, y1] = points[i];
            const [x2, y2] = points[j];
            
            const dx = x2 - x1;
            const dy = y2 - y1;
            
            let slope, intercept;
            
            // handle vertical lines (undefined slope)
            if (dx === 0) {
                // large number as "infinity"
                slope = 1e9 + 7;  

                // x-coordinate as intercept
                intercept = x1;    
            } else {
                // calculate slope and intercept
                slope = dy / dx;
                intercept = (y1 * dx - x1 * dy) / dx;
            }
            
            // create unique key for midpoint
            const midPointKey = (x1 + x2) * 10000 + (y1 + y2);
            
            // store segment information
            if (!slopeIntercepts.has(slope)) {
                slopeIntercepts.set(slope, []);
            }
            slopeIntercepts.get(slope).push(intercept);
            
            if (!midPointsMap.has(midPointKey)) {
                midPointsMap.set(midPointKey, []);
            }
            midPointsMap.get(midPointKey).push(slope);
        }
    }
    
    // step 2 - count quadrilaterals with at least one pair of parallel sides
    for (const intercepts of slopeIntercepts.values()) {
        if (intercepts.length <= 1) continue;
        
        // count segments on each parallel line
        const interceptCount = new Map();
        for (const intercept of intercepts) {
            interceptCount.set(intercept, (interceptCount.get(intercept) || 0) + 1);
        }
        
        // combinatorial counting
        let prevTotal = 0;
        for (const count of interceptCount.values()) {
            res += count * prevTotal;
            prevTotal += count;
        }
    }
    
    // step 3 - subtract parallelograms
    for (const slopes of midPointsMap.values()) {
        if (slopes.length <= 1) continue;
        
        // count segments by slope
        const slopeCount = new Map();
        for (const slope of slopes) {
            slopeCount.set(slope, (slopeCount.get(slope) || 0) + 1);
        }
        
        // remove parallelogram combinations
        let prevTotal = 0;
        for (const count of slopeCount.values()) {
            res -= count * prevTotal;
            prevTotal += count;
        }
    }

    // step 4 - return fianl result, `res`
    return res;
};

// const points = [[-3,2],[3,0],[2,3],[3,2],[2,-3]];

const points = [[0,0],[1,0],[0,1],[2,1]];
console.log(countTrapezoids(points));