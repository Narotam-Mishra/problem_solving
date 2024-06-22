
// Problem link - https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

package Heaps_PriorityQueue_problems;

import java.util.Arrays;

public class MinCostToHireKWorkers {
    public static double mincostToHireWorkers(int[] quality, int[] minWage, int k) {
        int n = quality.length;
        double minCost = Double.MAX_VALUE;

        // iterate over each worker to consider them as the manager
        for(int manager = 0; manager < n; manager++){
            // calculate the ratio of minWage to quality for the manager
            double managerRatio = (double) minWage[manager] / quality[manager];

            // array to store actual (valid) wages for each worker
            double[] validWages = new double[n];
            int validCount = 0;

            // check each worker's wage when hired by this manager
            for(int worker = 0; worker < n; worker++){
                double workerWage = managerRatio * quality[worker];

                if(workerWage >= minWage[worker]){
                    // if the calculated worker's wage is greater than or equal to the worker's minimum wage
                    // that will be only valid
                    validWages[validCount++] = workerWage;
                }
            }

            if(validCount < k){
                // if we don't have enough valid workers, 
                // continue to the next manager
                continue;
            }

            // sort the valid wages in ascending order
            // as we need to find the least amount of wage
            Arrays.sort(validWages, 0, validCount);

            // Sum the smallest k wages
            double totalWage = 0;
            for(int i=0; i<k; i++){
                totalWage += validWages[i];
            }

            // update the minimum cost if we found a cheaper combination
            minCost = Math.min(minCost, totalWage);
        }
        return minCost;
    }

    public static void main(String[] args) {
        // int[] quality = {10, 20, 5};
        // int[] minWage = {70, 50, 30};
        // int k = 2;

        int[] quality = {3, 1, 10, 10, 1};
        int[] minWage = {4, 8, 2, 2, 7};
        int k = 3;
        System.out.println(mincostToHireWorkers(quality, minWage, k));
    }
}