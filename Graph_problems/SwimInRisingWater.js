
// Problem link - https://leetcode.com/problems/swim-in-rising-water/?envType=daily-question&envId=2025-10-06

let swimInWater = function(grid) {
    // direction grid to traverse in all four directions (down, up, right, left)
    const directions = [[1,0], [-1,0], [0,1], [0,-1]];
    
    // get the size of the grid
    const n = grid.length;
    
    // DFS function to check if we can reach destination with water level t
    const isPossibleToReach = (i, j, t, visited) => {
        // base cases: out of bounds, already visited, or elevation too high for current water level
        if (i < 0 || i >= n || j < 0 || j >= n || visited[i][j] || grid[i][j] > t) {
            return false;
        }
        
        // mark current cell as visited
        visited[i][j] = true;
        
        // check if we reached the destination (bottom-right corner)
        if (i === n - 1 && j === n - 1) {
            return true;
        }
        
        // explore all four directions
        for (const [dx, dy] of directions) {
            const newRow = i + dx;
            const newCol = j + dy;
            
            // recursively check if we can reach destination from new position
            if (isPossibleToReach(newRow, newCol, t, visited)) {
                return true;
            }
        }
        
        // cannot reach destination from this path
        return false;
    };
    
    // using binary search bounds:
    // minimum possible time is the starting cell elevation
    // maximum possible time is n*n-1 (worst case if all cells have unique values 0 to n*n-1)
    let start = grid[0][0];
    let end = n * n - 1;
    
    // variable to store the result (minimum time)
    let res = 0;
    
    // perform binary search on the water level
    while (start <= end) {
        // calculate mid point to test as potential water level
        const mid = start + Math.floor((end - start) / 2);
        
        // create a fresh visited array for each binary search iteration
        const visited = Array.from({ length: n }, () => Array(n).fill(false));
        
        // check if we can reach destination with water level = mid
        if (isPossibleToReach(0, 0, mid, visited)) {
            // if reachable, try to find a smaller water level
            res = mid;
            end = mid - 1;
        } else {
            // if not reachable, we need higher water level
            start = mid + 1;
        }
    }

    // return final result `res`
    return res;
};

// const grid = [[0,2],[1,3]];

const grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]];
console.log(swimInWater(grid));