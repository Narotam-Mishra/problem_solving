
// Problem link - https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/description/?envType=problem-list-v2&envId=array

let maxWidthOfVerticalArea = function(points) {
    // step 1 - extract and sort x-coordinates
    // we only care about x-coordinates since we're looking for vertical gaps
    const xPoints = points.map((point) => point[0]).sort((a,b) => a - b);

    // step 2 - find the maximum gap between consecutive x-coordinates
    let maxWidth = 0;
    for(let i=1; i<xPoints.length; i++){
        let currentWidth = xPoints[i] - xPoints[i-1];
        
        // step 3 - update maximum width
        maxWidth = Math.max(maxWidth, currentWidth);
    }

    // step 4 - return maximum widest vertical area
    return maxWidth;
};

// const points = [[8,7],[9,9],[7,4],[9,7]];

const points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]];
console.log(maxWidthOfVerticalArea(points));