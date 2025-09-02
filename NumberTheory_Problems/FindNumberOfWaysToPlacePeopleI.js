
// Problem link - https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/description/?envType=daily-question&envId=2025-09-02

// using Brute Force Approach
let numberOfPairs = function(points) {
    const n = points.length;

    // store count of valid points
    let count = 0;

    // step 1 - try every pair of points
    for(let i=0; i<n; i++){
        for(let j=0; j<n; j++){
            // skip same points
            if(i === j) continue;

            // extract co-ordinate points
            const A = points[i];
            const B = points[j];

            // step 2 - check first condition : if A is on upper left of B
            // A is on upper left if A.x <= B.x and A.y >= b.y
            if(A[0] <= B[0] && A[1] >= B[1]){
                // step 3 - check second condition : there is no points inside rectangle
                let hasPointsInside = false;

                // check every other possible points to see if it lies in the rectangle
                for(let k=0; k<n; k++){
                    // skip same points
                    if(k === i || k === j) continue;

                    // extract co-ordinate points
                    const point = points[k];
                    const x = point[0];
                    const y = point[1];

                    // check if this point lies inside rectangle or not
                    if(x >= A[0] && x <= B[0] && y >= B[1] && y <= A[1]){
                        hasPointsInside = true;
                        break;
                    }
                }

                // step 4 - if no points lies inside rectangle 
                if(!hasPointsInside){
                    // this is valid pair, so increment count
                    count++;
                }
            }
        }
    }

    // step 5 - return valid count
    return count;
};

// const points = [[1,1],[2,2],[3,3]];

// const points = [[6,2],[4,4],[2,6]];

const points = [[3,1],[1,3],[1,1]];
console.log(numberOfPairs(points));