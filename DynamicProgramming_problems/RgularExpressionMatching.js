
// Problem link - https://leetcode.com/problems/regular-expression-matching/?envType=problem-list-v2&envId=string

let isMatch = function (s, p) {
  // step 1 - create dp array of boolean
  let dp = Array.from({ length: s.length + 1 }, () =>
    Array(p.length + 1).fill(false)
  );

  // step 2 - iterate on dp table and fill it required value
  let mr = dp.length - 1;
  let mc = dp[0].length - 1;

  for (let i = 0; i <= mr; i++) {
    for (let j = 0; j <= mc; j++) {
      if (i === 0 && j === 0) {
        dp[i][j] = true;
      } else if (j === 0) {
        dp[i][j] = false;
      } else if (i === 0) {
        let chp = p[j - 1];
        if (chp === "*") {
          dp[i][j] = dp[i][j - 2];
        } else {
          dp[i][j] = false;
        }
      } else {
        let chp = p[j - 1];
        let chs = s[i - 1];

        if (chp === "*") {
          dp[i][j] = dp[i][j - 2];

          let chpprev = p[j - 2];
          if (chpprev == "." || chpprev == chs) {
            dp[i][j] = dp[i][j] || dp[i - 1][j];
          }
        } else if (chp == ".") {
          dp[i][j] = dp[i - 1][j - 1];
        } else if (chp == chs) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = false;
        }
      }
    }
  }

  // step 3 - return final output
  return dp[mr][mc];
};

// const s = "aa", p = "a";

// const s = "aa", p = "a*";

const s = "ab", p = ".*";
console.log(isMatch(s, p));
