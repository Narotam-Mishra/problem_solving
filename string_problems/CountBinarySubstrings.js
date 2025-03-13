
// Problem link - https://leetcode.com/problems/count-binary-substrings/description/?envType=problem-list-v2&envId=string

let countBinarySubstrings = function(s) {
    // step 1 - variable intialization
    let prevGroup = 0, currGroup = 1, count = 0;

    // step 2 - iterate on input string
    for(let i=1; i<s.length; i++){
        if(s[i] === s[i-1]){
            // extend current group if current and previous digits are equal
            currGroup++;
        }else{
            // otherwise count valid substring
            count += Math.min(currGroup, prevGroup);

            // move to new group
            prevGroup = currGroup;

            // reset counter for the new group
            currGroup = 1;
        }
    }

    // step 3 - count last valid substring
    return count + Math.min(currGroup, prevGroup);
};

// const s = "00110011";

const s = "10101";
console.log(countBinarySubstrings(s));
