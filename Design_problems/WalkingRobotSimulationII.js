
// Problem link - https://leetcode.com/problems/walking-robot-simulation-ii/?envType=daily-question&envId=2026-04-07

let Robot = function(width, height) {
    this.pos = [];
    this.idx = 0;
    this.moved = false;

    // Bottom row (left to right) → East (0)
    for (let x = 0; x < width; x++)
        this.pos.push([x, 0, 0]);

    // Right column (bottom to top) → North (1)
    for (let y = 1; y < height; y++)
        this.pos.push([width - 1, y, 1]);

    // Top row (right to left) → West (2)
    for (let x = width - 2; x >= 0; x--)
        this.pos.push([x, height - 1, 2]);

    // Left column (top to bottom) → South (3)
    for (let y = height - 2; y > 0; y--)
        this.pos.push([0, y, 3]);

    // corner case: when returning to (0,0), direction should be South
    this.pos[0][2] = 3;
};

/** 
 * @param {number} num
 * @return {void}
 */
Robot.prototype.step = function(num) {
    this.moved = true;
    this.idx = (this.idx + num) % this.pos.length;
};

/**
 * @return {number[]}
 */
Robot.prototype.getPos = function() {
    return [this.pos[this.idx][0], this.pos[this.idx][1]];
};

/**
 * @return {string}
 */
Robot.prototype.getDir = function() {
    if (!this.moved) return "East";

    const dir = this.pos[this.idx][2];

    if (dir === 0) return "East";
    if (dir === 1) return "North";
    if (dir === 2) return "West";
    return "South";
};


// ---- Test ----
// ["Robot", "step", "step", "getPos", "getDir", "step", "step", "step", "getPos", "getDir"]
// [[6, 3],  [2],    [2],    [],        [],       [2],    [1],    [4],    [],        []      ]

const obj = new Robot(6, 3);

obj.step(2);
obj.step(2);
console.log("getPos:", obj.getPos()); // [4, 0]
console.log("getDir:", obj.getDir()); // East

obj.step(2);
obj.step(1);
obj.step(4);
console.log("getPos:", obj.getPos()); // [1, 2]
console.log("getDir:", obj.getDir()); // West