
// Problem link - https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/?envType=daily-question&envId=2026-05-12

package Array_problems;

import java.util.Arrays;

public class MinimumInitialEnergyToFinishTasks {
    private boolean isMinimumEnergyPossible(int[][] tasks, int mid) {
        // check if starting with 'mid' energy can finish all tasks in sorted order.
        for (int[] task : tasks) {
            // extract actual energy spent and minimum energy required to start this task.
            int actual = task[0];
            int minimum = task[1];

            // check If current energy is less than required minimum, this starting energy fails.
            if (minimum > mid) {
                return false;
            }

            // after completing the task, actual energy is consumed.
            mid -= actual;
        }

        return true;
    }

    public int minimumEffort(int[][] tasks) {
        // step 1 - sort tasks by (minimum - actual) in descending order.
        // tasks with a larger extra energy requirement should be attempted earlier.
        Arrays.sort(tasks, (task1, task2) -> {
            int diff1 = task1[1] - task1[0];
            int diff2 = task2[1] - task2[0];

            return diff2 - diff1;
        });

        // step 2 - binary search on the answer, i.e., minimum initial energy.
        int s = 0;
        int e = (int) 1e9;
        int res = Integer.MAX_VALUE;

        while (s <= e) {
            int mid = s + (e - s) / 2;

            // step 3 - check If 'mid' energy is enough, try to minimize the answer.
            if (isMinimumEnergyPossible(tasks, mid)) {
                res = mid;
                e = mid - 1;
            } else {
                // otherwise, more initial energy is required.
                s = mid + 1;
            }
        }

        // step 4 - return the minimum valid initial energy.
        return res;
    }

    public static void main(String[] args) {
        int[][] tasks = {{1,2},{2,4},{4,8}};

        // int[][] tasks = {{1,3},{2,4},{10,11},{10,12},{8,9}};

        // int[][] tasks = {{1,7},{2,8},{3,9},{4,10},{5,11},{6,12}};
        MinimumInitialEnergyToFinishTasks obj = new MinimumInitialEnergyToFinishTasks();
        System.out.println(obj.minimumEffort(tasks));
    }
}
