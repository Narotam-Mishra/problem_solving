
// Problem link :- https://leetcode.com/problems/flipping-an-image/description/?envType=problem-list-v2&envId=bit-manipulation

package BitMasking_Problems;

import java.util.Arrays;

public class FlippingAnImage {
    public static int[][] flipAndInvertImage(int[][] image) {
        // iterate through each row of the image matrix
        for(int[] row : image){
            // start pointer for the row (left side)
            int left = 0;
            
            // end pointer for the row (right side)
            int right = row.length - 1;

            // swap and invert simultaneously
            while(left <= right){
                // swap the left and right elements
                // XOR operation: 1 ^ 1 = 0, 0 ^ 1 = 1, so row[left] ^ 1 will invert the value
                int temp = row[left] ^ 1;
                row[left] = row[right] ^ 1;
                row[right] = temp;

                // move pointers towards the center
                left++;
                right--;
            }
        }
        // return the modified image
        return image;
    }

    public static void main(String[] args) {
        int[][] image = {{1,1,0},{1,0,1},{0,0,0}};
        int[][] res = flipAndInvertImage(image);
        for(int[] row : res){
            System.out.print(Arrays.toString(row));
        }
        System.out.println();
    }
}