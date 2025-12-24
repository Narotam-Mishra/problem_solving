
// Problem link - https://leetcode.com/problems/apple-redistribution-into-boxes/description/?envType=daily-question&envId=2025-12-24

package GreedyAlgorithms_problems;

import java.util.*;

public class AppleRedistributionIntoBoxes {
    public static int minimumBoxes(int[] apple, int[] capacity) {
        // step 1 - sort capacity in descending order
        Arrays.sort(capacity);
        // Reverse the array to get descending order
        for (int i = 0; i < capacity.length / 2; i++) {
            int temp = capacity[i];
            capacity[i] = capacity[capacity.length - 1 - i];
            capacity[capacity.length - 1 - i] = temp;
        }

        // step 2 - find sum of all apples
        int applesSum = 0;
        for (int a : apple) {
            applesSum += a;
        }

        // step 3 - start distributing apples starting from largest box
        // and maintain box count
        int boxCount = 0, currentApples = 0;
        for (int cap : capacity) {
            currentApples += cap;
            boxCount++;
            if (currentApples >= applesSum) {
                return boxCount;
            }
        }

        // step 4 - return the minimum number of boxes
        return boxCount;
    }

    public static void main(String[] args) {
        // int[] apple = {1,3,2};
        // int[] capacity = {4,3,1,5,2};

        int[] apple = {5,5,5};
        int[] capacity = {2,4,2,7};
        System.out.println(minimumBoxes(apple, capacity));
    }
}
