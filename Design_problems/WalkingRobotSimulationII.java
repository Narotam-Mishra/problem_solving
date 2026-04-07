
// Problem link - https://leetcode.com/problems/walking-robot-simulation-ii/?envType=daily-question&envId=2026-04-07

package Design_problems;

import java.util.*;

public class WalkingRobotSimulationII {
    static class Robot {
        // store boundary positions: [x, y, dir]
        private List<int[]> pos;

        // keep track index in position grid
        private int idx;

        // keep track of movement
        private boolean moved;

        public Robot(int width, int height) {
            // initialization
            pos = new ArrayList<>();
            idx = 0;
            moved = false;

            // 0 -> East, 1 -> North, 2 -> West, 3 -> South
            // Bottom row (left to right)
            for (int x = 0; x < width; x++) {
                pos.add(new int[] { x, 0, 0 });
            }

            // Right column
            for (int y = 1; y < height; y++) {
                pos.add(new int[] { width - 1, y, 1 });
            }

            // top row (right to left)
            for (int x = width - 2; x >= 0; x--) {
                pos.add(new int[] { x, height - 1, 2 });
            }

            // Left column (top to bottom)
            for (int y = height - 2; y > 0; y--) {
                pos.add(new int[] { 0, y, 3 });
            }

            // handle corner case
            // make it south when robot came back to (0,0)
            pos.get(0)[2] = 3;
        }

        public void step(int num) {
            moved = true;
            int n = pos.size();
            idx = (idx + num) % n;
        }

        public int[] getPos() {
            int[] cur = pos.get(idx);
            return new int[] { cur[0], cur[1] };
        }

        public String getDir() {
            if (!moved) {
                return "East";
            }
            int dir = pos.get(idx)[2];
            switch (dir) {
                case 0:
                    return "East";
                case 1:
                    return "North";
                case 2:
                    return "West";
                case 3:
                default:
                    return "South";
            }
        }
    }

    public static void main(String[] args) {
        Robot robot = new Robot(4, 3);

        int[] pos;

        // Initial state
        pos = robot.getPos();
        System.out.println("Initial: (" + pos[0] + "," + pos[1] + "), Dir: " + robot.getDir());

        robot.step(2);
        pos = robot.getPos();
        System.out.println("After step(2): (" + pos[0] + "," + pos[1] + "), Dir: " + robot.getDir());

        robot.step(2);
        pos = robot.getPos();
        System.out.println("After step(2): (" + pos[0] + "," + pos[1] + "), Dir: " + robot.getDir());

        robot.step(10);
        pos = robot.getPos();
        System.out.println("After step(10): (" + pos[0] + "," + pos[1] + "), Dir: " + robot.getDir());
    }
}
