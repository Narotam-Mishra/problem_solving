
// Problem link - https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/?envType=daily-question&envId=2026-01-31

package Array_problems;

public class FindSmallestLetterGreaterThanTarget {
    public static char nextGreatestLetter(char[] letters, char target) {
        // find size of letters
        int n = letters.length;

        // step 1 - apply binary search and find result
        int s = 0, e = n - 1;

        int ansPos = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;

            if (letters[mid] > target) {
                ansPos = mid;
                e = mid - 1;
            } else {
                s = mid + 1;
            }
        }

        // step 2 - return first character if no target exist
        // otherwise return required result
        return ansPos == -1 ? letters[0] : letters[ansPos];
    }

    public static void main(String[] args) {
        // char[] letters = {'c','f','j'};
        // char target = 'a';

        // char[] letters = {'c','f','j'};
        // char target = 'c';

        char[] letters = {'x','x','y','y'};
        char target = 'x';
        System.out.println(nextGreatestLetter(letters, target));
    }
}
