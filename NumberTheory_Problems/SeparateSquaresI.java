
// Problem link - https://leetcode.com/problems/separate-squares-i/?envType=daily-question&envId=2026-01-13

package NumberTheory_Problems;

public class SeparateSquaresI {
    private static boolean isBottomAreaEqualsTopArea(int[][] squares, double mid_y, double totalArea) {
        double bottomArea = 0.0;
        
        for (int[] square : squares) {
            double y = square[1];
            double len = square[2];
            
            double bottom_y = y;
            double top_y = y + len;
            
            if (mid_y >= top_y) {
                // full square below
                bottomArea += (len * len);
            } else if (mid_y > bottom_y) {
                // partial area below
                bottomArea += (mid_y - bottom_y) * len;
            }
        }
        
        // check if bottom area equals or exceeds half
        return bottomArea >= totalArea / 2.0;
    }

    public static double separateSquares(int[][] squares) {
        double s = Double.MAX_VALUE;
        double e = Double.MIN_VALUE;
        
        double total = 0.0;
        
        // step 1 - calculate total area and find range
        for (int[] square : squares) {
            double y = square[1];
            double len = square[2];
            
            total += (len * len);
            
            s = Math.min(s, y);
            e = Math.max(e, y + len);
        }
        
        // step 2 - using binary search
        while (e - s > 1e-6) {
            double mid_y = s + (e - s) / 2;
            
            // step 3
            if (isBottomAreaEqualsTopArea(squares, mid_y, total)) {
                e = mid_y;
            } else {
                s = mid_y;
            }
        }

        // step 4
        return (s + e) / 2.0;
    }

    public static void main(String[] args) {
        // int[][] squares = {{0,0,1},{2,2,1}};

        int[][] squares = {{0,0,2},{1,1,1}};
        System.out.println(separateSquares(squares));
    }
}
