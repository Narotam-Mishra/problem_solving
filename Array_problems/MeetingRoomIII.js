
// Problem link - https://leetcode.com/problems/meeting-rooms-iii/description/?envType=daily-question&envId=2025-12-27

let mostBooked = function(n, meetings) {
    // step 1 - sort meetings by start time
    meetings.sort((a, b) => a[0] - b[0]);

    let lastAvailable = new Array(n).fill(0);
    let roomsUsedCount = new Array(n).fill(0);

    // step 2 - Process each meeting
    for (let [start, end] of meetings) {
        let duration = end - start;

        let earliestFreeTime = Infinity;
        let earliestRoom = 0;
        let roomAssigned = false;

        // step 3 - find available room
        for (let r = 0; r < n; r++) {
            if (lastAvailable[r] <= start && !roomAssigned) {
                lastAvailable[r] = end;
                roomsUsedCount[r]++;
                roomAssigned = true;
            }

            if (lastAvailable[r] < earliestFreeTime) {
                earliestFreeTime = lastAvailable[r];
                earliestRoom = r;
            }
        }

        // step 4 - delay meeting if no room free
        if (!roomAssigned) {
            lastAvailable[earliestRoom] += duration;
            roomsUsedCount[earliestRoom]++;
        }
    }

    // step 5 - Find most used room and return it
    let resRoom = 0;
    for (let r = 1; r < n; r++) {
        if (roomsUsedCount[r] > roomsUsedCount[resRoom]) {
            resRoom = r;
        }
    }

    return resRoom;
};

// const n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]];

const n = 3, meetings = [[1,20],[2,10],[3,5],[4,9],[6,8]];
console.log(mostBooked(n, meetings));