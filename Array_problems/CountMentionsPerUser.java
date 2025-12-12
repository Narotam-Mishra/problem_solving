
// Problem link - https://leetcode.com/problems/count-mentions-per-user/description/?envType=daily-question&envId=2025-12-12

package Array_problems;

import java.util.*;

public class CountMentionsPerUser {
    private static void performMessageEvent(List<String> event, int[] mentionCount, int[] offlineTime) {
        int timestamp = Integer.parseInt(event.get(1));
        String[] ids = event.get(2).split(" ");

        for (String id : ids) {
            if(id.equals("ALL")) {
                // Mention all users
                for (int i = 0; i < mentionCount.length; i++) {
                    mentionCount[i]++;
                }
            } else if (id.equals("HERE")) {
                // Mention only online users
                for (int i = 0; i < mentionCount.length; i++) {
                    if (offlineTime[i] == 0 || offlineTime[i] + 60 <= timestamp) {
                        mentionCount[i]++;
                    }
                }
            } else {
                // idX → extract X
                int userId = Integer.parseInt(id.substring(2));
                mentionCount[userId]++;
            }
        }
    }

    public static int[] countMentions(int numberOfUsers, List<List<String>> events) {
        int[] mentionCount = new int[numberOfUsers];
        int[] offlineTime = new int[numberOfUsers];

        // Sort events
        Collections.sort(events, (a, b) -> {
            int t1 = Integer.parseInt(a.get(1));
            int t2 = Integer.parseInt(b.get(1));

            if (t1 == t2) {
                // Offline should come first if timestamps tie
                return a.get(0).charAt(1) > b.get(0).charAt(1) ? -1 : 1;
            }
            return Integer.compare(t1, t2);
        });

        // Process events
        for (List<String> event : events) {
            if (event.get(0).equals("MESSAGE")) {
                performMessageEvent(event, mentionCount, offlineTime);
            } else if (event.get(0).equals("OFFLINE")) {
                int ts = Integer.parseInt(event.get(1));
                int id = Integer.parseInt(event.get(2));
                offlineTime[id] = ts;
            }
        }

        return mentionCount;
    }

    public static void main(String[] args) {
        // int numberOfUsers = 2;
        // List<List<String>> events = Arrays.asList(
        //     Arrays.asList("MESSAGE", "10", "id1 id0"),
        //     Arrays.asList("OFFLINE", "11", "0"),
        //     Arrays.asList("MESSAGE", "71", "HERE")
        // );

        // int numberOfUsers = 2;
        // List<List<String>> events = Arrays.asList(
        //     Arrays.asList("MESSAGE", "10", "id1 id0"),
        //     Arrays.asList("OFFLINE", "11", "0"),
        //     Arrays.asList("MESSAGE", "12", "ALL")
        // );

        int numberOfUsers = 2;
        List<List<String>> events = Arrays.asList(
            Arrays.asList("OFFLINE", "10", "0"),
            Arrays.asList("MESSAGE", "12", "HERE")
        );
        int[] result = countMentions(numberOfUsers, events);
        System.out.println(Arrays.toString(result));
    }
}
