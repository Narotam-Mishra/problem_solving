
// Problem link - https://leetcode.com/problems/meeting-rooms-iii/?envType=daily-question&envId=2025-12-27

package Array_problems;

import java.util.*;

public class MeetingRoomIII {
    public static int mostBooked(int n, int[][] meetings) {
        // step 1 - sort meetings by its stating time
        Arrays.sort(meetings, (a,b) -> Integer.compare(a[0], b[0]));

        long[] lastAvailable = new long[n];
        int[] usedRoomsCount = new int[n];

        // step 2 - process each meeting
        for(int[] meeting : meetings){
            int sTime = meeting[0];
            int eTime = meeting[1];
            int meetDuration = eTime - sTime;

            long earliestFreeTime = Long.MAX_VALUE;
            int earliestRoom = 0;

            // step 3 - find available room
            boolean roomAssigned = false;
            for(int r=0; r<n; r++){
                // check if room is free at meeting start time
                if(lastAvailable[r] <= sTime && !roomAssigned){
                    lastAvailable[r] = eTime;
                    usedRoomsCount[r]++;
                    roomAssigned = true;
                }

                // track room that becomes free earliest
                if(lastAvailable[r] < earliestFreeTime){
                    earliestFreeTime = lastAvailable[r];
                    earliestRoom = r;
                }
            }

            // step 4 - if no room was free, dealy meeting
            if(!roomAssigned){
                lastAvailable[earliestRoom] += meetDuration;
                usedRoomsCount[earliestRoom]++;
            }
        }

        // step 5 - find room with maximum usage and return it
        int resRoom = -1;
        int maxUse = 0;
        for(int r=0; r<n; r++){
            if(usedRoomsCount[r] > maxUse){
                maxUse = usedRoomsCount[r];
                resRoom = r;
            }
        }
        return resRoom;
    }

    public static void main(String[] args) {
        // int n = 2;
        // int[][] meetings = {{0,10},{1,5},{2,7},{3,4}};

        int n = 3;
        int[][] meetings = {{1,20},{2,10},{3,5},{4,9},{6,8}};
        System.out.println(mostBooked(n, meetings));
    }
}
