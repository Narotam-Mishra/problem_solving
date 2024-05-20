
// Problem link - https://leetcode.com/problems/richest-customer-wealth/

package Array_problems;

public class RichestCustomerWealth {
    
    public static int findMax(int a, int b){
        return a > b ? a : b;
    }
    
    public int maximumWealth(int[][] accounts) {
        int maxWealth = 0;
        
        for(int p=0; p<accounts.length; p++){
            int curSum=0;
            for(int a=0; a<accounts[p].length; a++){
                curSum += accounts[p][a];
            }
            maxWealth = findMax(maxWealth,curSum);
        }
        return maxWealth;
    }
}
