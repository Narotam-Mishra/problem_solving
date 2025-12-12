
// Problem link - https://leetcode.com/problems/count-mentions-per-user/?envType=daily-question&envId=2025-12-12

function performMessageEvent(event, mentionCount, offlineTime) {
    const timestamp = Number(event[1]);
    const ids = event[2].split(" ");

    for (let id of ids) {
        if (id === "ALL") {
            for (let i = 0; i < mentionCount.length; i++) {
                mentionCount[i]++;
            }
        } else if (id === "HERE") {
            for (let i = 0; i < mentionCount.length; i++) {
                if (offlineTime[i] === 0 || offlineTime[i] + 60 <= timestamp) {
                    mentionCount[i]++;
                }
            }
        } else {
            const userId = Number(id.substring(2)); // idX → X
            mentionCount[userId]++;
        }
    }
}

let countMentions = function(numberOfUsers, events) {
    const mentionCount = new Array(numberOfUsers).fill(0);
    const offlineTime = new Array(numberOfUsers).fill(0);

    // step 1 - sort events
    events.sort((a, b) => {
        const t1 = Number(a[1]);
        const t2 = Number(b[1]);

        if (t1 === t2) {
            // offline should come first in tie (same logic as C++)
            return a[0][1] > b[0][1] ? -1 : 1;
        }
        return t1 - t2;
    });

    // step 2 - process events
    for (let event of events) {
        if (event[0] === "MESSAGE") {
            performMessageEvent(event, mentionCount, offlineTime);
        } else if (event[0] === "OFFLINE") {
            const timestamp = Number(event[1]);
            const id = Number(event[2]);
            offlineTime[id] = timestamp;
        }
    }

    // step 3 - return final result
    return mentionCount;
}


// const numberOfUsers = 2;
// const events = [
//     ["OFFLINE", "10", "0"],
//     ["MESSAGE", "12", "HERE"]
// ];

// const numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","71","HERE"]];

const numberOfUsers = 2, events = [["MESSAGE","10","id1 id0"],["OFFLINE","11","0"],["MESSAGE","12","ALL"]];

console.log(countMentions(numberOfUsers, events));
