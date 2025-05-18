
// Problem link - https://leetcode.com/problems/valid-number/description/

let isNumber = function(s) {
    // step 1 - trim any leading or trailing whitspaces from string `s`
    s = s.trim();

    // step 2 - determine regular expression to match valid number format
    const validNumberRegEx = /^[\+\-]?((\d+\.\d*)|(\.\d+)|(\d+))([eE][\+\-]?\d+)?$/;

    // step 3 - test if string matches valid number regular expression
    return validNumberRegEx.test(s);
};

// const s = "0";

// const s = "e";

// const s = ".";

// const s = "-0.1";

// const s = "+6e-1";

// const s = "53.5e93";

// const s = "-+3";

// const s = "99e2"

// const s = "99e2.";

// const s = "1e";

// const s = "e3";

// const s = "--6";

// const s = "95a54e53";

// const s = "2e10";

// const s = "-.9";

const s = "-90E3";
console.log(isNumber(s));
