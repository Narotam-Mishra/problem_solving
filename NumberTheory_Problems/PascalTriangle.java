
// Problem link : https://leetcode.com/problems/pascals-triangle/description/

package NumberTheory_Problems;

import java.util.ArrayList;
import java.util.List;

public class PascalTriangle {
    public static List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res = new ArrayList<>();
        for(int i=0; i<numRows; i++){
            List<Integer> row = new ArrayList<>();
            row.add(1);
            for(int j=1; j<=i; j++){
                row.add(row.get(j-1) * (i-j+1)/j);
            }
            res.add(row);
        }
        return res;
    }

    public static void main(String[] args) {
        int numRows = 5;
        System.out.println(generate(numRows));
    }
}
