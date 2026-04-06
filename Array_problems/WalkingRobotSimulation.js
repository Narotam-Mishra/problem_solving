
// Problem link - https://leetcode.com/problems/walking-robot-simulation/description/?envType=daily-question&envId=2026-04-06

let robotSim = function(commands, obstacles) {
    // Step 1 - Set to access obstacles quickly
    const st = new Set();
    for (const obs of obstacles) {
        st.add(`${obs[0]}_${obs[1]}`);
    }

    // Start simulation
    let x = 0, y = 0;
    let maxDistance = 0;

    // Pointing to North dir
    let dir = [0, 1];

    // Step 2 - Move through each command
    for (const cmd of commands) {
        if (cmd === -2) {
            // Turn left 90 degrees
            dir = [-dir[1], dir[0]];
        } else if (cmd === -1) {
            // Turn right 90 degrees
            dir = [dir[1], -dir[0]];
        } else {
            // Move in the direction step by step
            for (let s = 0; s < cmd; s++) {
                const newX = x + dir[0];
                const newY = y + dir[1];

                // Check if newX & newY is part of obstacles
                if (st.has(`${newX}_${newY}`)) break;

                x = newX;
                y = newY;
            }
        }

        // Step 3 - Update maximum distance
        maxDistance = Math.max(maxDistance, x * x + y * y);
    }

    // Step 4 - Return final maximum distance
    return maxDistance;
};

// const commands = [4,-1,3], obstacles = [];

// const commands = [4,-1,4,-2,4], obstacles = [[2,4]];

const commands = [6,-1,-1,6], obstacles = [[0,0]];
console.log(robotSim(commands, obstacles));