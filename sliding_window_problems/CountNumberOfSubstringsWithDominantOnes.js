
// Problem link - https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/?envType=daily-question&envId=2025-11-15

let numberOfSubstrings = function (s) {
  const n = s.length;

  // step 1 - find cummulative count of 1
  const cumOneCount = new Array(n).fill(0);
  cumOneCount[0] = s.charAt(0) == "1" ? 1 : 0;

  for (let i = 1; i < n; i++) {
    cumOneCount[i] = cumOneCount[i - 1] + (s.charAt(i) == "1" ? 1 : 0);
  }

  // step 2 - iterate on each substring
  let res = 0;
  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      // step 2 - find count of 1 & 0 at each substring
      let ones = cumOneCount[j] - (i - 1 >= 0 ? cumOneCount[i - 1] : 0);
      let zeros = j - i + 1 - ones;

      // case 1 - too many zeros - substring is not dominant
      // skip ahead to avoid checking invalid substrings
      if (zeros * zeros > ones) {
        let deficit = zeros * zeros - ones;
        j += deficit - 1;
      }
      // case 2 - exactly at the boundary - this substring is valid
      else if (zeros * zeros == ones) {
        res += 1;
      }
      // case 3 - dominant substring found - count all valid extensions
      else {
        // [i....j] is a valid dominant string
        res += 1;

        // step 3 - calculate how many positions we can extend to the right
        let k = Math.floor(Math.sqrt(ones)) - zeros;
        let nextJ = j + k;

        // step 4 - check if we can extend beyond the string, all remaining positions
        // are valid
        if (nextJ >= n) {
          res += n - j - 1;
          break;
        } else {
          // otherwise, count the valid extensions and skip ahead
          res += k;
        }

        j = nextJ;
      }
    }
  }

  // step 5 - return final result res
  return res;
};

// const s = "00011";

const s = "101101";
console.log(numberOfSubstrings(s));