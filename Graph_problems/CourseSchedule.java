
// Problem link - https://leetcode.com/problems/course-schedule/description/

package Graph_problems;

import java.util.*;

public class CourseSchedule {
    // we will topological sort using BFS traversal
    private static boolean topologicalSort(List<List<Integer>> graph, int n, int[] indegreeArr){
        // using queue to perform BFS traversal
        Queue<Integer> queue = new LinkedList<>();

        // visited set to keep track of visited nodes/vertices
        Set<Integer> visited = new HashSet<>();

        // traverse the graph
        for(int i=0; i<n; i++){
            if(indegreeArr[i] == 0){
                // add all those nodes as start whose indegree is 0
                queue.add(i);
                visited.add(i);
            }
        }

        // counter 'count' to keep track of number visited nodes/vertices
        int count = 0;

        // traverse the queue till it is empty
        while(!queue.isEmpty()){
            int curr = queue.poll();
            count++;

            // traverse all the neighbours of the current node
            for(int neighbour : graph.get(curr)){
                // check if neighbour is not visited already
                if(!visited.contains(neighbour)){
                    // then decrement the indegree count
                    indegreeArr[neighbour]--;

                    // check if all the indegree (dependency) is 0 then
                    if(indegreeArr[neighbour] == 0){
                        // add it into the queue
                        queue.add(neighbour);
                        // and mark it as visited
                        visited.add(neighbour);
                    }
                }
            }
        }
        // return true if count is equal to the number of nodes/vertices in the graph
        return count == n;
    }

    public static boolean canFinish(int numCourses, int[][] prerequisites) {
        // create graph
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0; i<numCourses; i++){
            graph.add(new ArrayList<>());
        }

        // indegree array for each node/vertex of the graph
        int[] indegreeArr = new int[numCourses];

        // read prerequisites to fill the graph
        for(int[] curr : prerequisites){
            int a = curr[0];
            int b = curr[1];

            // a is dependent on b i.e, b ------> a
            graph.get(b).add(a);

            // now there is an incoming edge on a
            indegreeArr[a]++;
        }

        return topologicalSort(graph, numCourses, indegreeArr);
    }

    public static void main(String[] args) {
        int numCourses = 2;
        int[][] prerequisites = {{1, 0}};

        // int[][] prerequisites = {{1, 0}, {0, 1}};
        System.out.println(canFinish(numCourses, prerequisites));
    }
}