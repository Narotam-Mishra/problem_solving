
// Problem link - https://leetcode.com/problems/maximum-average-pass-ratio/?envType=daily-question&envId=2025-09-01

package Heaps_PriorityQueue_problems;

import java.util.*;

public class MaximumAveragePassRatio {
    public static double maxAverageRatio(int[][] classes, int extraStudents) {
        // get the number of classes we need to work with
        int n = classes.length;

        // step 1 - create a max-heap using PriorityQueue with custom comparator
        // we will store arrays: [gain, class_index]
        // max heap: higher gain has priority
        PriorityQueue<double[]> pq = new PriorityQueue<>((a, b) -> Double.compare(b[0], a[0]));

        // step 2 - calculate initial gain for each class and add to priority queue
        for (int i = 0; i < n; i++) {
            // calculate current pass ratio for class i
            double currRatio = (double)classes[i][0] / classes[i][1];
        
            // calculate what the pass ratio would be if we add 1 extra student
            double newRatio = (double)(classes[i][0] + 1) / (classes[i][1] + 1);
        
            // calculate the improvement (delta/gain) we get by adding 1 student
            double gain = newRatio - currRatio;
        
            // add to max-heap: {gain, class_index}
            pq.offer(new double[]{gain, i});
        }

        // step 3 - greedily assign each extra student to the class with maximum gain
        while (extraStudents > 0) {
            extraStudents--;

            // get the class that currently offers maximum gain
            double[] curr = pq.poll();

            // gain value
            double gain = curr[0];

            // index of the class with max gain
            int idx = (int)curr[1];

            // step 4 - add one extra student to the selected class
            classes[idx][0]++;   // increment passing students
            classes[idx][1]++;   // increment total students

            // step 5 - recalculate the gain for this class after adding the student
            double currRatio = (double)classes[idx][0] / classes[idx][1];
            double newRatio = (double)(classes[idx][0] + 1) / (classes[idx][1] + 1);
        
            // calculate updated gain for this class
            gain = newRatio - currRatio;
        
           // step 6 - put the class back into priority queue with its new gain
           pq.offer(new double[]{gain, idx});
        }

        // step 7 - calculate the final average pass ratio across all classes
        double res = 0.0;
        for (int i = 0; i < n; i++) {
            res += (double)classes[i][0] / classes[i][1];
        }

        // step 8 - return average = total_sum_of_ratios / number_of_classes
        return res / n;
    }

    public static void main(String[] args) {
        // int[][] classes = {{1,2},{3,5},{2,2}};
        // int extraStudents = 2;

        int[][] classes = {{2,4},{3,9},{4,5},{2,10}};
        int extraStudents = 4;
        System.out.println(maxAverageRatio(classes, extraStudents));
    }
}
