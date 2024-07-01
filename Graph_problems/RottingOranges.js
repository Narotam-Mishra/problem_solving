
// Problem link - https://leetcode.com/problems/rotting-oranges/

const neighbourArr = [[-1, 0], [0, -1], [1,0], [0,1]]

function bfs_traversal(grid){
    // using array as queue
    let qu = [];

    // find size of row and column of grid
    let m = grid.length;
    let n = grid[0].length;

    // iterate on grid
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(grid[i][j] === 2){
                // current ornage is rotten
                qu.push([[i, j], 0]);
                // adding all sources, at time, t=0 first orange will get rotten
            }
        }
    }

    let res = 0;
    // till the time queue is empty
    while(qu.length > 0){
        let curr = qu.shift();
        // get co-ordinates of the rotten orange
        let coords = curr[0];
        // time at which currrent orange is rotten
        let time = curr[1];

        // traverse neighbour of current rotten orange
        for(let ni=0; ni<4; ni++){
            let nx = coords[0] + neighbourArr[ni][0];
            let ny = coords[1] + neighbourArr[ni][1];

            // check boundary condition for grid
            if(nx < 0 || ny < 0 || nx >= m || ny >= n) continue;

            if(grid[nx][ny] === 1){
                // if it is fresh orange
                qu.push([[nx, ny], time+1]);
                // neighboring will be rotten at t = t+1
                res = Math.max(res, time+1);
                grid[nx][ny] = 2 ; // mark as rotten
            }
        }
    }

    // if any orange is left fresh then return -1
    for(let i=0; i<m; i++){
        for(let j=0; j<n; j++){
            if(grid[i][j] === 1) return -1;
        }
    }
    return res;
}

let orangesRotting = function(grid) {
    return bfs_traversal(grid);
};

// let grid = [[2,1,1],[1,1,0],[0,1,1]];

// let grid = [[2,1,1],[0,1,1],[1,0,1]];

let grid = [[0,2]];
console.log(orangesRotting(grid));