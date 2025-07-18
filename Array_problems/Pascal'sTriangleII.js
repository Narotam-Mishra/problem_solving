
// Problem link - https://leetcode.com/problems/pascals-triangle-ii/description/?envType=problem-list-v2&envId=array

let getRow = function(rowIndex) {
    // store result in `res`
    const res = [1];

    // edge case: if rowIndex is 0, return [1]
    if(rowIndex === 0){
        return res;
    }
    
    // step 1 - generate each row of Pascal's triangle
    // using formula - C(n,i) = C(n,i-1) * (n-i+1) / i
    // where `n` is rowIndex and `i` is the current position
    for(let i=1; i<=rowIndex; i++){
        // step 2 - calculate next element based on previous element
        const nextVal = res[i-1] * (rowIndex-i+1)/i;
        
        // store in result `res`
        res.push(nextVal);
    }

    // step 3 - return result `res`
    return res;
};

const rowIndex = 1;

// const rowIndex = 3;

// const rowIndex = 0;

// const rowIndex = 2;
console.log(getRow(rowIndex));