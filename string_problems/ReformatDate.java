
// Problem link - https://leetcode.com/problems/reformat-date/?envType=problem-list-v2&envId=string

package string_problems;

import java.util.*;

public class ReformatDate {
    public static String reformatDate(String date) {
        // step 1 - split date into day, month and year
        String[] parts = date.split(" ");
        String day = parts[0];
        String month = parts[1];
        String year = parts[2];

        // step 2 - remove the ordinal indicators from day
        day = day.replaceAll("st|nd|rd|th", "");

        // ensure day is two digits by padding with a leading zero if necessary
        if(day.length() == 1){
            day = "0" + day;
        }

        // step 3 - create month map
        Map<String, String> monthMap = new HashMap<>();
        monthMap.put("Jan", "01");
        monthMap.put("Feb", "02");
        monthMap.put("Mar", "03");
        monthMap.put("Apr", "04");
        monthMap.put("May", "05");
        monthMap.put("Jun", "06");
        monthMap.put("Jul", "07");
        monthMap.put("Aug", "08");
        monthMap.put("Sep", "09");
        monthMap.put("Oct", "10");
        monthMap.put("Nov", "11");
        monthMap.put("Dec", "12");

        // step 3 - get the numeric month from map
        String numericMonth = monthMap.get(month);

        // step 5 - combine parts into desired format and return
        return year + "-" + numericMonth + "-" + day;
    }

    public static void main(String[] args) {
        // String date = "20th Oct 2052";

        // String date = "6th Jun 1933";

        String date = "26th May 1960";
        System.out.println(reformatDate(date));
    }
}