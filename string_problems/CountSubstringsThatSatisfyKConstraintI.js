
// Problem link - https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/?envType=problem-list-v2&envId=string

let countKConstraintSubstrings = function(s, k) {
    // step 1 - initialize count to count number of substring that satisfy k-constraint
    let count = 0;

    // step 2 - iterate on input string `s`
    for(let i=0; i<s.length; i++){
        let zeroCount = 0, oneCount = 0;

        // step 3 - iterate on each substring
        for(let j=i; j<s.length; j++){
            // update 0's and 1's count
            if(s[j] === '0') zeroCount++
            else oneCount++
            
            // step 4 - check k-constraint
            if(zeroCount <= k || oneCount <= k){
                count++
            }else{
                // no need to check further
                break;
            }
        }
    }

    // step 5 - return count
    return count;
};

// const s = "10101", k = 1;

// const s = "1010101", k = 2;

const s = "11111", k = 1;
console.log(countKConstraintSubstrings(s, k));
