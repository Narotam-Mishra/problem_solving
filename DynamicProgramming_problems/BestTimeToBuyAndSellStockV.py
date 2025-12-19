
# Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/

def maximumProfit(prices, k):
    n = len(prices)
    
    NEG_INF = float('-inf')
    
    # initialize memoization table
    memo = [[[None for _ in range(3)] for _ in range(k + 1)] for _ in range(n)]
    
    def solveRec(i, k, c):
        # base case: no more transactions left or no more days left
        if i >= n:
            if c == 0:
                return 0
            # unfinished transaction: transaction is invalid
            return NEG_INF
        
        # memoization check
        if memo[i][k][c] is not None:
            return memo[i][k][c]
        
        # recursive case: 
        skip = solveRec(i + 1, k, c)
        take = NEG_INF
        if k > 0:
            if c == 1:
                # normal transaction
                take = prices[i] + solveRec(i + 1, k - 1, 0)
            elif c == 2:
                # short sell, you have to buy later
                take = -prices[i] + solveRec(i + 1, k - 1, 0)
            else:
                # fresh transaction: buy-sell or short sell-buy
                take = max(
                    -prices[i] + solveRec(i + 1, k, 1), # buy-sell (normal transaction)
                    prices[i] + solveRec(i + 1, k, 2) # short sell-buy
                )
        
        memo[i][k][c] = max(skip, take)
        return memo[i][k][c]
    
    return solveRec(0, k, 0)

# test case
# prices = [1,7,9,8,2]
# k = 2

prices = [12,16,19,19,8,1,19,13,9]
k = 3
print(maximumProfit(prices, k))