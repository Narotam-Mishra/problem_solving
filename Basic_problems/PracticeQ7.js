
// Predict Output - 15

const data = [1, "2", 3, "4", 5];

const result = data
  .map((item) => parseInt(item))
  .filter((item) => !isNaN(item))
  .reduce((acc, item) => acc + item, 0);

console.log(result);
