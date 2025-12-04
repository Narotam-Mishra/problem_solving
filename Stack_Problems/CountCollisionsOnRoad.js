// Problem link - https://leetcode.com/problems/count-collisions-on-a-road/description/?envType=daily-question&envId=2025-12-04

let countCollisions = function (directions) {
  const n = directions.length;

  // step 1 - define left & right boundary
  let i = 0;
  while (i < n && directions.charAt(i) == "L") {
    i++;
  }

  // right boundary
  let j = n - 1;
  while (j >= 0 && directions.charAt(j) == "R") {
    j--;
  }

  // step 2 - count collisions
  let collisons = 0;
  while (i <= j) {
    if (directions.charAt(i) != "S") {
      collisons++;
    }
    i++;
  }

  // step 3 - return number of collisons
  return collisons;
};

// const directions = "RLRSLL";

const directions = "LLRR";
console.log(countCollisions(directions));
