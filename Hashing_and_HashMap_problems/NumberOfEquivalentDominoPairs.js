
// Problem link : https://leetcode.com/problems/number-of-equivalent-domino-pairs/?envType=problem-list-v2&envId=hash-table

let numEquivDominoPairs = function(dominoes) {
    // step 1 - map to store frequency of normalized dominoes
    const normalizedMap = new Map();

    for(const [a, b] of dominoes){
        // normalize the domino
        const key = `${Math.min(a,b)} ${Math.max(a,b)}`
        
        // set the key pair count in map
        normalizedMap.set(key, (normalizedMap.get(key) || 0) + 1);
    }

    // step 2 - calculate the number of pairs
    // stores the total number of valid pairs
    let pairs = 0;
    for(const count of normalizedMap.values()){
        if(count >= 2){
            // calculate pairs
            pairs += (count * (count - 1)) / 2;
        }
    }

    // step 3 - return number of valid pairs
    return pairs;
};

// const dominoes = [[1,2],[2,1],[3,4],[5,6]];

const dominoes = [[1,2],[1,2],[1,1],[1,2],[2,2]]
console.log(numEquivDominoPairs(dominoes));
