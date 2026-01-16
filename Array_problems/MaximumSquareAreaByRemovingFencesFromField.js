
// Problem link - https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/description/?envType=daily-question&envId=2026-01-16

let maximizeSquareArea = function(m, n, hFences, vFences) {
    const mod = 1e9 + 7;

    // step 1 - insert 1 to hFences & vFences to find all widths
    vFences.push(1);
    vFences.push(n);

    hFences.push(1);
    hFences.push(m);

    // sort both fences
    hFences.sort((a, b) => a - b);
    vFences.sort((a, b) => a - b);

    // step 2 - find all widths for vFences
    const widths = new Set();
    for (let i = 0; i < vFences.length; i++) {
        for (let j = i + 1; j < vFences.length; j++) {
            const w = vFences[j] - vFences[i];
            widths.add(w);
        }
    }
    
    // step 3 - find all heights for hFences
    let maxSide = 0;
    for (let i = 0; i < hFences.length; i++) {
        for (let j = i + 1; j < hFences.length; j++) {
            const h = hFences[j] - hFences[i];
            if (widths.has(h)) {
                maxSide = Math.max(maxSide, h);
            }
        }
    }

    // step 4 - return area using maximum side
    return maxSide === 0 ? -1 : (maxSide * maxSide) % mod;
};

// const m = 4, n = 3, hFences = [2,3], vFences = [2];

const m = 6, n = 7, hFences = [2], vFences = [4];
console.log(maximizeSquareArea(m,n,hFences,vFences));