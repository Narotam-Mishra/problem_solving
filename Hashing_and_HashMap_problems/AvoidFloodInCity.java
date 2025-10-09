
// Problem link - https://leetcode.com/problems/avoid-flood-in-the-city/?envType=daily-question&envId=2025-10-07

package Hashing_and_HashMap_problems;

import java.util.*;

public class AvoidFloodInCity {
    public static int[] avoidFlood1(int[] rains) {
        // get the total number of days
        int n = rains.length;

        // list to store indices of dry days (when rains[i] == 0)
        // these are the days we can choose to dry a lake
        List<Integer> dryDays = new ArrayList<>();
        
        // map to track which lakes are currently full
        // key: lake number, value: the day index when it was last filled
        Map<Integer, Integer> filledLakes = new HashMap<>();

        // result array to store our answer
        int[] res = new int[n];

        // step 1 - process each day sequentially
        for(int i=0; i<n; i++){
            int lake = rains[i];

            // step 2 - case 1: DRY DAY (rains[i] == 0)
            if(lake == 0){
                // store this day index as an available dry day
                dryDays.add(i);
                
                // set placeholder value (dry lake 1 by default)
                // this will be overwritten if we need to use this day
                res[i] = 1;
            }
            // step 3 - case 2: RAINY DAY (rains[i] > 0)
            else{
                // check if this lake is already full
                if(filledLakes.containsKey(lake)){
                    // FLOOD ALERT! This lake is already full
                    // we must have dried it using a dry day that occurred

                    // get the day when this lake was last filled
                    int lastFilledIndex = filledLakes.get(lake);
                    
                    // variable to store the dry day we'll use to prevent flood
                    int index = -1;

                    // step 4 - search through available dry days to find one that occurred
                    // after the lake was last filled
                    for(int j=0; j<dryDays.size(); j++){
                        // check if this dry day is after the lake was filled
                        if(dryDays.get(j) > lastFilledIndex){
                            // found a valid dry day!
                            index = dryDays.get(j);
                            
                            // remove this dry day from available list
                            dryDays.remove(j);
                            break;
                        }
                    }

                    // step 5 - if no valid dry day was found, flood is inevitable
                    if(index == -1){
                        // return empty array to indicate impossible scenario
                        return new int[0];
                    }

                    // step 6 - assign this dry day to dry the specific lake
                    res[index] = lake;
                }

                // step 7 - mark this lake as full (or update fill time)
                // store current day as the last time this lake was filled
                filledLakes.put(lake, i);
                
                // step 8 - for rainy days, the answer is always -1
                res[i] = -1;
            }
        }

        // step 9 - return the final result array
        return res;
    }

    public static int[] avoidFlood(int[] rains) {
        // get the total number of days
        int n = rains.length;

        // map to track which day each lake last received rain
        // key: lake number, value: the day index when it was last filled
        Map<Integer, Integer> rainyDay = new HashMap<>();

        // TreeSet (ordered set) to store all days with no rain (rains[i] == 0)
        TreeSet<Integer> zeroDays = new TreeSet<>();

        // store final result in `res` array, initialize all values to 1
        int[] res = new int[n];
        Arrays.fill(res, 1);

        // step 1 - process each day
        for(int i=0; i<n; i++){
            int lake = rains[i];

            // step 1 - check if it zero day (no rain), store it for later use
            if(lake == 0){
                zeroDays.add(i);
            }
            // step 2 - check if it's rainy day
            else{
                // mark -1 in the result `res` for this day
                res[i] = -1;

                // step 3 - check if this lake has already water from previous rain
                if(rainyDay.containsKey(lake)){
                    // it means lake is already full,
                    // step 4 - we need to find most recent zero day to dry it up
                    Integer zerothDay = zeroDays.ceiling(rainyDay.get(lake));

                    // step 5 - if no such zeroth day exist then we can't prevent flood
                    if(zerothDay == null){
                        // return empty array
                        return new int[0];
                    }

                    // step 6 - found zeroth day to dry this lake
                    res[zerothDay] = lake;

                    // step 7 - remove this zeroth day as it is utilised now
                    zeroDays.remove(zerothDay);
                }

                // step 8 - update the map with the current day as the last rain day for this lake
                rainyDay.put(lake, i);
            }
        }

        // step 9 - return final result `res`
        return res;
    }

    public static void main(String[] args) {
        // int[] rains = {1,2,3,4};

        // int[] rains = {1,2,0,0,2,1};

        int[] rains = {1,2,0,1,2};
        int[] res = avoidFlood(rains);
        System.out.println(Arrays.toString(res));
    }
}