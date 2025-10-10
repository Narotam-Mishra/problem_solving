
// Problem link - https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/?envType=daily-question&envId=2025-10-10

let maximumEnergy = function (energy, k) {
  // get size of energy list
  const n = energy.length;

  // assume maximum energy is minimum value initially
  let maxEnergy = -Infinity;

  // step 1 - iterate backwards from the last magician to the first
  // this allows us to build optimal paths by reusing previously calculated results
  for (let i = n - 1; i >= 0; i--) {
    // step 2 - if there's a next magician at position (i + k), add their accumulated energy
    if (i + k < n) {
      energy[i] += energy[i + k];
    }

    // if (i + k >= n), magician at 'i' is already at the end of a path chain
    // So energy[i] remains as is (the final stop)

    // step 3 - update maximum energy so far
    // energy[i] now contains the total energy from starting at position 'i'
    maxEnergy = Math.max(maxEnergy, energy[i]);
  }

  // step 4 - return maximum energy
  return maxEnergy;
};

// const energy = [5,2,-10,-5,1], k = 3;

const energy = [-2,-3,-1], k = 2;
console.log(maximumEnergy(energy, k));