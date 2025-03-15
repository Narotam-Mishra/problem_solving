
// Problem link - https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/description/?envType=problem-list-v2&envId=string

let freqAlphabets = function (s) {
  // step 1 - start form last character of `s`
  let i = s.length - 1;
  let res = [];

  // step 2 - iterate `s` from reverse
  while (i >= 0) {
    if (s[i] === "#") {
      // step 3 - decode two digits number (10# to 26#)
      let num = parseInt(s.substring(i, i - 2));
      res.push(String.fromCharCode(96 + num));
      i -= 3;
    } else {
      // step 4 - decode single-digit number (1 to 9)
      let num = parseInt(s[i]);
      res.push(String.fromCharCode(96 + num));
      i--;
    }
  }

  // step 5 - reverse the `res` to get correct order and return it
  return res.reverse().join("");
};

// const s = "10#11#12";

const s = "1326#";
console.log(freqAlphabets(s));
