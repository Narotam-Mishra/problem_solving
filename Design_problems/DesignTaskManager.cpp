
// Problem link - https://leetcode.com/problems/design-task-manager/?envType=daily-question&envId=2025-09-18

#include<bits/stdc++.h>
using namespace std;

class TaskManager {
    // map for task id and its priority mapping
    unordered_map<int, int> taskPriorityMap;

    // pair of priority queue (max-heap) for priority and task id
    // for efficient retrival
    priority_queue<pair<int, int>> maxHeap;

    // map for task id and user id mapping
    unordered_map<int, int> taskUserMap;

public:
    TaskManager(vector<vector<int>>& tasks) {
        // for each task call add function
        for(auto &task : tasks){
            add(task[0], task[1], task[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        // add pair of task id and its priority in max heap
        maxHeap.push({priority, taskId});
        
        // store task id and priority mapping 
        taskPriorityMap[taskId] = priority;

        // store task id and user id mapping
        taskUserMap[taskId] = userId;
    }
    
    void edit(int taskId, int newPriority) {
        // add updated priority in maxHeap
        // remove the older priority later on
        maxHeap.push({newPriority, taskId});

        // update the new priority taskPriorityMap as well
        taskPriorityMap[taskId] = newPriority;
    }
    
    void rmv(int taskId) {
        // in order to remove the task, set its priority to -1
        taskPriorityMap[taskId] = -1;
    }
    
    int execTop() {
        // find task with highest priority 
        // and remove stale (old priority) as well
        while(!maxHeap.empty()){
            auto [currPriority, taskId] = maxHeap.top();

            // remove entry after retrival
            maxHeap.pop();

            // check if current priority is matching from updated priority
            if(currPriority == taskPriorityMap[taskId]){
                // set old priority to -1
                taskPriorityMap[taskId] = -1;

                // returned corresponding user
                return taskUserMap[taskId];
            }
        }

        // if task id not available return -1
        return -1;
    }
};

int main(){
    vector<vector<int>> initialTasks = {
        {1, 101, 10},  // userId=1, taskId=101, priority=10
        {2, 102, 20},  // userId=2, taskId=102, priority=20
        {3, 103, 15}   // userId=3, taskId=103, priority=15
    };
    
    TaskManager tm(initialTasks);
    
    cout << "Initial tasks added:" << endl;
    cout << "Task 101 (User 1, Priority 10)" << endl;
    cout << "Task 102 (User 2, Priority 20)" << endl;
    cout << "Task 103 (User 3, Priority 15)" << endl;
    
    // Execute top priority task
    cout << "\nExecuting top priority task:" << endl;
    int user = tm.execTop();
    cout << "User ID: " << user << " (should be 2, highest priority 20)" << endl;
    
    // Add a new task
    tm.add(4, 104, 25);
    cout << "\nAdded Task 104 (User 4, Priority 25)" << endl;
    
    // Execute top priority task
    cout << "Executing top priority task:" << endl;
    user = tm.execTop();
    cout << "User ID: " << user << " (should be 4, highest priority 25)" << endl;
    
    // Edit a task's priority
    tm.edit(101, 30);
    cout << "\nEdited Task 101 priority to 30" << endl;
    
    // Execute top priority task
    cout << "Executing top priority task:" << endl;
    user = tm.execTop();
    cout << "User ID: " << user << " (should be 1, highest priority 30)" << endl;
    
    // Remove a task
    tm.rmv(103);
    cout << "\nRemoved Task 103" << endl;
    
    // Execute remaining task
    cout << "Executing remaining task:" << endl;
    user = tm.execTop();
    cout << "User ID: " << user << " (should be -1, no tasks left or task was removed)" << endl;
    
    return 0;
}