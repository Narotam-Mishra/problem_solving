
// Problem link - https://leetcode.com/problems/check-distances-between-same-letters/description/?envType=problem-list-v2&envId=string

let checkDistances = function(s, distance) {
    // step 1 - array to store the index of first occurrence of each character
    const firstIndexArr = new Array(26).fill(-1);

    // step 2 - iterate on each character of `s`
    for(let i=0; i<s.length; i++){
        // convert each character to corresponding number
        // 'a' --> 0, 'b' --> 1, .... 'z' --> 25
        let charCode = s.charCodeAt(i) - 97;

        // step 3 - if first time seeing this character then store its index
        if(firstIndexArr[charCode] === -1){
            firstIndexArr[charCode] = i;
        }else{
            // step 4 - if second time seeing this, calculate the distance
            let actualDistance = i - firstIndexArr[charCode] - 1;

            // step 5 - check actual distance with distance array
            if(actualDistance !== distance[charCode]){
                // if distance doesn't match, it's not well spaced string, return false
                return false;
            }
        }
    }

    // step 6 - all character matched the required distance, return true
    return true;
};

// const s = "abaccb", distance = [1,3,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];

const s = "aa", distance = [1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
console.log(checkDistances(s, distance));
