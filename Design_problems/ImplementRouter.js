
// Problem link - https://leetcode.com/problems/implement-router/?envType=daily-question&envId=2025-09-20

/**
 * @param {number} memoryLimit
 */
let Router = function(memoryLimit) {
    this.max_size = memoryLimit;

    // map for packet mapping: key -> [source, destination, timestamp]
    this.packetMap = new Map();

    // queue for storage and forwarding the next packet
    this.packetQueue = [];

    // map for destination and timestamp mapping
    this.desTimeMap = new Map();
};

/** 
 * @param {number} source 
 * @param {number} destination 
 * @param {number} timestamp
 * @return {boolean}
 */
Router.prototype.addPacket = function(source, destination, timestamp) {
    let key = `${source}_${destination}_${timestamp}`;

    // check if current packet already exists
    if (this.packetMap.has(key)) {
        return false;
    }

    // check if queue size exceeded the maximum size
    if (this.packetQueue.length >= this.max_size) {
        this.forwardPacket();
    }

    // add to packetMap
    this.packetMap.set(key, [source, destination, timestamp]);

    // add to queue
    this.packetQueue.push(key);

    // add timestamp to desTimeMap
    if (!this.desTimeMap.has(destination)) {
        this.desTimeMap.set(destination, []);
    }
    this.desTimeMap.get(destination).push(timestamp);

    return true;
};

/**
 * @return {number[]}
 */
Router.prototype.forwardPacket = function() {
    if (this.packetMap.size === 0) {
        return [];
    }

    let key = this.packetQueue.shift(); // remove oldest
    let packet = this.packetMap.get(key);
    this.packetMap.delete(key);

    let destination = packet[1];
    let timestamps = this.desTimeMap.get(destination);
    if (timestamps && timestamps.length > 0) {
        timestamps.shift(); // remove oldest timestamp
    }

    return packet;
};

/** 
 * @param {number} destination 
 * @param {number} startTime 
 * @param {number} endTime
 * @return {number}
 */
Router.prototype.getCount = function(destination, startTime, endTime) {
    let timestamps = this.desTimeMap.get(destination);

    if (!timestamps || timestamps.length === 0) {
        return 0;
    }

    // binary search helpers
    function lowerBound(arr, target) {
        let lo = 0, hi = arr.length;
        while (lo < hi) {
            let mid = Math.floor((lo + hi) / 2);
            if (arr[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    function upperBound(arr, target) {
        let lo = 0, hi = arr.length;
        while (lo < hi) {
            let mid = Math.floor((lo + hi) / 2);
            if (arr[mid] <= target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }

    let s = lowerBound(timestamps, startTime);
    let e = upperBound(timestamps, endTime);

    return e - s;
};

/* ---------------- MAIN RUNNER FUNCTION ---------------- */
function main() {
    let router = new Router(3); // memory limit = 3

    console.log(router.addPacket(1, 2, 5)); // true
    console.log(router.addPacket(2, 3, 10)); // true
    console.log(router.addPacket(1, 2, 15)); // true
    console.log(router.addPacket(3, 4, 20)); // true (oldest removed)

    console.log("Forwarded:", router.forwardPacket()); // should forward oldest
    console.log("Count [dest=2, 5-20]:", router.getCount(2, 5, 20)); // count packets to dest=2 between 5-20
    console.log("Count [dest=3, 1-15]:", router.getCount(3, 1, 15)); // count packets to dest=3
}

main();
