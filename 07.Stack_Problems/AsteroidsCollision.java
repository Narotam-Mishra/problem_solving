
// Problem link - https://leetcode.com/problems/asteroid-collision/

package Stack_Problems;

import java.util.Arrays;
import java.util.Stack;

public class AsteroidsCollision {
    public static int[] asteroidCollision(int[] asteroids) {
        Stack<Integer> stack = new Stack<>();
        for(int ast : asteroids){
            if(ast > 0 || stack.isEmpty()){
                // If the current asteroid is positive, or the stack is empty,
                // it will not collide with any previous asteroids, so we push it onto the stack.
                stack.push(ast);
            }else{
                // If the current asteroid is negative
                while (!stack.isEmpty() && stack.peek() > 0 && stack.peek() < Math.abs(ast)) {
                    // If the top of the stack is positive and has a smaller magnitude than the current asteroid
                    // then the top of the stack will be destroyed, 
                    // so we pop it and repeat the collision check with the new top
                    stack.pop();
                }
                if(stack.isEmpty() || stack.peek() < 0){
                    // If the stack is empty or the top of the stack is negative, 
                    // then the current asteroid will not collide with any other asteroids, 
                    // So, we push the current asteroid onto the stack.
                    stack.push(ast);
                }else if(!stack.isEmpty() && stack.peek() == Math.abs(ast)){
                    // If the top of the stack has the same magnitude as the current asteroid, 
                    // both asteroids will explode & hence we pop from stack
                    stack.pop();
                }
            }
        }

        // store stack items to an array
        int[] res = new int[stack.size()];
        for(int i=res.length-1; i>=0; i--){
            res[i] = stack.pop();
        }
        return res;
    }

    public static void main(String[] args) {
        // int[] ast = {-5, -2, 4, 3, 1, -6, 8, -2};

        // int[] ast = {5, 10, -5};

        int[] ast = {-2, -1, 1, 2};
        int[] ans = asteroidCollision(ast);
        System.out.println(Arrays.toString(ans));
    }
}