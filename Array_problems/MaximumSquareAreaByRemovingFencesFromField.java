
// Problem link - https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/?envType=daily-question&envId=2026-01-16

package Array_problems;

import java.util.*;

public class MaximumSquareAreaByRemovingFencesFromField {
    public static int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        final int mod = 1000000007;

        // step 1 - convert arrays to lists and add boundaries
        List<Integer> hFencesList = new ArrayList<>();
        for (int fence : hFences) {
            hFencesList.add(fence);
        }
        hFencesList.add(1);
        hFencesList.add(m);

        List<Integer> vFencesList = new ArrayList<>();
        for (int fence : vFences) {
            vFencesList.add(fence);
        }
        vFencesList.add(1);
        vFencesList.add(n);

        // sort both fences
        Collections.sort(hFencesList);
        Collections.sort(vFencesList);

        // step 2 - find all widths for vFences
        Set<Integer> widths = new HashSet<>();
        for (int i = 0; i < vFencesList.size(); i++) {
            for (int j = i + 1; j < vFencesList.size(); j++) {
                int w = vFencesList.get(j) - vFencesList.get(i);
                widths.add(w);
            }
        }
        
        // step 3 - find all heights for hFences
        int maxSide = 0;
        for (int i = 0; i < hFencesList.size(); i++) {
            for (int j = i + 1; j < hFencesList.size(); j++) {
                int h = hFencesList.get(j) - hFencesList.get(i);
                if (widths.contains(h)) {
                    maxSide = Math.max(maxSide, h);
                }
            }
        }

        // step 4 - return area using maximum side
        return maxSide == 0 ? -1 : (int)((1L * maxSide * maxSide) % mod);
    }

    public static void main(String[] args) {
        // int m = 4, n = 3;
        // int[] hFences = {2,3}, vfences = {2};

        int m = 6, n = 7;
        int[] hFences = {2}, vfences = {4};
        System.out.println(maximizeSquareArea(m, n, hFences, vfences));
    }
}
