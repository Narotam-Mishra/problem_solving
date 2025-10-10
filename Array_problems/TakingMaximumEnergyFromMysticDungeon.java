
// Problem link - https://leetcode.com/problems/taking-maximum-energy-from-the-mystic-dungeon/?envType=daily-question&envId=2025-10-10

package Array_problems;

public class TakingMaximumEnergyFromMysticDungeon {
    public static int maximumEnergy1(int[] energy, int k) {
        // get size of energy list
        int n = energy.length;

        // assume maximum energy is minimum value initially
        int maxEnergy = Integer.MIN_VALUE;

        // step 1 - iterate on each energy value
        for(int i=0; i<n; i++){
            // initialize current energy as 0
            int currEnergy = 0;

            // step 2 - take `i+k` jumps and abosrb each energy possible
            for(int j=i; j<n; j+=k){
                // step 3 - calculate current energy 
                currEnergy += energy[j];
            }

            // step 4 - update maximum energy
            maxEnergy = Math.max(maxEnergy, currEnergy);
        }

        // step 5 - return maximum energy
        return maxEnergy;
    }

    public static int maximumEnergy2(int[] energy, int k) {
        // get size of energy list
        int n = energy.length;

        // precompute `i+k` value in `temp` array
        int[] temp = new int[n];

        // assume maximum energy is minimum value initially
        int maxEnergy = Integer.MIN_VALUE;

        // step 1 - iterate on each energy value from backward
        for(int i=n-1; i>=0; i--){
            if(i+k < n){
                // step 2 -precompute `i+k` value
                temp[i] = energy[i] + temp[i+k];
            }else{
                temp[i] = energy[i];
            }
        }

        // step 3 - find maximum energy from temp
        for(int i=0; i<n; i++){
            maxEnergy = Math.max(maxEnergy, temp[i]);
        }

        // step 4 - return maximum energy
        return maxEnergy;
    }

    public static int maximumEnergy(int[] energy, int k) {
        // get size of energy list
        int n = energy.length;

        // assume maximum energy is minimum value initially
        int maxEnergy = Integer.MIN_VALUE;

        // step 1 - iterate backwards from the last magician to the first
        // this allows us to build optimal paths by reusing previously calculated results
        for(int i=n-1; i>=0; i--){
            // step 2 - if there's a next magician at position (i + k), add their accumulated energy
            if(i + k < n){
                energy[i] += energy[i+k];
            }

            // if (i + k >= n), magician at 'i' is already at the end of a path chain
            // So energy[i] remains as is (the final stop)

            // step 3 - update maximum energy so far
            // energy[i] now contains the total energy from starting at position 'i'
            maxEnergy = Math.max(maxEnergy, energy[i]);
        }

        // step 4 - return maximum energy
        return maxEnergy;
    }

    public static void main(String[] args) {
        int[] energy = {5,2,-10,-5,1};
        int k = 3;

        // int[] energy = {-2,-3,-1};
        // int k = 2;
        System.out.println(maximumEnergy(energy, k));
    }
}