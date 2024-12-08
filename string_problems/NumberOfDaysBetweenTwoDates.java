
// Problem link : https://leetcode.com/problems/number-of-days-between-two-dates/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

package string_problems;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class NumberOfDaysBetweenTwoDates {
    public static int daysBetweenDates(String date1, String date2) {
        // parse the input strings into LocalDate objects
        LocalDate d1 = LocalDate.parse(date1);
        LocalDate d2 = LocalDate.parse(date2);

        // calculate the absolute difference in days
        return (int) Math.abs(ChronoUnit.DAYS.between(d1, d2));
    }

    public static void main(String[] args) {
        // String date1 = "2019-06-29", date2 = "2019-06-30";

        String date1 = "2020-01-15", date2 = "2019-12-31";
        System.out.println(daysBetweenDates(date1, date2));
    }
}