
// Problem link - https://leetcode.com/problems/find-all-people-with-secret/

let findAllPeople = function(n, meetings, firstPerson) {
    // step 1 - mark people who initially know the secret
    const knowSecret = new Array(n).fill(false);
    knowSecret[0] = true;
    knowSecret[firstPerson] = true;

    // step 2 - map time -> list of meetings (sorted by time)
    const timeMeetingsMap = new Map();

    for (const [p1, p2, time] of meetings) {
        if (!timeMeetingsMap.has(time)) {
            timeMeetingsMap.set(time, []);
        }
        timeMeetingsMap.get(time).push([p1, p2]);
    }

    // sort times in ascending order
    const sortedTimes = [...timeMeetingsMap.keys()].sort((a, b) => a - b);

    // step 3 - process each time group
    for (const time of sortedTimes) {
        const meets = timeMeetingsMap.get(time);

        // step 4 - build graph for current time
        const adjList = new Map();
        const queue = [];
        const visited = new Set();

        for (const [p1, p2] of meets) {
            if (!adjList.has(p1)) adjList.set(p1, []);
            if (!adjList.has(p2)) adjList.set(p2, []);

            adjList.get(p1).push(p2);
            adjList.get(p2).push(p1);

            // add people who already know secret
            if (knowSecret[p1] && !visited.has(p1)) {
                queue.push(p1);
                visited.add(p1);
            }

            if (knowSecret[p2] && !visited.has(p2)) {
                queue.push(p2);
                visited.add(p2);
            }
        }

        // step 5 - BFS to spread secret
        while (queue.length > 0) {
            const person = queue.shift();

            for (const next of adjList.get(person) || []) {
                if (!knowSecret[next]) {
                    knowSecret[next] = true;
                    queue.push(next);
                }
            }
        }
    }

    // step 6 - build result
    const res = [];
    for (let i = 0; i < n; i++) {
        if (knowSecret[i]) {
            res.push(i);
        }
    }

    return res;
};

// const n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1;

// const n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3;

const n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1;
console.log(findAllPeople(n, meetings, firstPerson));