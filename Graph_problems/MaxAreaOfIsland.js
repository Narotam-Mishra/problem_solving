
// Problem link - https://leetcode.com/problems/max-area-of-island/

const neighbourArr = [[-1, 0], [0, -1], [1,0], [0,1]]

function bfs_traversal(i, j, grid){
    // using array as queue to perform BFS 
    let qu = [];

    // push the starting point (src) in queue
    qu.push([i, j]);

    // mark this source cell(i,j) as visited by using '-1'
    grid[i][j] = -1;

    // every connected component of a size atleast 1
    let sizeOfCC = 1;

    // till queue is not empty visted neighbour of current cell(i,j)
    while(qu.length > 0){
        let curr = qu.shift();
        // trverse nearest neighbour
        for(let n = 0; n < 4; n++){
            let newNeighbourX = curr[0] + neighbourArr[n][0]; 
            // n=0, i-1, n=1, i, n=2, i+1, n=3, i
            let newNeighbourY = curr[1] + neighbourArr[n][1];
            // n=0, j, n=1, j-1, n=2, j, n=3, j+1

            // check boundary condition
            if(newNeighbourX < 0 || newNeighbourY < 0 || newNeighbourX >= grid.length || newNeighbourY >= grid[0].length){
                // we are outside of grid, so we will continue
                continue;
            }
            if(grid[newNeighbourX][newNeighbourY] === 1){
                // its unvisited piece of land
                grid[newNeighbourX][newNeighbourY] = -1
                // we will mark it as visited
                qu.push([newNeighbourX, newNeighbourY]);
                // push new neighbour into queue

                //increment the size of connected component after each visit
                sizeOfCC++;
            }
        }
    }
    return sizeOfCC;
}


let maxAreaOfIsland = function(grid) {
    let numOfMaxCC = 0;
    for(let i=0; i<grid.length; i++){
        for(let j=0; j<grid[i].length; j++){
            if(grid[i][j] === 1){
                numOfMaxCC = Math.max(numOfMaxCC, bfs_traversal(i, j, grid));
            }
        }
    }
    return numOfMaxCC;
};

function main() {
  let grid = [
    [0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
    [0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
    [0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
  ];
  console.log("Maximum area of Island:", maxAreaOfIsland(grid));
}

main();