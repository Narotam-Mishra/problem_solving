
// Problem link - https://leetcode.com/problems/lexicographical-numbers/description/

// Approach - using recursion

package Array_problems;

import java.util.*;

public class LexicographicalNumbers {
    private static void getLexicographicalOrderRecursion(int curNum, int n, List<Integer> res){
        // Base case: if the current number exceeds n, return
        if(curNum > n) return;

        // add current number curNum to result list res
        res.add(curNum);

        // Recursively call the recursive function for next numbers in lexical order (by multiplying by 10)
        getLexicographicalOrderRecursion(curNum*10, n, res);

        // check if the last digit of the current number is not 9, recursively call for the next number
        if(curNum % 10 != 9){
            getLexicographicalOrderRecursion(curNum+1, n, res);
        }

    }
    public static List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        getLexicographicalOrderRecursion(1, n, res);
        return res;
    }
    public static void main(String[] args) {
        int n = 13;
        List<Integer> res = lexicalOrder(n);
        for(int num : res){
            System.out.print(num + " ");
        }
        System.out.println();
    }
}