package NumberTheory_Problems;

import java.util.PriorityQueue;

public class MinimumOperationsToMakeUniValueGrid {
    public int minOperations(int[][] grid, int x) {
        int m = grid.length;
        int n = grid[0].length;

        // step 1 - use min-heap to store all elements
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();

        // step 2 - check remainder consistency
        int remainder = -1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currRem = grid[i][j] % x;
                if (remainder == -1) {
                    remainder = currRem;
                } else if (remainder != currRem) {
                    return -1;
                }
                minHeap.offer(grid[i][j]);
            }
        }

        // step 3 - convert heap to array to find median
        int total = m * n;
        int[] arr = new int[total];
        for (int i = 0; i < total; i++) {
            arr[i] = minHeap.poll();
        }

        // step 4 - median is the middle element
        int median = arr[total / 2];

        // step 5 - calculate operations
        int operations = 0;
        for (int num : arr) {
            operations += Math.abs(num - median) / x;
        }

        return operations;
    }

    public static void main(String[] args) {
        int[][] grid = {{2,4},{6,8}};
        int x = 2;
        MinimumOperationsToMakeUniValueGrid obj = new MinimumOperationsToMakeUniValueGrid();
        System.out.println(obj.minOperations(grid, x));
    }
}
