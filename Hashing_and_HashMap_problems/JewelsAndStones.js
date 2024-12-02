
// Problem link : https://leetcode.com/problems/jewels-and-stones/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let numJewelsInStones1 = function(jewels, stones) {
    let frqMap = {};

    for(let i=0; i<stones.length; i++){
        if(frqMap[stones[i]]){
            frqMap[stones[i]]++;
        }else{
            frqMap[stones[i]] = 1;
        }
    }

    let count = 0;
    for(let i=0; i<jewels.length; i++){
        if(frqMap[jewels[i]]){
            count += frqMap[jewels[i]];
        }
    }

    return count;;
};

let numJewelsInStones = function(jewels, stones) {
    // convert jewels string to a Set for efficient lookup.
    let jewelsSet = new Set(jewels);
    
    // initialize a counter to track the number of jewels in stones.
    let count = 0;

    // loop through each character in stones.
    for(let s of stones){
        // check if the current stone is in the jewelSet.
        if(jewelsSet.has(s)){
            // increment the count if it is a jewel
            count++;
        }
    }

    // return the total count of jewels in stones.
    return count;
};

let jewels = "aA", stones = "aAAbbbb";

// let jewels = "z", stones = "ZZ";
console.log(numJewelsInStones(jewels, stones));
