
// Problem link - https://leetcode.com/problems/count-square-sum-triples/description/?envType=daily-question&envId=2025-12-08

package NumberTheory_Problems;

public class CountSquareSumTriples {
    public static int countTriples(int n) {
        // store count of square triplets
        int count = 0;

        // step 1 - iterate on possible value of `a` & `b` and find triplets
        for(int a=1; a<=n; a++){
            for(int b=1; b<=n; b++){
                // compute `c2`
                int c2 = a*a + b*b;

                // find square root value of `c2`
                int c = (int)Math.sqrt(c2);

                // check if `c2` is perfect square number or not
                if(c <= n && c*c == c2){
                    // increment triplet counter
                    count++;
                }
            }
        }

        // step 3 - return the number of square triples
        return count;
    }

    public static void main(String[] args) {
        // int n = 5;

        int n = 10;
        System.out.println(countTriples(n));
    }
}
