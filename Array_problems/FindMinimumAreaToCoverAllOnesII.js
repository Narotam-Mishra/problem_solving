
// Problem link - https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii/?envType=daily-question&envId=2025-08-23

/**
 * Utility function to rotate grid 90 degrees clockwise
 * Transformation: (i,j) -> (j, m-1-i)
 */
function rotateGrid(grid) {
    const m = grid.length;        // original rows
    const n = grid[0].length;     // original columns

    // After 90° clockwise rotation: new_rows = original_cols, new_cols = original_rows
    const rotatedGrid = Array(n).fill(null).map(() => Array(m).fill(0));

    // Apply rotation transformation
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            rotatedGrid[j][m - 1 - i] = grid[i][j];
        }
    }

    return rotatedGrid;
}

/**
 * Utility function to calculate minimum bounding rectangle area within a specific region
 * @param {number} sr start row (inclusive)
 * @param {number} er end row (exclusive)
 * @param {number} sc start column (inclusive)
 * @param {number} ec end column (exclusive)
 * @param {number[][]} grid the 2D grid
 */
function getMinimumRectangularAreaFromGrid(sr, er, sc, ec, grid) {
    const m = grid.length;
    const n = grid[0].length;

    // Initialize bounds to invalid values to detect if any 1's exist
    let minRow = m, maxRow = -1;
    let minCol = n, maxCol = -1;

    // Scan the specified region to find bounding box of all 1's
    for (let i = sr; i < er; i++) {
        for (let j = sc; j < ec; j++) {
            if (grid[i][j] === 1) {
                minRow = Math.min(minRow, i);
                maxRow = Math.max(maxRow, i);
                minCol = Math.min(minCol, j);
                maxCol = Math.max(maxCol, j);
            }
        }
    }

    // If no 1's found in this region, return 0 (shouldn't happen in valid partitions)
    if (maxRow === -1) return 0;

    // Calculate area of minimum bounding rectangle
    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
}

function minimumSumHelper(grid) {
    const m = grid.length;        // number of rows
    const n = grid[0].length;     // number of columns

    let ans = Number.MAX_SAFE_INTEGER; // store minimum possible sum

    /**
     * CASE 1 & 2: Mixed horizontal-vertical splits
     * 
     * Case 1: ⊥ shape        Case 2: ⊤ shape
     * +-------+-------+      +-------+-------+
     * |   TOP PART    |      |  TL   |   TR  |
     * +-------+-------+      +-------+-------+
     * |  BL   |   BR  |      |   BOTTOM      |
     * +-------+-------+      +-------+-------+
     */
    
    for (let rowSplit = 1; rowSplit < m; rowSplit++) {      // Try all horizontal cut positions
        for (let colSplit = 1; colSplit < n; colSplit++) {  // Try all vertical cut positions
            
            // Case 1: Top full-width, bottom split vertically (⊥ shape)
            const topPart = getMinimumRectangularAreaFromGrid(0, rowSplit, 0, n, grid);
            const bottomLeft = getMinimumRectangularAreaFromGrid(rowSplit, m, 0, colSplit, grid);
            const bottomRight = getMinimumRectangularAreaFromGrid(rowSplit, m, colSplit, n, grid);
            ans = Math.min(ans, topPart + bottomLeft + bottomRight);

            // Case 2: Top split vertically, bottom full-width (⊤ shape)
            const topLeft = getMinimumRectangularAreaFromGrid(0, rowSplit, 0, colSplit, grid);
            const topRight = getMinimumRectangularAreaFromGrid(0, rowSplit, colSplit, n, grid);
            const bottomPart = getMinimumRectangularAreaFromGrid(rowSplit, m, 0, n, grid);
            ans = Math.min(ans, topLeft + topRight + bottomPart);
        }
    }

    /**
     * CASE 3: Three horizontal strips (≡ shape)
     * 
     * +---------------+
     * |   TOP PART    |
     * +---------------+
     * |  MIDDLE PART  |
     * +---------------+
     * |  BOTTOM PART  |
     * +---------------+
     */
    
    for (let s1 = 1; s1 < m; s1++) {            // First horizontal cut position
        for (let s2 = s1 + 1; s2 < m; s2++) {   // Second horizontal cut position
            
            const topPart = getMinimumRectangularAreaFromGrid(0, s1, 0, n, grid);      // Rows [0, s1)
            const middlePart = getMinimumRectangularAreaFromGrid(s1, s2, 0, n, grid);  // Rows [s1, s2)
            const bottomPart = getMinimumRectangularAreaFromGrid(s2, m, 0, n, grid);   // Rows [s2, m)

            ans = Math.min(ans, topPart + middlePart + bottomPart);
        }
    }

    return ans;
}

let minimumSum = function(grid) {
    // step 1 - try the original orientation
    // case 1: top full-width, bottom split vertically (⊥ shape)
    // case 2: top split vertically, bottom full-width (⊤ shape)
    // case 3 - Three horizontal strips (≡ shape)
    let res = minimumSumHelper(grid);

    // step 2 - rotate grid 90° clockwise and try again
    // this handles Case 4: Three vertical strips (|||)
    // after rotation, vertical strips become horizontal strips
    const rotatedGrid = rotateGrid(grid);

    // step 3 - calculate minimum area of rotated grid
    res = Math.min(res, minimumSumHelper(rotatedGrid));

    // step 4 - return minimum possible sum of the area of these rectangles
    return res;
};

// const grid = [[1,0,1],[1,1,1]];

const grid = [[1,0,1,0],[0,1,0,1]];
console.log(minimumSum(grid));