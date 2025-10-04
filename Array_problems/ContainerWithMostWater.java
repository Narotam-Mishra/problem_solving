package Array_problems;

public class ContainerWithMostWater {
    public static int maxArea(int[] height) {
        // find size of height list
        int n = height.length;

        // use two-pointers approach
        int s = 0, e = n - 1;

        // store maximum amount of water a container can store
        int maxWater = 0;

        // step 1 - continue until two-pointers meet
        while (s < e) {
            // step 2 - calculate the width of the container
            // width is the distance between the two lines
            int width = e - s;

            // step 3 - find the effective height of the container
            // water level is constrained by the shorter of the two lines
            int h = Math.min(height[s], height[e]);

            // step 4 - calculate the area (water capacity) of current container
            // Area = width × height
            int area = h * width;

            // step 5 - update maximum water capacity if current is larger
            maxWater = Math.max(maxWater, area);

            // step 6 - move the pointer pointing to the shorter line
            // moving the taller line inward can only decrease area
            // moving the shorter line gives potential to find a taller line
            if (height[s] > height[e]) {
                // right line is shorter, move it inward
                e--;
            } else {
                // left line is shorter or equal, move it inward
                s++;
            }
        }

        // step 7 - return the maximum water capacity found
        return maxWater;
    }

    public static void main(String[] args) {
        // int[] height = {1,8,6,2,5,4,8,3,7};

        int[] height = {1,1};
        System.out.println(maxArea(height));
    }
}
