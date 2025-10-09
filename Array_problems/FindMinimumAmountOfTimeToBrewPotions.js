
// Problem link - https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/?envType=daily-question&envId=2025-10-09

let minTime = function(skill, mana) {
    // find size of skill and mana
    const n = skill.length;
    const m = mana.length;
    
    // track when each wizard finishes their current work
    const finishTime = new Array(n).fill(0);
    
    // step 1 - process each potion sequentially
    for(let j = 0; j < m; j++) {
        // step 2 - first wizard starts immediately after finishing previous potion
        finishTime[0] += mana[j] * skill[0];
        
        // step 3 - each wizard starts when both they and previous wizard are ready
        for(let i = 1; i < n; i++) {
            finishTime[i] = Math.max(finishTime[i], finishTime[i-1]) + mana[j] * skill[i];
        }
        
        // step 4 - synchronize timing so potion flows smoothly
        for(let i = n - 1; i > 0; i--) {
            finishTime[i-1] = finishTime[i] - mana[j] * skill[i];
        }
    }
    
    // step 5 - last wizard's finish time is the total time needed
    return finishTime[n-1];
};

// const skill = [1,5,2,4], mana = [5,1,4,2];

// const skill = [1,1,1], mana = [1,1,1];

const skill = [1,2,3,4], mana = [1,2];
console.log(minTime(skill, mana));