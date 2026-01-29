
// Problem link - https://leetcode.com/problems/minimum-cost-to-convert-string-i/description/?envType=daily-question&envId=2026-01-29

function applyFloydWarshall(adjMatrix, original, changed, cost) {
    // Populate adjacency matrix
    for (let i = 0; i < original.length; i++) {
        const src = original[i].charCodeAt(0) - 97;
        const tar = changed[i].charCodeAt(0) - 97;
        adjMatrix[src][tar] = Math.min(adjMatrix[src][tar], cost[i]);
    }

    // Floyd–Warshall
    for (let k = 0; k < 26; k++) {
        for (let i = 0; i < 26; i++) {
            for (let j = 0; j < 26; j++) {
                if (adjMatrix[i][k] < Number.MAX_SAFE_INTEGER &&
                    adjMatrix[k][j] < Number.MAX_SAFE_INTEGER) {
                    adjMatrix[i][j] = Math.min(
                        adjMatrix[i][j],
                        adjMatrix[i][k] + adjMatrix[k][j]
                    );
                }
            }
        }
    }
}

let minimumCost = function (source, target, original, changed, cost) {
    const INF = Number.MAX_SAFE_INTEGER;

    // Initialize adjacency matrix
    const adjMatrix = Array.from({ length: 26 }, () =>
        Array(26).fill(INF)
    );

    applyFloydWarshall(adjMatrix, original, changed, cost);

    let ans = 0;
    for (let i = 0; i < source.length; i++) {
        if (source[i] === target[i]) continue;

        const s = source.charCodeAt(i) - 97;
        const t = target.charCodeAt(i) - 97;

        if (adjMatrix[s][t] === INF) return -1;

        ans += adjMatrix[s][t];
    }

    return ans;
};

const source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20];
console.log(minimumCost(source, target, original, changed, cost));