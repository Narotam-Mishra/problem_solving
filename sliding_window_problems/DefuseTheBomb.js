
// Problem link : https://leetcode.com/problems/defuse-the-bomb/description/

let decrypt1 = function(code, k) {
    let res = [];
    let n = code.length;

    if(k === 0) {
        return new Array(n).fill(0);
    }else if(k > 0) {
        for(let i = 0; i < n; i++) {
            let sum = 0;
            for(let j = 1; j <= k; j++) {
                sum += code[(i+j)%n];
            }
            res.push(sum);
        }
    }else{
        for(let i = 0; i < n; i++) {
            let sum = 0;
            for(let j = 1; j <= Math.abs(k); j++) {
                sum += code[(i-j+n)%n];
            }
            res.push(sum);
        }
    }
    return res;
};

let decrypt = function(code, k) {
    const n = code.length;

    // edge case:
    if(k === 0) return new Array(n).fill(0);

    // `res` array to store decrypted code
    const res = new Array(n).fill(0);

    // find the direction of summation based on `k`
    const direction = k > 0 ? 1 : -1;

    // determine number of elements to sum
    const steps = Math.abs(k);

    for(let i=0; i<n; i++){
        // `sum` to store running sum
        let sum = 0;
        for(let j=1; j<=steps; j++){
            // calculate the index of the element to sum using modular arithmetic
            const idx = (i + j * direction + n) % n;
            sum += code[idx];
        }
        // store computed sum in result `res` array
        res[i] = sum;
    }

    // return `res` result array
    return res;
};

// const code = [5,7,1,4], k = 3;

// const code = [1, 2, 3, 4], k = 0;

const code = [2, 4, 9, 3], k = -2;
console.log(decrypt(code, k)); 
