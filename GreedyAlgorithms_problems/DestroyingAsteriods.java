
// Problem link - https://leetcode.com/problems/destroying-asteroids/description/?envType=daily-question&envId=2026-05-31

package GreedyAlgorithms_problems;

import java.util.*;

public class DestroyingAsteriods {
    public boolean asteroidsDestroyed(int mass, int[] asteroids) {
        // step 1 - sort asteroids by size so we can destroy the smallest ones first.
        Arrays.sort(asteroids);

        // use a long to avoid overflow when summing asteroid masses.
        long totalMass = mass;

        // step 2 - iterate through the asteroids in increasing order.
        for (int m : asteroids) {
            // check If the current asteroid is larger than our current mass,
            // we cannot destroy it and the answer is false.
            if (m > totalMass) {
                return false;
            }

            // destroy the asteroid and add its mass to our total mass.
            totalMass += m;
        }

        // step 3 - return true, If we destroyed all asteroids successfully
        return true;
    }

    public static void main(String[] args) {
        int mass = 10;
        int[] asteroids = {3, 9, 19, 5, 21};
        DestroyingAsteriods obj = new DestroyingAsteriods();
        System.out.println(obj.asteroidsDestroyed(mass, asteroids));
    }
}
