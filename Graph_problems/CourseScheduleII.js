
// Problem link - https://leetcode.com/problems/course-schedule-ii/description/

function topologicalSort(graph, n, indegreeArr){
    // we will topological sort using BFS traversal
    // hence we will use array as queue
    let queue = [];

    // visted set to keep track of visited node
    let visited = new Set();

    // traverse the graph
    for(let i=0; i<n; i++){
        if(indegreeArr[i] === 0){
            // add all those nodes as start whose indegree is 0
            queue.push(i);
            visited.add(i);
        }
    }

    // counter 'count' to keep track of number visited nodes/vertices
    let count = 0;
    
    // array to store ordering of courses
    let res = [];

    // traverse the queue till it is empty
    while(queue.length > 0){
        let curr = queue.shift();
        count++;
        res.push(curr);
        // traverse all the neighbours of current node
        for(const neighbour of graph[curr]){
            if(!visited.has(neighbour)){
                // if neighbour is not vsisted already
                indegreeArr[neighbour]--;
                // if all the indegree (dependency) is 0 then 
                if(indegreeArr[neighbour] === 0){
                    // we are good to add it in queue
                    queue.push(neighbour);
                    // and mark it visited also
                    visited.add(neighbour);
                }
            }
        }
    }

    return count === n ? res : [];

}

let findOrder = function(numCourses, prerequisites) {
    // create graph
    let g = new Array(numCourses);
    for(let i=0; i<numCourses; i++){
        g[i] = new Array();
    }

    // indegree array for each node/vertex of graph
    let indegreeArr = new Array(numCourses).fill(0);

    // read prerequisites to fill graph
    for(let i=0; i<prerequisites.length; i++){
        const curr = prerequisites[i];
        const a = curr[0];
        const b = curr[1];
        // a is dependent on b : b ------> a
        g[b].push(a);
        // now there is an incoming edge on a
        indegreeArr[a]++;
    }

    return topologicalSort(g, numCourses, indegreeArr);
};

let numCourses = 2, prerequisites = [[1,0]];
console.log(findOrder(numCourses, prerequisites));