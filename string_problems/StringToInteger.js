
// Problem link - https://leetcode.com/problems/string-to-integer-atoi/description/

let myAtoi = function(s) {
    // store integer max and min values
    const INT_MAX = 2 ** 31 - 1;
    const INT_MIN = - (2 ** 31);

    let i = 0;        // pointer to iterate on string `s`
    let sign = 1;     // keep track of sign `-` & `+`
    let res = 0;      // store resultant number in `res`
    let n = s.length; // get length of `s`

    // step 1 - skip whitespaces in `s`
    while(i < n && s[i] === ' '){
        i++;
    }

    // step 2 - handle optional `+` and `-`
    if(i < n && (s[i] === '-' || s[i] === '+')){
        sign = s[i] === '-' ? -1 : 1;
        i++;
    }

    // step 3 - convert numeric charcter into integer
    while(i < n && s[i] >= '0' && s[i] <= '9'){
        let digit = s[i].charCodeAt(0) - '0'.charCodeAt(0);

        // step 4 - check for overfolow / underflow befor multiplying by 10
        if (
          res > Math.floor(INT_MAX / 10) ||
          (res === Math.floor(INT_MAX / 10) && digit > INT_MAX % 10)
        ) {
          return sign === 1 ? INT_MAX : INT_MIN;
        }

        res = res * 10 + digit;

        // move to next numeric character
        i++;
    }

    // step 5 - return resultant number by applying sign
    return res * sign;
};

// const s = "42";

// const s = "-042";

// const s = "1337c0d3";

// const s = "0-1"

const s = "words and 987";
console.log(myAtoi(s));
