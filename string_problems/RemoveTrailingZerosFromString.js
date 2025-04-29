
// Problem link - https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/?envType=problem-list-v2&envId=string

let removeTrailingZeros = function(num) {
    // step 1 - initialize counter to count trailing zeros in `num`
    let countZeros = 0;

    // step 2 - iterate on `num` from backward to find trailing zeros easily
    for(let i=num.length - 1; i >= 0; i--){
        // count trailing zeros
        if(num[i] === '0'){
            countZeros++
        }else{
            // for non zeros break the loop
            break;
        }
    }

    // step 3 - return substring of `num` after removing trailing zeros
    return num.substring(0, num.length - countZeros);
};

// const num = "51230100";

// const num = "123";

const num = "1720865079269529096765717822459";

console.log(removeTrailingZeros(num));
