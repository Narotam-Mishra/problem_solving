
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/

package sliding_window_problems;

import java.util.*;

public class FindXSumOfAllKLongSubarraysII {
    private static int compare(int[] a, int[] b){
        if (a[0] != b[0]) return Integer.compare(a[0], b[0]);
        return Integer.compare(a[1], b[1]);
    }

    // utility method to insert a {frequency, value} pair into appropriate set
    private static long insertPair(int[] p, TreeSet<int[]> mainSet, TreeSet<int[]> secSet, long sum, int x){
        // if main set has room OR this element is larger than smallest in main set
        if(mainSet.size() < x || compare(p, mainSet.first()) > 0){
            sum += (long) p[0] * p[1];
            mainSet.add(p);

            // if main set exceeds size x, move smallest to secondary set
            if(mainSet.size() > x){
                int[] smallest = mainSet.pollFirst();
                
                // update running sum
                sum -= (long) smallest[0] * smallest[1];
                secSet.add(smallest);
            }
        }else{
            // this pair element doesn't qualify for top x
            // add it to secondary set
            secSet.add(p);
        }
        return sum;
    }

    // utility method to remove a [frequency, value] pair from sets
    private static long removePair(int[] p, TreeSet<int[]> mainSet, TreeSet<int[]> secSet, long sum){
        // check if pair exist in mainSet
        if(mainSet.remove(p)){
            // remove from mainSet and update sum
            sum -= (long) p[0] * p[1];

            // move largest element pair from secondary set to main set to fill the gap
            if(!secSet.isEmpty()){
                int[] largest = secSet.pollLast();
                mainSet.add(largest);

                // update running sum after insertion
                sum += (long) largest[0] * largest[1];
            }
        }else{
            // pair is in secondary set, simply remove it
            secSet.remove(p);
        }
        return sum;
    }

    public static long[] findXSum(int[] nums, int k, int x) {
        int n = nums.length;
        long[] res = new long[n - k + 1];

        // track frequency of each element in current window
        Map<Integer, Integer> frqMap = new HashMap();

        // main set : main set contains top x {frequency, element}
        TreeSet<int[]> mainSet = new TreeSet<>((a, b) -> {
            if(a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        // secondary set : secondary set, sec contains remaining {frequency, element}
        TreeSet<int[]> secSet = new TreeSet<>((a, b) -> {
            if(a[0] != b[0]) return Integer.compare(a[0], b[0]);
            return Integer.compare(a[1], b[1]);
        });

        // maintains sum of top x elements from main set
        long currSum = 0;

        // using sliding window approach
        int i = 0, j = 0; 
        int idx = 0;

        while(j < n){
            // step 1 - remove old frequency pair if element already exist
            int currFrq = frqMap.getOrDefault(nums[j], 0);
            if(currFrq > 0){
                currSum = removePair(new int[]{currFrq, nums[j]}, mainSet, secSet, currSum);
            }

            // step 2 - increment frequency and insert new pair
            frqMap.put(nums[j], currFrq + 1);
            currSum = insertPair(new int[]{currFrq+1, nums[j]}, mainSet, secSet, currSum, x);

            // step 3 - when window reaches size k, record result and slide
            if(j - i + 1 == k){
                res[idx++] = currSum;

                // remove leftmost element from window
                int leftFrq = frqMap.get(nums[i]);
                currSum = removePair(new int[]{leftFrq, nums[i]}, mainSet, secSet, currSum);

                // if frequency becomes 0, remove from map
                if(leftFrq == 1){
                    frqMap.remove(nums[i]);
                }else{
                    // otherwise re-insert
                    frqMap.put(nums[i], leftFrq-1);
                    currSum = insertPair(new int[]{leftFrq - 1, nums[i]}, mainSet, secSet, currSum, x);
                }
                i++;
            }
            j++;
        }

        // step 4 - return final result, res
        return res;
    }

    public static void main(String[] args) {
        // int[] nums = {3,8,7,8,7,5};
        // int k = 2, x = 2;

        int[] nums = {1,1,2,2,3,4,2,3};
        int k = 6, x = 2;
        long[] res = findXSum(nums, k, x);
        System.out.println(Arrays.toString(res));
    }
}
