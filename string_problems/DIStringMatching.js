
// Problem link - https://leetcode.com/problems/di-string-match/description/?envType=problem-list-v2&envId=string

let diStringMatch = function(s) {
    // step 1 - intialize all necessary variables and store result into `res`
    let n = s.length;
    let low = 0;
    let high = n;
    const res = []

    // step 2 - iterate on `s`
    for(let i=0; i<n; i++){
        if(s[i] === 'I'){
            // step 3 - if 'I', assign the lowest number and increment low
            res.push(low);
            low++;
        }else{
            // step 4 - if 'D', assign the highest number and decrement high
            res.push(high);
            high--;
        }
    }

    // step 5 - after the loop, one number (low === high) remains to be added
    res.push(low);

    // step 6 - return `res`
    return res;
};

// const s = "IDID";

// const s = "III";

const s = "DDI";
console.log(diStringMatch(s));
