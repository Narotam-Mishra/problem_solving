
// Problem link - https://leetcode.com/problems/points-that-intersect-with-cars/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class PointsThatIntersectWithCars {

    public static int numberOfPoints(List<List<Integer>> nums) {
        // step 1 - create set to store unique covered points
        Set<Integer> coveredPoints = new HashSet<>();

        // step 2 - iterate over each car's parking range
        for(List<Integer> car : nums){
            int start = car.get(0);
            int end = car.get(1);

            // add each integer point from start to end into the set
            for(int i=start; i<=end; i++){
                coveredPoints.add(i);
            }
        }

        // step 3 - return the size of set 
        return coveredPoints.size();
    }

    public static void main(String[] args) {
        List<List<Integer>> nums = Arrays.asList(
            Arrays.asList(3, 6),
            Arrays.asList(1, 5),
            Arrays.asList(4, 7)
        );

        // List<List<Integer>> nums = Arrays.asList(
        //     Arrays.asList(1, 3),
        //     Arrays.asList(5, 8)
        // );

        System.out.println(numberOfPoints(nums));
    }
}