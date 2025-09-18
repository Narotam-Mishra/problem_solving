
// Problem link - https://leetcode.com/problems/design-task-manager/?envType=daily-question&envId=2025-09-18

package Design_problems;

import java.util.*;

class TaskManager {
    // map for task id and its priority mapping
    private Map<Integer, Integer> taskPriorityMap;

    // pair of priority queue (max-heap) for priority and task id
    // for efficient retrieval
    private PriorityQueue<int[]> maxHeap;

    // map for task id and user id mapping
    private Map<Integer, Integer> taskUserMap;

    public TaskManager(List<List<Integer>> tasks) {
        // initialize data structures
        taskPriorityMap = new HashMap<>();
        taskUserMap = new HashMap<>();

        // max heap: compare by priority (index 0), then by task id (index 1) for tie-breaking
        maxHeap = new PriorityQueue<>((a, b) -> {
            // highest priority first
            if(a[0] != b[0]) return Integer.compare(b[0], a[0]);

            // if priority are same then return higher task id
            return Integer.compare(b[1], a[1]);
        });

        // for each task call add method 
        for(List<Integer> task : tasks){
            add(task.get(0), task.get(1), task.get(2));
        }
    }
    
    public void add(int userId, int taskId, int priority) {
        // add pair of priority and task id in max heap
        maxHeap.offer(new int[]{priority, taskId});

        // store task id and priority mapping
        taskPriorityMap.put(taskId, priority);

        // store task id and user id mapping
        taskUserMap.put(taskId, userId);
    }
    
    public void edit(int taskId, int newPriority) {
        // add updated priority in maxHeap
        // remove the older priority later on
        maxHeap.offer(new int[]{newPriority, taskId});

        // update new priority in taskPriorityMap
        taskPriorityMap.put(taskId, newPriority);
    }
    
    public void rmv(int taskId) {
        // in order to remove the task, set its priority to -1
        taskPriorityMap.put(taskId, -1);
    }
    
    public int execTop() {
        // find get task with highest priority
        // and remove stale (old priority) as well
        while (!maxHeap.isEmpty()) {
            int[] pair = maxHeap.poll();
            int currPriority = pair[0];
            int taskId = pair[1];

            // check if current priority is matching from updated priority
            if(currPriority == taskPriorityMap.get(taskId)){
                // set old priority to -1
                taskPriorityMap.put(taskId, -1);

                // return corresponding user id
                return taskUserMap.get(taskId);
            }
        }

        // if task id not available return -1
        return -1;
    }
}

public class DesignTaskManager {
    public static void main(String[] args) {
        // Test the TaskManager
        List<List<Integer>> initialTasks = Arrays.asList(
            Arrays.asList(1, 101, 10),  // userId=1, taskId=101, priority=10
            Arrays.asList(2, 102, 20),  // userId=2, taskId=102, priority=20
            Arrays.asList(3, 103, 15)   // userId=3, taskId=103, priority=15
        );
        
        TaskManager tm = new TaskManager(initialTasks);
        
        System.out.println("Initial tasks added:");
        System.out.println("Task 101 (User 1, Priority 10)");
        System.out.println("Task 102 (User 2, Priority 20)");
        System.out.println("Task 103 (User 3, Priority 15)");
        
        // Execute top priority task
        System.out.println("\nExecuting top priority task:");
        int user = tm.execTop();
        System.out.println("User ID: " + user + " (should be 2, highest priority 20)");
        
        // Add a new task
        tm.add(4, 104, 25);
        System.out.println("\nAdded Task 104 (User 4, Priority 25)");
        
        // Execute top priority task
        System.out.println("Executing top priority task:");
        user = tm.execTop();
        System.out.println("User ID: " + user + " (should be 4, highest priority 25)");
        
        // Edit a task's priority
        tm.edit(101, 30);
        System.out.println("\nEdited Task 101 priority to 30");
        
        // Execute top priority task
        System.out.println("Executing top priority task:");
        user = tm.execTop();
        System.out.println("User ID: " + user + " (should be 1, highest priority 30)");
        
        // Remove a task
        tm.rmv(103);
        System.out.println("\nRemoved Task 103");
        
        // Execute remaining task
        System.out.println("Executing remaining task:");
        user = tm.execTop();
        System.out.println("User ID: " + user + " (should be -1, no tasks left or task was removed)");
    }
}
