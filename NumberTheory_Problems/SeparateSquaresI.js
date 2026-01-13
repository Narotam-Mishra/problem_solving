
// Problem link - https://leetcode.com/problems/separate-squares-i/description/?envType=daily-question&envId=2026-01-13

function isBottomAreaEqualsTopArea(squares, mid_y, totalArea) {
    let bottomArea = 0.0;
    
    for (const square of squares) {
        const y = square[1];
        const len = square[2];
        
        const bottom_y = y;
        const top_y = y + len;
        
        if (mid_y >= top_y) {
            // full square below
            bottomArea += (len * len);
        } else if (mid_y > bottom_y) {
            // partial area below
            bottomArea += (mid_y - bottom_y) * len;
        }
    }
    
    // check if bottom area equals or exceeds half
    return bottomArea >= totalArea / 2.0;
}

let separateSquares = function(squares) {
    let s = Number.MAX_VALUE;
    let e = Number.MIN_VALUE;
    
    let total = 0.0;
    
    // step 1 - calculate total area and find range
    for (const square of squares) {
        const y = square[1];
        const len = square[2];
        
        total += (len * len);
        
        s = Math.min(s, y);
        e = Math.max(e, y + len);
    }
    
    // step 2 - using Binary search
    while (e - s > 1e-6) {
        const mid_y = s + (e - s) / 2;
        
        // step 3 - 
        if (isBottomAreaEqualsTopArea(squares, mid_y, total)) {
            e = mid_y;
        } else {
            s = mid_y;
        }
    }

    // step 4 - return final result
    return (s + e) / 2.0;
}

// const squares = [[0,0,1],[2,2,1]];

const squares = [[0,0,2],[1,1,1]];
console.log(separateSquares(squares));