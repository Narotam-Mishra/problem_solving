
// Problem link - https://leetcode.com/problems/can-place-flowers/description/?envType=problem-list-v2&envId=array

package GreedyAlgorithms_problems;

public class CanPlaceFlowers {
    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        // track down number of flowers planted
        int planted = 0;
        int len = flowerbed.length;

        // step 1 - iterate on each flowerbed
        for(int i=0; i<len; i++){
            // step 2 - check if current flowerbed is empty (0)
            if(flowerbed[i] == 0){
                // check left neighbour of flowebed is empty or not
                boolean leftNeighbourEmpty = (i == 0) || (flowerbed[i-1] == 0);

                // check right neighbour of flowebed is empty or not
                boolean rightNeighbourEmpty = (i == len-1) || (flowerbed[i+1] == 0);

                // step 3 - if both neighbors are safe(empty), we can plant here
                if(leftNeighbourEmpty && rightNeighbourEmpty){
                    // plant flower
                    flowerbed[i] = 1;
                    
                    // count planted flower
                    planted++;

                    // step 4 - early termination if we have planted enough flowers
                    if(planted >= n){
                        return true;
                    }
                }
            }
        }

        // step 5 - check and return if we planted at least 'n' flowers
        return planted >= n;
    }

    public static void main(String[] args) {
        // int[] flowebed = {1,0,0,0,1};
        // int n = 1;

        int[] flowebed = {1,0,0,0,1};
        int n = 2;
        System.out.println(canPlaceFlowers(flowebed, n));
    }
}