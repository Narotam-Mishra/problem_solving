
// Objective: Compare sequential and concurrent execution patterns in handling Promises.

/*

Task - Given an array of URLs (simulated as functions that return Promises), write two functions:

1). fetchSequentially(urls) : This function should fetch data from the URLs one after the other, waiting for each fetch to complete before starting the next. Measure and log the total time taken to complete all fetches.

2). fetchConcurrently(urls) : This function should initiate all fetches at once and wait for all of them to complete. Measure and log the total time taken to complete all fetches.

For both functions, simulate the fetch operation with a function that returns a Promise resolving after a random delay (1 to 3 seconds)

Criteria for success:
1). Implement both fetching strategies correctly.
2). Use console.time and console.timeEnd to measure execution time.
3). Understand and explain why the times differ between the two approaches.

*/