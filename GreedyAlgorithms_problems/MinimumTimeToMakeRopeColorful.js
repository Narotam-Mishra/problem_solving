
// Problem link - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

let minCost = function(colors, neededTime) {
    let n = colors.length;

    let minTime = 0, prevMax = 0;

    for (let i = 0; i < n; i++) {
        // for new balloon
        if (i > 0 && colors.charAt(i) != colors.charAt(i-1)) {
            prevMax = 0;
        }

        let curr = neededTime[i];

        minTime += Math.min(prevMax, curr);

        prevMax = Math.max(prevMax, curr);
    }

    return minTime;
};

// const colors = "abaac", neededTime = [1,2,3,4,5];

// const colors = "abc", neededTime = [1,2,3];

const colors = "aabaa", neededTime = [1,2,3,4,1];
console.log(minCost(colors, neededTime));