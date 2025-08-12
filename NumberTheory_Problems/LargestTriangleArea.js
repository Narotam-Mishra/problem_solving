
// Problem link - https://leetcode.com/problems/largest-triangle-area/description/?envType=problem-list-v2&envId=array

let largestTriangleArea = function(points) {
    // step 1 - store maximum area in `maxArea`
    let maxArea = 0;

    // step 2 - generate all possible combinations of 3 points using three nested loops
    const n = points.length;
    for(let i=0; i<n-2; i++){
        for(let j=i+1; j<n-1; j++){
            for(let k=j+1; k<n; k++){
                let [x1, y1] = points[i];
                let [x2, y2] = points[j];
                let [x3, y3] = points[k];

                // step 3 - calculate area using cross product formula
                // formula: Area = 0.5 * |x1(y2-y3) + x2(y3-y1) + x3(y1-y2)|
                let area = 0.5 * Math.abs(
                    x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
                );

                // step 4 - update maximum area
                maxArea = Math.max(maxArea, area);
            }
        }
    }

    // step 5 - return maximum area of triangle
    return maxArea;
};

const points = [[0,0],[0,1],[1,0],[0,2],[2,0]];

// const points = [[1,0],[0,0],[0,1]];

// const points = [[4,6],[6,5],[3,1]];
console.log(largestTriangleArea(points));