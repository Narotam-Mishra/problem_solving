
// Problem link - https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-06

package Array_problems;

import java.util.*;

public class WalkingRobotSimulation {
    public int robotSim(int[] commands, int[][] obstacles) {
        // step 1 - set to access obstacles quickly
        Set<String> st = new HashSet<>();
        for (int[] obs : obstacles) {
            st.add(obs[0] + "_" + obs[1]);
        }

        // start simulation
        int x = 0, y = 0;
        int maxDistance = 0;

        // pointing to North dir
        int[] dir = { 0, 1 };

        // step 2 - move through each command
        for (int cmd : commands) {
            if (cmd == -2) {
                // Turn left 90 degrees
                dir = new int[] { -dir[1], dir[0] };
            } else if (cmd == -1) {
                // Turn right 90 degrees
                dir = new int[] { dir[1], -dir[0] };
            } else {
                // Move in the direction step by step
                for (int s = 0; s < cmd; s++) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];

                    // Check if newX & newY is part of obstacles
                    if (st.contains(newX + "_" + newY))
                        break;

                    x = newX;
                    y = newY;
                }
            }

            // step 3 - update maximum distance
            maxDistance = Math.max(maxDistance, x * x + y * y);
        }

        // step 4 - return final maximum distance
        return maxDistance;
    }

    public static void main(String[] args) {
        WalkingRobotSimulation obj = new WalkingRobotSimulation();
        // int[] commands = {4,-1,3}; 
        // int[][] obstacles = {};

        // int[] commands = {4,-1,4,-2,4}; 
        // int[][] obstacles = {{2,4}};

        int[] commands = {6,-1,-1,6}; 
        int[][] obstacles = {{0,0}};
        System.out.println(obj.robotSim(commands, obstacles));
    }
}
