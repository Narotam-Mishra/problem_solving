
// Problem link - https://leetcode.com/problems/calculate-money-in-leetcode-bank/description/?envType=daily-question&envId=2025-10-25

let totalMoney1 = function(n) {
    // store total amount of money in `total`
    let total = 0;

    // step 1 - iterate on each day
    for(let i = 0; i < n; i++){
        // step 2 - find number of week
        let w = Math.floor(i / 7);

        // step 3 - find number of day
        let d = i % 7;

        // step 4 - calculate total
        total += (w + d + 1);
    }

    // step 5 - return total amount of money
    return total;
};

let totalMoney = function (n) {
  // step 1 - calculate number of complete and remaining weeks
  let completeWeeks = Math.floor(n / 7);
  let remainingDays = n % 7;
  let total = 0;

  // step 2 - calculate money from complete weeks
  if (completeWeeks > 0) {
    // sum of arithmetic sequence: 7k + 21 for k from 1 to completeWeeks
    let weekSum =
      (7 * completeWeeks * (completeWeeks + 1)) / 2 + 21 * completeWeeks;
    total += weekSum;
  }

  // step 3 - calculate money from remaining days in the incomplete week
  if (remainingDays > 0) {
    // Monday of the incomplete week
    let startVal = completeWeeks + 1;

    // sum = number_of_terms * (first_term + last_term) / 2
    let remainingSum =
      (remainingDays * (startVal + startVal + remainingDays - 1)) / 2;

    total += remainingSum;
  }

  // step 4 - return the total amount of money at nth day
  return total;
};

// const n = 4;

// const n = 10;

const n = 20;
console.log(totalMoney(n));