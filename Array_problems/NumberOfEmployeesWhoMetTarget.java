package Array_problems;

public class NumberOfEmployeesWhoMetTarget {
    public static int numberOfEmployeesWhoMetTarget(int[] hours, int target) {
        // store the count of employees who worked at least target hours in `count`
        int count = 0;

        // step 1 - iterate on each hour
        for (int hour : hours) {

            // step 2 - check if working hour is greater than or equal to target hour
            if (hour >= target) {
                // increment counter
                count++;
            }
        }

        // step 3 - return counter `count`
        return count;
    }

    public static void main(String[] args) {
        // int[] hours = {0,1,2,3,4};
        // int target = 2;

        int[] hours = {5,1,4,2,2};
        int target = 6;
        System.out.println(numberOfEmployeesWhoMetTarget(hours, target));
    }
}
