
// Problem link - https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/description/?envType=problem-list-v2&envId=string

let getSmallestString = function(s) {
    // step 1 - convert string `s` to character array for easy iteration
    const digits = s.split('');
    const n = digits.length;

    // step 2 - utility function check if two digits have same parity
    const haveSameParity = (a, b) => {
        return (parseInt(a) % 2)  === (parseInt(b) % 2);
    }

    // step 3 - scan each digit from left to right
    for(let i=0; i<n; i++){
        // get current and next digit
        let curr = digits[i];
        let next = digits[i+1];

        // step 4 - check if adjacent digits have same parity AND swapping would make string smaller
        if(haveSameParity(curr, next) && curr > next){
            // step 5 - perform swapping as above conditions satisfied
            [digits[i], digits[i+1]] = [digits[i+1], digits[i]];

            // step 6 - return immediately after first swap (at most one swap allowed)
            return digits.join('');
        }
    }

    // step 7 - otherwise return original string `s`
    return s;
};

// const s = "45320";

const s = "001";
console.log(getSmallestString(s));
