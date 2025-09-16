
// Problem link - https://leetcode.com/problems/replace-non-coprime-numbers-in-array/description/?envType=daily-question&envId=2025-09-16

let replaceNonCoprimes1 = function(nums) {
    // utility function to find GCD of two numbers
    function findGCD(a, b){
        while(b !== 0){
            let temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // utility function to find LCM of two numbers
    function findLCM(a, b){
        return (a * b) / findGCD(a, b);
    }

    // step 1 - create copy of input array `nums` in `res`
    let res = [...nums];

    // pointer to keep track of `res` numbers
    let i = 0;

    // step 2 - process the `res` array as per given steps
    while(i < res.length - 1){
        if(findGCD(res[i], res[i+1]) > 1){
            // step 3 - replace adjacent non-coprime numbers with their LCM
            let lcmVal = findLCM(res[i], res[i+1]);
            res.splice(i, 2, lcmVal);

            // step 4 - move back one position to check if new LCM
            // creates a non-coprime pair with the previous element
            if(i > 0){
                i--;
            }
        }else{
            // move to next position if current pair is co-prime
            i++;
        }
    }

    // step 5 - return final result `res`
    return res;
};

let replaceNonCoprimes = function(nums) {
    // utility function to find GCD of two numbers
    function findGCD(a, b){
        while(b !== 0){
            let temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // store final result in `res` 
    const res = [];

    // step 1 - process the array until no more adjacent non-coprime pairs exist
    for(let num of nums){
        // step 2 - keep merging the current number with the last element in result
        while(res.length > 0){
            let prevNum = res[res.length - 1];
            let currNum = num;

            // as long as they are non-coprime
            let gcdValue = findGCD(prevNum, currNum);
            if(gcdValue == 1){
                break;
            }

            let lcmValue = prevNum / gcdValue * currNum;

            // step 3 - replace num with LCM of last element and current num
            num = lcmValue;

            // step 4 - remove the last element
            res.pop();
        }

        // step 5 - add the (possibly merged) number to result `res`
        res.push(num);
    }

    // step 6 - return final result `res`
    return res;
};

const nums = [6,4,3,2,7,6,2];

// const nums = [2,2,1,1,3,3,3];
console.log(replaceNonCoprimes(nums));