
// Problem link - https://leetcode.com/problems/power-grid-maintenance/?envType=daily-question&envId=2025-11-06

/**
 * Utility function to perform DFS and assign component IDs to nodes
 */
function dfs(currentNode, graph, componentId, nodeToComponentId, componentToOnlineNodes, visited) {
    // mark current node as visited
    visited[currentNode] = true;
    
    // assign component ID to this node
    nodeToComponentId[currentNode] = componentId;
    
    // add this node to the set of online nodes in this component
    if(!componentToOnlineNodes.has(componentId)) {
        componentToOnlineNodes.set(componentId, new Set());
    }
    componentToOnlineNodes.get(componentId).add(currentNode);
    
    // recursively visit all unvisited neighbors
    if(graph.has(currentNode)) {
        for(const neighbor of graph.get(currentNode)) {
            if(!visited[neighbor]) {
                dfs(neighbor, graph, componentId, nodeToComponentId, componentToOnlineNodes, visited);
            }
        }
    }
}

let processQueries = function(c, connections, queries) {
    // step 1 - Build adjacency list representation of the graph
    const graph = new Map();
    for(const [station1, station2] of connections) {
        if(!graph.has(station1)) graph.set(station1, []);
        if(!graph.has(station2)) graph.set(station2, []);
        
        graph.get(station1).push(station2);
        graph.get(station2).push(station1);
    }
    
    // maps each component ID to Set of online nodes in that component
    const componentToOnlineNodes = new Map();
    
    // step 2 - find connected components using DFS
    const visited = new Array(c + 1).fill(false);
    const nodeToComponentId = new Array(c + 1);
    
    for(let station = 1; station <= c; station++) {
        if(!visited[station]) {
            // Use the first node in component as component ID
            const componentId = station;
            dfs(station, graph, componentId, nodeToComponentId, componentToOnlineNodes, visited);
        }
    }
    
    // step 3 - process queries and build result
    const res = [];
    for(const [queryType, station] of queries) {
        if(queryType === 1) {
            // type 1: Maintenance check query
            const componentId = nodeToComponentId[station];
            const onlineNodes = componentToOnlineNodes.get(componentId);
            
            // check if station itself is online
            if(onlineNodes && onlineNodes.has(station)) {
                res.push(station);
            }
            // find smallest online station in same component
            else if(onlineNodes && onlineNodes.size > 0) {
                // Convert Set to sorted array and get smallest
                const smallestOnlineStation = Math.min(...onlineNodes);
                res.push(smallestOnlineStation);
            }
            // no online station in this component
            else {
                res.push(-1);
            }
        }
        else {
            // type 2: Take station offline
            const componentId = nodeToComponentId[station];
            const onlineNodes = componentToOnlineNodes.get(componentId);
            if(onlineNodes) {
                onlineNodes.delete(station);
            }
        }
    }
    
    // step 4 - return final result, res
    return res;
};

// const c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]];

const c = 3, connections = [], queries = [[1,1],[2,1],[1,1]];
console.log(processQueries(c, connections, queries));