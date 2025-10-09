
// Problem link - https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/?envType=daily-question&envId=2025-10-09

package Array_problems;

public class FindMinimumAmountOfTimeToBrewPotions {
    public static long minTime(int[] skill, int[] mana) {
        // find size of skill and & mana
        int n = skill.length;
        int m = mana.length;

        // track when each wizard finishes their current work
        long[] finishTime = new long[n];

        // step 1 - process each potion sequentially
        for(int j=0; j<m; j++){
            // step 2 - first wizard starts immediately just after finishing previous potion
            finishTime[0] += (long) mana[j] * skill[0];

            // step 3 - each wizard starts when both they and previous wizard are ready
            for(int i=1; i<n; i++){
                finishTime[i] = Math.max(finishTime[i], finishTime[i-1]) + (long) mana[j] * skill[i];
            }

            // step 4 - synchronize timing so potion flows smoothly
            for(int i=n-1; i>0; i--){
                finishTime[i-1] = finishTime[i] - (long) mana[j] * skill[i];
            }
        }

        // step 5 - Last wizard's finish time is minimum time needed
        return finishTime[n-1];
    }

    public static void main(String[] args) {
        // int[] skill = {1,5,2,4};
        // int[] mana = {5,1,4,2};

        // int[] skill = {1,1,1};
        // int[] mana = {1,1,1};

        int[] skill = {1,2,3,4};
        int[] mana = {1,2};
        System.out.println(minTime(skill, mana));
    }
}
