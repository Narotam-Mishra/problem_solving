
// Problem link - https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/description/?envType=problem-list-v2&envId=string

let closestTarget = function(words, target, startIndex) {
    // step 1 - initialize variable to find minimum distance `minDistance`
    let minDistance = Infinity;
    const n = words.length;

    // step 2 - iterate on each word of `words` array
    for(let i=0; i<n; i++){
        // if target is found
        if(words[i] === target){
            // step 3 - calculate forward distance
            let forwardDistance = (i - startIndex + n) % n;

            // step 4 - calculate backward distance
            let backwardDistance = (startIndex - i + n) % n;

            // step 5 - find minimum distance from forward and backward distance
            const distance = Math.min(forwardDistance, backwardDistance);
            
            // update minimum distance
            minDistance = Math.min(distance, minDistance);
        }
    }

    // step 6 - return minimum distance
    return minDistance === Infinity ? -1 : minDistance;
};

// const words = ["hello","i","am","leetcode","hello"], target = "hello", startIndex = 1;

// const words = ["a","b","leetcode"], target = "leetcode", startIndex = 0;

const words = ["i","eat","leetcode"], target = "ate", startIndex = 0;
console.log(closestTarget(words, target, startIndex));
