
// Problem link - https://leetcode.com/problems/trapping-rain-water/

package Array_problems;

public class TrappingRainWater {
    public static int trap(int[] height) {
        int n = height.length;

        // step 1 - find left max height
        int[] leftMax = new int[n];
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = Math.max(leftMax[i-1], height[i]);
        }

        // step 2 - find right max heigh
        int[] rightMax = new int[n];
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = Math.max(rightMax[i+1], height[i]);
        }

        // step 3 - find total water stored 
        int totalWaterStored = 0;
        for(int i=0; i<n; i++){
            int h = Math.min(leftMax[i], rightMax[i]) - height[i];
            totalWaterStored += h;
        }

        // step 4 - return total water stored
        return totalWaterStored;
    }

    public static void main(String[] args) {
        // int[] height = {0,1,0,2,1,0,1,3,2,1,2,1};

        int[] height = {4,2,0,3,2,5};
        System.out.println(trap(height));
    }
}
