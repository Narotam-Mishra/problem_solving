
// Problem link - https://leetcode.com/problems/maximal-rectangle/description/?envType=daily-question&envId=2026-01-11

// utility function to find NSR (Next Smaller to Right)
function findNSR(height) {
    const n = height.length;
    const st = [];
    const nsr = new Array(n);

    for (let i = n - 1; i >= 0; i--) {
        if (st.length === 0) {
            nsr[i] = n;
        } else {
            while (st.length > 0 && height[st[st.length - 1]] >= height[i]) {
                st.pop();
            }

            if (st.length === 0) {
                nsr[i] = n;
            } else {
                nsr[i] = st[st.length - 1];
            }
        }
        st.push(i);
    }

    return nsr;
}

// utility function to find NSL (Next Smaller to Left)
function findNSL(height) {
    const n = height.length;
    const st = [];
    const nsl = new Array(n);

    for (let i = 0; i < n; i++) {
        if (st.length === 0) {
            nsl[i] = -1;
        } else {
            while (st.length > 0 && height[st[st.length - 1]] >= height[i]) {
                st.pop();
            }

            if (st.length === 0) {
                nsl[i] = -1;
            } else {
                nsl[i] = st[st.length - 1];
            }
        }
        st.push(i);
    }

    return nsl;
}

// utility function to find maximum area
function findMaxArea(height) {
    // width --> NSR[i] - NSL[i] - 1
    // height -> height[i]

    // find NSR
    const NSR = findNSR(height);

    // find NSL
    const NSL = findNSL(height);

    // find width
    const n = height.length;
    const width = new Array(n);
    for (let i = 0; i < n; i++) {
        width[i] = NSR[i] - NSL[i] - 1;
    }

    // find maximum area
    let maxArea = 0;
    for (let i = 0; i < n; i++) {
        const area = width[i] * height[i];
        maxArea = Math.max(maxArea, area);
    }
    return maxArea;
}

function maximalRectangle(matrix) {
    const m = matrix.length;
    const n = matrix[0].length;

    // step 1 - find height of 1st rectangle
    const height = new Array(n);
    for (let i = 0; i < n; i++) {
        height[i] = matrix[0][i] === '1' ? 1 : 0;
    }

    // step 2 - find maximum area for 1st row
    let maxArea = findMaxArea(height);

    // step 3 - find height of remaining rectangles
    for (let r = 1; r < m; r++) {
        for (let c = 0; c < n; c++) {
            if (matrix[r][c] === '0') {
                height[c] = 0;
            } else {
                height[c] += 1;
            }
        }

        // step 4 - updated maximum area
        maxArea = Math.max(maxArea, findMaxArea(height));
    }

    // step 5 - return maximum area
    return maxArea;
}

// const matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]];

// const matrix = [["0"]];

const matrix = [["1"]];
console.log(maximalRectangle(matrix));