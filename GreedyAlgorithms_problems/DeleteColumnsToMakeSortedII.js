
// Problem link - https://leetcode.com/problems/delete-columns-to-make-sorted-ii/?envType=daily-question&envId=2025-12-21

let minDeletionSize = function (strs) {
    // find row and column size
    const r = strs.length;
    const c = strs[0].length;

    // keep track of already sorted column
    // this is to avoid unnecessary deletion
    const alreadySorted = new Array(r).fill(false);

    // step 1 - process columns left to right
    let deletionCount = 0;
    for (let col = 0; col < c; col++) {
        let deleted = false;

        // step 2 - check if current column violates order
        for (let row = 0; row < r - 1; row++) {
            if (!alreadySorted[row] && strs[row].charAt(col) > strs[row + 1].charAt(col)) {
                // must delete this column
                deletionCount++;
                deleted = true;
                break;
            }
        }

        // skip marking sorted pair if column was already deleted
        if (deleted) continue;

        // step 3 - update which pairs are now confirmed sorted
        for (let i = 0; i < r - 1; i++) {
            alreadySorted[i] = alreadySorted[i] | (strs[i].charAt(col) < strs[i + 1].charAt(col));
        }
    }

    // step 4 - return minimum deletion count
    return deletionCount;
};

// const strs = ["ca","bb","ac"];

// const strs = ["xc","yb","za"];

const strs = ["zyx","wvu","tsr"];
console.log(minDeletionSize(strs));