
// Problem link - https://leetcode.com/problems/find-all-people-with-secret/description/

package Graph_problems;

import java.util.*;

public class FindAllPeopleWithSecret {
    public static List<Integer> findAllPeople(int n, int[][] meetings, int firstPerson) {
        // step 1 - mark people who initially know the secret
        boolean[] knowSecret = new boolean[n];
        knowSecret[0] = true;
        knowSecret[firstPerson] = true;

        // step 2 - map time -> with list of meetings at that time
        // where time should be sorted in ascending order
        TreeMap<Integer, List<int[]>> timeMeetingsMap = new TreeMap<>();
        for(int[] meeting : meetings){
            int p1 = meeting[0];
            int p2 = meeting[1];
            int time = meeting[2];

            // populate map
            timeMeetingsMap.computeIfAbsent(time, k -> new ArrayList<>())
            .add(new int[]{p1, p2});
        }

        // step 3 - process meeting time by time
        for(Map.Entry<Integer, List<int[]>> entry : timeMeetingsMap.entrySet()){
            List<int[]> meets = entry.getValue();

            // step 4 - build graph for current time using Adjacency list
            Map<Integer, List<Integer>> adjList = new HashMap<>();
            Queue<Integer> queue = new LinkedList<>();
            Set<Integer> visited = new HashSet<>();

            for(int[] meet : meets){
                int p1 = meet[0];
                int p2 = meet[1];

                // bidirectional graph
                adjList.computeIfAbsent(p1, k -> new ArrayList<>()).add(p2);
                adjList.computeIfAbsent(p2, k -> new ArrayList<>()).add(p1);

                // add people who already know secret into BFS queue
                if(knowSecret[p1] && !visited.contains(p1)){
                    queue.offer(p1);
                    visited.add(p1);
                }

                if(knowSecret[p2] && !visited.contains(p2)){
                    queue.offer(p2);
                    visited.add(p2);
                }
            }

            // step 5 - spread secret by performing BFS traversal on graph
            while(!queue.isEmpty()){
                int person = queue.poll();

                if(adjList.containsKey(person)){
                    for(int nextPerson : adjList.get(person)){
                        if(!knowSecret[nextPerson]){
                            knowSecret[nextPerson] = true;
                            queue.offer(nextPerson);
                        }
                    }
                }
            }
        }

        // step 6 - form result list, `res` and return it
        List<Integer> res = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(knowSecret[i]){
                res.add(i);
            }
        }
        return res;
    }

    public static void main(String[] args) {
        // int n = 6;
        // int[][] meetings = {{1,2,5},{2,3,8},{1,5,10}};
        // int firstPerson = 1;

        // int n = 4;
        // int[][] meetings = {{3,1,3},{1,2,2},{0,3,3}};
        // int firstPerson = 3;

        int n = 5;
        int[][] meetings = {{3,4,2},{1,2,1},{2,3,1}};
        int firstPerson = 1;
        List<Integer> res = findAllPeople(n, meetings, firstPerson);
        System.out.println(res);
    }
}
