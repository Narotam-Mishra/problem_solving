
/*

You are given an array of itegers value. Find the minimum cost to remove all elements from the array. The cost to remove any one element is equal to the sum of elements at that point of time in array. 

*/

package Array_problems;

import java.util.*;

/**
 * MinimumCost
 */
public class MinimumCost {

    public static void reverse(int [] arr){
        int s = 0, e = arr.length-1;
        while(s<e){
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;
            s++;
            e--;
        }
    }
    public static int findMinCost(int[] arr){
        int totalSum = 0;
        // Calculate total sum of array elements
        for(int num : arr){
            totalSum += num;
        }

         // to find minimum cost to remove all elements, sort the array items in descending order
         Arrays.sort(arr);
         reverse(arr);

        int cost = 0;
        // Iterate through the array and calculate the cost to remove each element
        for(int i=0; i<arr.length; i++){
            // Add the current element's value to the total cost
            cost += totalSum;
            // update total sum 'ts' by substracting (removing) current element
            totalSum -= arr[i];
        }

        return cost;
    }

    public static void main(String[] args) {
        int [] arr = {4,1,6};
        int minCost = findMinCost(arr);
        System.out.println(minCost);
    }
}