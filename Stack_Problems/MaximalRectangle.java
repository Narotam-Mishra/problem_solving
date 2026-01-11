
// Problem link - https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11

package Stack_Problems;

import java.util.*;

public class MaximalRectangle {
    private static int[] getNSR(int[] height){
        int n = height.length;

        int[] nsr = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i=n-1; i>=0; i--){
            if(st.isEmpty()){
                nsr[i] = n;
            }else{
                while (!st.isEmpty() && height[st.peek()] >= height[i]) { 
                    st.pop();
                }

                if(st.isEmpty()){
                    nsr[i] = n;
                }else{
                    nsr[i] = st.peek();
                }
            }
            st.push(i);
        }

        return nsr;
    }

    private static int[] getNSL(int[] height){
        int n = height.length;

        int[] nsl = new int[n];
        Stack<Integer> st = new Stack<>();
        for(int i=0; i<n; i++){
            if(st.isEmpty()){
                nsl[i] = -1;
            }else{
                while (!st.isEmpty() && height[st.peek()] >= height[i]) { 
                    st.pop();
                }

                if(st.isEmpty()){
                    nsl[i] = -1;
                }else{
                    nsl[i] = st.peek();
                }
            }
            st.push(i);
        }

        return nsl;
    }

    private static int findMaximumArea(int[] height){
        // width --> NSR[i] - NSL[i] - 1
        // height -> height[i]

        // find NSR
        int[] NSR = getNSR(height);

        // find NSL
        int[] NSL = getNSL(height);

        // find width
        int n = height.length;
        int[] width = new int[n];
        for (int i = 0; i < n; i++) {
            width[i] = NSR[i] - NSL[i] - 1;
        }

        // find maximum area
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            int area = width[i] * height[i];
            maxArea = Math.max(maxArea, area);
        }
        return maxArea;
    }

    public static int maximalRectangle(char[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        // step 1 - find height of 1st rectangle
        int[] height = new int[n];
        for (int i = 0; i < n; i++) {
            height[i] = matrix[0][i] == '1' ? 1 : 0;
        }

        // step 2 - find maximum area of 1st rectangle
        int maxArea = findMaximumArea(height);

        // step 3 - find height of remaining rectangles
        for (int r = 1; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (matrix[r][c] == '0') {
                    height[c] = 0;
                } else {
                    height[c] += 1;
                }
            }

            // step 4 - updated maximum area
            maxArea = Math.max(maxArea, findMaximumArea(height));
        }

        // step 5 - return maximum area
        return maxArea;
    }

    public static void main(String[] args) {
        // char[][] matrix = {
        //         { '1', '0', '1', '0', '0' },
        //         { '1', '0', '1', '1', '1' },
        //         { '1', '1', '1', '1', '1' },
        //         { '1', '0', '0', '1', '0' }
        // };

        // char[][] matrix = {{'0'}};

        char[][] matrix = {{'1'}};
        System.out.println(maximalRectangle(matrix));
    }
}
