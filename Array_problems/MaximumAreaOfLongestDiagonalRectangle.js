
// Problem link - https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/description/?envType=daily-question&envId=2025-08-26

let areaOfMaxDiagonal = function(dimensions) {
    // keep track of maximum area and maximum diagonal in `maxArea` and maxDiagonal
    let maxArea = 0, maxDiagonal = 0;

    // step 1 - iterate on each recgangle's dimension
    for(let dimension of dimensions){
        // step 2 - extract length and breadth
        let [l, b] = dimension;
        
        // step 3 - calculate digonal
        let currDiagonal = Math.sqrt(l*l + b*b);

        // step 4 - find area of current rectangle's dimesion
        area = l * b;
        
        // step 5 - compare current diagonal with maximum diagonal found so far
        if(currDiagonal > maxDiagonal){
            // case 1 - found rectangle with longer diagonal
            // update maximum area and maximum Diagonal in this case
            maxDiagonal = currDiagonal;
            maxArea = area;

        }else if (currDiagonal === maxDiagonal){
            // case 2 - found a rectangle with same diagonal length as current maximum
            // keep the maximum area among all
            maxArea = Math.max(area, maxArea);
        }
    }

    // step 6 - return maximum area of longest diagonal
    return maxArea;
};

// const dimensions = [[9,3],[8,6]];

// const dimensions = [[3,4],[4,3]];

const dimensions = [[2,6],[5,1],[3,10],[8,4]];
console.log(areaOfMaxDiagonal(dimensions));