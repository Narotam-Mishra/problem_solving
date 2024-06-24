
// Problem link - https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/

package Heaps_PriorityQueue_problems;

import java.util.*;

public class MinCostToHireKWorkers {

    // Optimal Approach
    public static double mincostToHireWorkers(int[] quality, int[] minWage, int k) {
        int n = quality.length;
        double minCost = Double.MAX_VALUE;

        // create an array to store the ratio of wage to quality for each worker
        double[][] workerRatio = new double[n][2];

        // calculate the workerRatio array with (ratio, quality) pairs
        for(int worker = 0; worker < n; worker++){
            workerRatio[worker][0] = (double) minWage[worker] / quality[worker];
            workerRatio[worker][1] = (double) quality[worker];
        }

        // sort the workers by their wage-to-quality ratio in ascending order
        Arrays.sort(workerRatio, Comparator.comparingDouble(a -> a[0]));

        // using a max-heap to keep track of the k smallest quality values
        PriorityQueue<Double> pq = new PriorityQueue<>(Comparator.reverseOrder());

        // add the first k workers to the heap and calculate the initial quality sum
        double qualitySum = 0;
        for(int i=0; i<k; i++){
            pq.add(workerRatio[i][1]);
            qualitySum += workerRatio[i][1];
        }

        // get the ratio of the k-th worker (the manager)
        double managerRatio = workerRatio[k-1][0];
        // calculate the initial minimum cost using the k-th worker's ratio and the quality sum
        minCost = managerRatio * qualitySum;

        // iterate through the remaining workers
        for(int manager = k; manager < n; manager++){
            // update the manager ratio to the current worker's ratio
            managerRatio = workerRatio[manager][0];

            // add the current worker's quality to the heap and update the quality sum
            pq.add(workerRatio[manager][1]);
            qualitySum += workerRatio[manager][1];

            // if the heap size exceeds k, 
            // remove the largest quality value to maintain the smallest k qualities
            if(pq.size() > k){
                qualitySum -= pq.poll();
            }

            // calculate the new minimum cost and update minCost if the new cost is lower
            minCost = Math.min(minCost, managerRatio * qualitySum);
        }

        // return the minimum wage cost to hire k workers
        return minCost;
    }

    // Brute Force Approach (will give TLE)
    public static double mincostToHireWorkers1(int[] quality, int[] minWage, int k) {
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