package NumberTheory_Problems;

public class CountNumberOfComputerUnlockingPermutations {
    public static int countPermutations(int[] complexity) {
        final int mod = 1000000007; 
        int n = complexity.length;

        // initialized result, `res` to 1
        // as first computer is already unlocked
        long res = 1;

        // step 1 - iterate on each complexity
        // we start from index 1 as computer0 (index - 0) is already unlocked
        for(int i=1; i<n; i++){
            // step 2 - check if complexity[i] <= complexity[0], no earlier
            // unlocked computer has lower complexity => unlocking i is
            // impossible => return 0.
            if(complexity[i] <= complexity[0]){
                return 0;
            }

            // step 3 - for every valid i, we can place it in ANY of the i
            // available positions among the already placed computers.
            res = (res * i) % mod;
        }

        // step 4 - return final result, `res`
        return (int)res;
    }

    public static void main(String[] args) {
        // int[] complexity = {1,2,3};

        int[] complexity = {3,3,3,4,4,4};
        System.out.println(countPermutations(complexity));
    }
}
