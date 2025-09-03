
// Problem link - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/?envType=daily-question&envId=2025-09-03

let numberOfPairs = function(points) {
    // find size of points
    const n = points.length;

    // store count of valid points
    let count = 0;

    // step 1 - sort x-points in ascending and y-points in descending order
    // optimization - this helps us process potential upper-left points first
    const sortedPoints = points.map((point) => ({
        x : point[0],
        y : point[1],
    })).sort((a,b) => {
        // ascending order for x-points
        if(a.x !== b.x) return a.x - b.x;

        // descending order for y-points
        return b.y - a.y;
    });

    // step 2 - now iterate over possible x and y co-ordinates
    for(let i=0; i<n; i++){
        for(let j=i+1; j<n; j++){
            
            // extract co-ordinate points from sorted points
            const A = sortedPoints[i];
            const B = sortedPoints[j];

            // step 3 - check A.y >= B.y (A is on upper left of B)
            // no need to check x point as it sorted i.e A.x <= B.x
            if(A.y >= B.y){
                // step 4 - check second condition : there is no points inside rectangle
                let hasPointsInside = false;

                // step 5 - only check points between i & j
                // since points are sorted, points after j can't be in rectangle
                for(let k=i+1; k<j && !hasPointsInside; k++){
                
                    // extract co-ordinate points
                    const point = sortedPoints[k];

                    // early termination - if point.x > B.x
                    if(point.x > B.x) break;
                    
                    // check if this point lies inside rectangle or not
                    if(point.x >= A.x && point.y >= B.y && point.y <= A.y){
                        hasPointsInside = true;
                        break;
                    }
                }

                // step 6 - if no points lies inside rectangle 
                if(!hasPointsInside){
                    // this is valid pair, so increment count
                    count++;
                }
            }
        }
    }

    // step  7- return valid count
    return count;
};

// const points = [[1,1],[2,2],[3,3]];

// const points = [[6,2],[4,4],[2,6]];

const points = [[3,1],[1,3],[1,1]];
console.log(numberOfPairs(points));