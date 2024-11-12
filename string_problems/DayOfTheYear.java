
// Problem link : https://leetcode.com/problems/day-of-the-year/description/?envType=problem-list-v2&envId=string&difficulty=EASY&status=TO_DO

package string_problems;

import java.time.LocalDate;
import java.time.temporal.ChronoUnit;

public class DayOfTheYear {
    public static int dayOfYear(String date) {
        // parse the date string to a LocalDate object
        LocalDate dateVal = LocalDate.parse(date);

        // create a LocalDate for the start of the year
        LocalDate startOfYear = LocalDate.of(dateVal.getYear(), 1, 1);

        // calculate the difference in days between the given date and January 1st
        long dayNumber = ChronoUnit.DAYS.between(startOfYear, dateVal) + 1;

        // return day number
        return (int) dayNumber;
    }

    public static void main(String[] args) {
        // String date = "2019-10-29";

        String date = "2019-02-10";
        System.out.println(dayOfYear(date));
    }
}