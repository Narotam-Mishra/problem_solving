

function multiplyStrings(num1, num2) {
    // Get the lengths of the input strings
    const m = num1.length;
    const n = num2.length;

    // Create an array to store the product, initialized with zeros
    const product = new Array(m + n).fill(0);

    // Perform long multiplication algorithm
    for (let i = m - 1; i >= 0; i--) {
        for (let j = n - 1; j >= 0; j--) {
            // Calculate positions in the product array
            const p1 = i + j;
            const p2 = i + j + 1;

            // Calculate the product of current digits and add to the ongoing sum
            const mul = parseInt(num1[i]) * parseInt(num2[j]);
            const sum = mul + product[p2];

            // Update product array and carry over if necessary
            product[p1] += Math.floor(sum / 10);
            product[p2] = sum % 10;
        }
    }
    console.log("Product Array:",product);

    // Remove leading zeros
    while (product.length > 1 && product[0] === 0) {
        product.shift();
    }

    // Return the product as a string
    return product.length ? product.join('') : '0';
}

// Example usage:
const num1 = "123";
const num2 = "456";
console.log(multiplyStrings(num1, num2)); // Output: "56088"
