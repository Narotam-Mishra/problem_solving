/*

list1 = [[1,1,1], [1,1,1]]
list2 = [[0,0,0], [0,0,0]]

[[1,0,1,0,1,0],[0,1,0,1,0,1]]

*/

function interleaveLists(list1, list2) {
    // Ensure both lists have the same dimensions
    if (!areListsSameDimensions(list1, list2)) {
        console.error('Input lists must have the same dimensions');
        return;
    }

    // Initialize the result list
    const resultList = [];

    // Interleave elements from list1 and list2

    let flag = true;
    for (let i = 0; i < list1.length; i++) {
        const interleavedRow = [];
        for (let j = 0; j < list1[i].length; j++) {
            if (flag === true) {
                interleavedRow.push(list1[i][j]);
                interleavedRow.push(list2[i][j]);
            } else {
                interleavedRow.push(list2[i][j]);
                interleavedRow.push(list1[i][j]);
            }
        }
        flag = !flag; // toggle the flag after processing each row
        resultList.push(interleavedRow);
    }

    // Print the result list
    console.log(resultList);
}

function areListsSameDimensions(list1, list2) {
    if (list1.length !== list2.length) {
        return false;
    }

    for (let i = 0; i < list1.length; i++) {
        if (list1[i].length !== list2[i].length) {
            return false;
        }
    }

    return true;
}

// Example usage with different dimensions
const list1 = [[1, 1, 1], [1, 1, 1], [1, 1, 1],[1,1,1]];
const list2 = [[0, 0, 0], [0, 0, 0], [0, 0, 0],[0,0,0]];

interleaveLists(list1, list2);
