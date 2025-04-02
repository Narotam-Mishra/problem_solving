
// Problem link - https://leetcode.com/problems/snake-in-matrix/description/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class SnakeInMatrix {
    public static int finalPositionOfSnake(int n, List<String> commands) {
        // step 1 - initial position at top left corner (0, 0)
        int row = 0, col = 0;

        // step 2 - iterate through each comamnd
        for(String command : commands){
            // move one row up 
            if(command.equals("UP")) row--;

            // move one row down 
            else if(command.equals("DOWN")) row++;

            // move one column left 
            else if(command.equals("LEFT")) col--;

            // move one column right
            else col++;
        }

        // step 3 - return final grid position
        return (row * n) + col;
    }

    public static void main(String[] args) {
        // int n = 2;
        // List<String> commands = Arrays.asList("RIGHT", "DOWN");

        int n = 3;
        List<String> commands = Arrays.asList("DOWN","RIGHT","UP");
        System.out.println(finalPositionOfSnake(n, commands));
    }
}