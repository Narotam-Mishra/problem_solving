
// Problem link - https://leetcode.com/problems/check-if-it-is-a-straight-line/description/?envType=problem-list-v2&envId=array

// For three points to be collinear, the slope between points 1-2 should equal the slope between points 2-3:
// (y2 - y1) / (x2 - x1) = (y3 - y2) / (x3 - x2)

let checkStraightLine = function(coordinates) {
    const n = coordinates.length;
    
    // base case : if there're only 2 points, return true.
    if(n <= 2){
        return true;
    }
    
    // step 1 - check every consecutive triplet of points
    for(let i=0; i<n-2; i++){
        // extract co-ordinates
        const [x1, y1] = coordinates[i];
        const [x2, y2] = coordinates[i+1];
        const [x3, y3] = coordinates[i+2];

        // step 2 - cross multiplication check for collinearity
        if((y2 - y1) * (x3 - x2) !== (y3 - y2) * (x2 - x1)){
            return false;
        } 
    }

    // step 3 - return true as all points are collinear that forms straight line
    return true;
};

// const coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]];

const coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]];
console.log(checkStraightLine(coordinates));