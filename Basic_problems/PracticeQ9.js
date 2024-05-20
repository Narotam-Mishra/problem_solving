
// Predict out of the below code

// Output - 18

const nums = [1, 2, 3, 4, 5, 6];

const ans = nums
  .map((num) => num * 2)
  .filter((num) => num % 3 === 0)
  .reduce((acc, num) => acc + num, 0);

console.log(ans);