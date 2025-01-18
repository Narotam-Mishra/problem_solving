
// Problem link : https://leetcode.com/problems/destination-city/description/?envType=problem-list-v2&envId=hash-table

package Hashing_and_HashMap_problems;

import java.util.*;

public class DestinationCity {
    public static String destCity(List<List<String>> paths) {
        // step 1 - collect all starting cities in `startingCities` set
        HashSet<String> startingCities = new HashSet<>();
        for(List<String> path : paths){
            startingCities.add(path.get(0));
        }

        // step 2 - find destination city
        for(List<String> path : paths){
            String cityB = path.get(1);
            if(!startingCities.contains(cityB)){
                return cityB;
            }
        }

        // if no city is found (though guaranteed in this problem), return null
        return null;
    }

    public static void main(String[] args) {
        // List<List<String>> paths = Arrays.asList(
        //     Arrays.asList("London","New York"),
        //     Arrays.asList("New York","Lima"),
        //     Arrays.asList("Lima","Sao Paulo")
        // );

        List<List<String>> paths = Arrays.asList(
            Arrays.asList("B","C"),
            Arrays.asList("D","B"),
            Arrays.asList("C","A")
        );

        String res = destCity(paths);
        System.out.println(res);
    }
}