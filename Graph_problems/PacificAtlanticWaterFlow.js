
// Problem link - https://leetcode.com/problems/pacific-atlantic-water-flow/description/?envType=daily-question&envId=2025-10-05

/**
 * Check if coordinates are within grid boundaries
 */
function isValid(x, y, r, c) {
    return x >= 0 && y >= 0 && x < r && y < c;
}

/**
 * DFS to mark all cells reachable from ocean borders
 * We traverse uphill (>=) because we're going backwards from ocean to inland
 * In reality, water flows DOWN from these cells to the ocean
 */
function dfs(x, y, heights, visited, r, c) {
    // Four directions: up, down, left, right
    const directions = [[-1, 0], [1, 0], [0, -1], [0, 1]];
    
    // Mark this cell as reachable from the ocean we started from
    visited[x][y] = true;
    
    // Explore all four neighboring cells
    for(let dir of directions) {
        const newX = x + dir[0];
        const newY = y + dir[1];
        
        // main condition: heights[newX][newY] >= heights[x][y]
        // we're going BACKWARDS from ocean to inland
        // water flows DOWN in reality, but we're searching UP from ocean
        // it means: "Can we climb UP from current cell to neighbor?"
        // if yes, then water can flow DOWN from neighbor to current cell to ocean
        if(isValid(newX, newY, r, c) && 
           !visited[newX][newY] && 
           heights[newX][newY] >= heights[x][y]) {  // climb uphill or stay level
            dfs(newX, newY, heights, visited, r, c);
        }
    }
}

let pacificAtlantic = function(heights) {
    // find row and column size of height grid
    const r = heights.length;
    const c = heights[0].length;
    
    // track which cells can reach Pacific Ocean
    const pacificVisited = Array.from({length: r}, () => Array(c).fill(false));

    // track which cells can reach Atlantic Ocean
    const atlanticVisited = Array.from({length: r}, () => Array(c).fill(false));
    
    // step 1 - start DFS from all Pacific Ocean border cells (left and top edges)
    // and Atlantic Ocean border cells (right and bottom edges)
    for(let i = 0; i < r; i++) {
        // left edge (Pacific)
        dfs(i, 0, heights, pacificVisited, r, c);  
        
        // right edge (Atlantic)
        dfs(i, c - 1, heights, atlanticVisited, r, c);   
    }
    
    for(let j = 0; j < c; j++) {
        // top edge (Pacific)
        dfs(0, j, heights, pacificVisited, r, c);
        
        // bottom edge (Atlantic)
        dfs(r - 1, j, heights, atlanticVisited, r, c);   
    }
    
    // step 2 - find cells that can reach both oceans
    const res = [];
    for(let i = 0; i < r; i++) {
        for(let j = 0; j < c; j++) {
            // step 3 - if reachable from both Pacific and Atlantic
            if(pacificVisited[i][j] && atlanticVisited[i][j]) {
                // step 4 - add its co-ordinates to result `res` list
                res.push([i, j]);
            }
        }
    }
    
    // step 5 - return result `res` list
    return res;
};

// const heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]];

const heights = [[1]];
console.log(pacificAtlantic(heights));