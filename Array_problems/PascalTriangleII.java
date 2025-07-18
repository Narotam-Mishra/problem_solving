package Array_problems;

import java.util.*;

public class PascalTriangleII {
    public static List<Integer> getRow(int rowIndex) {
        // store result in `res`
        List<Integer> res = new ArrayList<>();
        res.add(1);

        // edge case: if rowIndex is 0, return [1]
        if (rowIndex == 0) {
            return res;
        }

        // step 1 - generate each row of Pascal's triangle
        // using formula - C(n,i) = C(n,i-1) * (n-i+1) / i
        // where `n` is rowIndex and `i` is the current position
        for (int i = 1; i <= rowIndex; i++) {
            // step 2 - calculate next element based on previous element
            long nextVal = (long) res.get(i - 1) * (rowIndex - i + 1) / i;

            // store in result `res`
            res.add((int)nextVal);
        }

        // step 3 - return result `res`
        return res;
    }

    public static void main(String[] args) {
        // int rowIndex = 3;

        // int rowIndex = 0;

        int rowIndex = 1;
        List<Integer> res = getRow(rowIndex);
        System.out.println(res);
    }
}