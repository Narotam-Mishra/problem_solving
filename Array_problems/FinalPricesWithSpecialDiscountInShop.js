
// Problem link - https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=problem-list-v2&envId=array

// Brute FOrce Approach
let finalPrices1 = function(prices) {
    // store answer in `res` array
    const res = []

    // step 1 - for each item in the shop
    const n = prices.length;
    for(let i=0; i<n; i++){
        // intially there is no discount
        let discount = 0;

        // step 2 - look for the first item to the right with price <= current price
        for(let j=i+1; j<n; j++){
            // step 3 - found discount
            if(prices[j] <= prices[i]){
                // take only first discount
                discount = prices[j];
                break;
            }
        }

        // step 4 - calculate the discounted price
        res[i] = prices[i] - discount;
    }

    // step 5 - return resultant discount array `res`
    return res;
};

let finalPrices = function(prices) {
    // start with original prices
    const res = [...prices]

    // stack to store indices
    const stack = [];

    // step 1 - process each item from left to right
    const n = prices.length;
    for(let i=0; i<n; i++){
        // get top from stack
        let top = stack[stack.length-1];
        // step 2 - while stack is not emppty and current price can give discount
        while(stack.length > 0 && prices[i] <= prices[top]){
            // pop index that can get discount from current item
            let index = stack.pop();

            // step 3 - apply discount: original price - discount amount
            res[index] = prices[index] - prices[i];
        }

        // step 4 - push current index to stack (it might receive discount later)
        stack.push(i);
    }

    // step 5 - return resultant discount array `res`
    return res;
};


const prices = [8,4,6,2,3];

// const prices = [1,2,3,4,5];

// const prices = [10,1,1,6];
console.log(finalPrices(prices));