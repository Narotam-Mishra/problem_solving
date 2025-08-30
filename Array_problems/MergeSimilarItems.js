
// Problem link - https://leetcode.com/problems/merge-similar-items/description/

let mergeSimilarItems = function(items1, items2) {
    // step 1 - use map to store value --> total weight mapping
    const valueWeightMap = new Map();

    // utility method to process each items
    const processItems = (items) => {
        for(const [value, weight] of items){
            // if value already exist map it to existing weight
            // otherwise add new entry
            valueWeightMap.set(value, (valueWeightMap.get(value) || 0) + weight);
        }
    }
    
    // step 2 - process each item
    processItems(items1);
    processItems(items2);

    // step 3 - convert map entries to array format and sort it by value
    // store result to `ret`
    const ret = Array.from(valueWeightMap.entries())
      .map(([value, totalWeight]) => [value, totalWeight])
      .sort((a, b) => a[0] - b[0]);
    
    // step 4 - return `ret`
    return ret;
};

// const items1 = [[1,1],[4,5],[3,8]], items2 = [[3,1],[1,5]];

// const items1 = [[1,1],[3,2],[2,3]], items2 = [[2,1],[3,2],[1,3]];

const items1 = [[1,3],[2,2]], items2 = [[7,1],[2,2],[1,4]];
console.log(mergeSimilarItems(items1, items2));