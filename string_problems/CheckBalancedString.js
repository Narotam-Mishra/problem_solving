
// Problem link - https://leetcode.com/problems/check-balanced-string/description/?envType=problem-list-v2&envId=string

let isBalanced = function(num) {
    // step 1 - initialize variables to store even and odd indices sum
    let oddSum = evenSum = 0;

    // step 2 - iterate on `num`
    for(let i=0; i<num.length; i++){
        // use 1-based indexing
        let index = i+1;
        // check for even index
        if(index % 2 === 0){
            // step 3 - find even index sum
            evenSum += +num[i];
        }else{
            // step 4 - find odd index sum
            oddSum += +num[i];
        }
    }

    // step 5 - if even index sum equals to odd index sum then return true otherwise false
    return evenSum === oddSum;
};

const num = "1234";

// const num = "24123";
console.log(isBalanced(num));
