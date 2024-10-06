
# Problem link : https://leetcode.com/problems/climbing-stairs/


def climbStairs(n: int) -> int:
    # use a memo to store results for already computed values
    memo = {}

    # inner helper function to handle recursion
    def helper(n):
        if n == 1:  # base case: 1 way to climb 1 step
            return 1
        if n == 2:  # base case: 2 ways to climb 2 steps
            return 2
        if n in memo:  # return cached result if available
            return memo[n]
            
        # recursively calculate and store result
        memo[n] = helper(n - 1) + helper(n - 2)
        return memo[n]
        
    return helper(n)  # start recursion from the given n

n = 3
print(climbStairs(n))