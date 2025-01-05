
// Problem link : https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=problem-list-v2&envId=hash-table

let arrayRankTransform = function(arr) {
    // step 1 - pair elements with their original indices
    const pair = arr.map((value, index) => [value, index]);

    // step 2 - sort the array by value
    pair.sort((a,b) => a[0] - b[0]);

    // step 3 - assign ranks
    const ranks = new Array(arr.length);
    // start rank from 1
    let rank = 1;

    for (let i = 0; i < pair.length; i++) {
      // if the current value is not equal to the previous value,
      if (i > 0 && pair[i][0] !== pair[i - 1][0]) {
        // incremnt the rank
        rank++;
      }
      // otherwise assign the same rank
      ranks[pair[i][1]] = rank;
    }

    // step 4 - return ranks
    return ranks;
};

// const arr = [37,12,28,9,100,56,80,5,12];

// const arr = [100, 100, 100];

const arr = [40,10,20,30];
console.log(arrayRankTransform(arr));
