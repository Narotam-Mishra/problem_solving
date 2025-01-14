
// Problem link : https://leetcode.com/problems/sort-the-people/description/?envType=problem-list-v2&envId=hash-table

let sortPeople1 = function(names, heights) {
    const pairs = names.map((name, index) => [name, heights[index]]);

    pairs.sort((a,b) => b[1] - a[1]);

    const res = [];
    for(let i=0; i<pairs.length; i++){
        res.push(pairs[i][0]);
    }
    
    return res;
};

let sortPeople = function(names, heights) {
    // step 1 - sort indices of the heights array based on the heights in descending order
    return heights
        // step 2 - map heights to their indices 
        .map((height, index) => index)
        // step 3 - sort indices by corresponding heights 
        .sort((a,b) => heights[b] - heights[a])
        // step 4 - map sorted indices to corresponding names
        .map((index) => names[index]);
};

// const names = ["Mary","John","Emma"], heights = [180,165,170];

const names = ["Alice","Bob","Bob"], heights = [155,185,150];
console.log(sortPeople(names, heights));
