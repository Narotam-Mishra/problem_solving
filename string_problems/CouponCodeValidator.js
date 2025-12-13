// Problem link - https://leetcode.com/problems/coupon-code-validator/?envType=daily-question&envId=2025-12-13

let validateCoupons = function (code, businessLine, isActive) {
  // helper function to validate coupon code
  const isValidCode = (code) => {
    if (!code || code.length === 0) return false;
    for (let ch of code) {
      if (!/[a-zA-Z0-9_]/.test(ch)) {
        return false;
      }
    }
    return true;
  };

  // priority mapping for business lines
  const mp = {
    restaurant: 3,
    grocery: 1,
    pharmacy: 2,
    electronics: 0,
  };

  // step 1 - validate each coupon code
  const res = [];
  for (let i = 0; i < code.length; i++) {
    if (
      isActive[i] &&
      isValidCode(code[i]) &&
      mp.hasOwnProperty(businessLine[i])
    ) {
      res.push([mp[businessLine[i]], code[i]]);
    }
  }

  // step 2 - sort based on priority
  res.sort((a, b) => {
    if (a[0] !== b[0]) return a[0] - b[0];

    // ASCII-based lexicographical comparison (like C++)
    if (a[1] < b[1]) return -1;
    if (a[1] > b[1]) return 1;
    return 0;
  });

  // step 3 - extract codes from sorted pairs
  const ans = [];
  for (let [_, c] of res) {
    ans.push(c);
  }

  // step 4 - return the result
  return ans;
};

const code = ["SAVE20", "", "PHARMA5", "SAVE@20"],
  businessLine = ["restaurant", "grocery", "pharmacy", "restaurant"],
  isActive = [true, true, true, true];

// const code = ["GROCERY15","ELECTRONICS_50","DISCOUNT10"], businessLine = ["grocery","electronics","invalid"], isActive = [false,true,true];
console.log(validateCoupons(code, businessLine, isActive));
