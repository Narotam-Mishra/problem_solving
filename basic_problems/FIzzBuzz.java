
// Problem link - https://leetcode.com/problems/fizz-buzz/

package basic_problems;

import java.util.*;

public class FIzzBuzz {
    public static List<String> fizzBuzz(int n) {
        List<String> res = new ArrayList<>();
        for(int i=1; i<=n; i++){
            if(i % 3 == 0 && i % 5 == 0){
                res.add("FizzBuzz");
            }else if(i % 3 == 0){
                res.add("Fizz");
            }else if(i % 5 == 0){
                res.add("Buzz");
            }else{
                res.add(String.valueOf(i));
            }
        }
        return res;
    }

    public static void main(String[] args) {
        List<String> res = fizzBuzz(50);
        for (String s : res) {
            System.out.print(s + " ");
        }
        System.out.println();
    }
}
