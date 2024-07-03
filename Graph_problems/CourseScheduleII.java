
// Problem link - https://leetcode.com/problems/course-schedule-ii/description/

package Graph_problems;

import java.util.*;

public class CourseScheduleII {
    // we will topological sort using BFS traversal
    private static int[] topologicalSort(List<Integer>[] graph, int n, int[] indegreeArr){
        // using queue to perform BFS traversal
        Queue<Integer> queue = new LinkedList<>();

        // visited set to keep track of visited nodes/vertices
        Set<Integer> visited = new HashSet<>();

        // traverse the graph
        for(int i=0; i<n; i++){
            if(indegreeArr[i] == 0){
                // add all those nodes as start whose indegree is 0
                queue.offer(i);
                visited.add(i);
            }
        }

        // counter 'count' to keep track of number visited nodes/vertices
        int count = 0;

        // array to store ordering of courses
        int[] res = new int[n];
        int index = 0;

        // traverse the queue till it is empty
        while(!queue.isEmpty()){
            int curr = queue.poll();
            count++;
            res[index++] = curr;

            // traverse all the neighbours of the current node
            for(int neighbour : graph[curr]){
                // check if neighbour is not visited already
                if(!visited.contains(neighbour)){
                    // then decrement the indegree count
                    indegreeArr[neighbour]--;

                    // check if all the indegree (dependency) is 0 then
                    if(indegreeArr[neighbour] == 0){
                        // add it into the queue
                        queue.offer(neighbour);
                        // and mark it as visited
                        visited.add(neighbour);
                    }
                }
            }
        }
        return count == n ? res : new int[0];
    }

    public static int[] findOrder(int numCourses, int[][] prerequisites) {
        // create graph
        @SuppressWarnings("unchecked")
        List<Integer>[] graph = new ArrayList[numCourses];
        for(int i=0; i<numCourses; i++){
            graph[i] = new ArrayList<>();
        }

        // indegree array for each node/vertex of the graph
        int[] indegreeArr = new int[numCourses];

        // read prerequisites to fill the graph
        for(int[] curr : prerequisites){
            int a = curr[0];
            int b = curr[1];

            // a is dependent on b i.e, b ------> a
            graph[b].add(a);

            // now there is an incoming edge on a
            indegreeArr[a]++;
        }

        return topologicalSort(graph, numCourses, indegreeArr);
    }
    
    public static void main(String[] args) {
        int numCourses = 4;
        int[][] prerequisites = { {1, 0}, {2, 0}, {3, 1}, {3, 2} };
        int[] order = findOrder(numCourses, prerequisites);
        System.out.println(Arrays.toString(order));
    }
}