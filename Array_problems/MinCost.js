
/*

You are given an array of itegers value. Find the minimum cost to remove all elements from the array. The cost to remove any one element is equal to the sum of elements at that point of time in array. 

*/

function findMinimumCost(arr){
    let totalSum = 0;
    // Calculate the total sum of the array
    for(let i=0; i<arr.length; i++){
        totalSum += arr[i];
    }

    // sort the array in descending order
    arr.sort((a,b) => b-a);

    // Iterate through the array and calculate the cost to remove each element
    let cost = 0;
    for(let i=0; i<arr.length; i++){
        // Add the current element's value to the total cost
        cost += totalSum;
        // Update the total sum by subtracting the current element's value
        totalSum -= arr[i];
    }
    return cost;
}

let arr = [4,1,6];
console.log(findMinimumCost(arr));