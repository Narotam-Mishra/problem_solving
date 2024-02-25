
// Problem link - https://leetcode.com/problems/multiply-strings/description/

// Approach - 1 (using general multiplication method)
// TC - O(n^2)

let multiply = function(num1, num2) {
    const l1 = num1.length;
    const l2 = num2.length;

    // initialize product Array 'productArr'with 0  
    const productArr = new Array(l1+l2).fill(0);

    // now use multiplication algorithm
    for(let i=l1-1; i>=0; i--){
        for(let j=l2-1; j>=0; j--){
            // Calculate positions in the product array
            let p1 = i + j;
            let p2 = i + j + 1;

            // Calculate the product of current digits and add to the ongoing sum
            let mul = parseInt(num1[i]) * parseInt(num2[j]);
            let sum = mul + productArr[p2];

            // Update product array and carry over if necessary
            productArr[p1] += Math.floor(sum/10);
            productArr[p2] = sum % 10;
        }
    }

    // Remove leading zeros
    while(productArr.length > 0 && productArr[0] === 0){
        productArr.shift();
    }

    // return product Array as string
    return productArr.length ? productArr.join('') : '0';
};