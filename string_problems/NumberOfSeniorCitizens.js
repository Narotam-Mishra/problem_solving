
// Problem link - https://leetcode.com/problems/number-of-senior-citizens/description/?envType=problem-list-v2&envId=string

let countSeniors = function(details) {
    // step 1 - intialize counter
    let count = 0;

    // step 2 - iterate on each details
    for(let data of details){
        // step 3 - check if age is greater than 60
        if(data.substring(11, 13) > 60){
            // then increment the counter
            count++;
        }
    }

    // step 4 - return count
    return count;
};

const details = ["7868190130M7522","5303914400F9211","9273338290F4010"];

// const details = ["1313579440F2036","2921522980M5644"];
console.log(countSeniors(details));
