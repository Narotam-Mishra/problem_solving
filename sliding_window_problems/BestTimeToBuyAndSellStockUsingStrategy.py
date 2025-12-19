
# Problem link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-using-strategy/

from typing import List

def maxProfit(prices: List[int], strategy: List[int], k: int) -> int:
    # step 1 - find profit for each stock price and strategy
    n = len(prices)
    profit = [0] * n
    actualProfit = 0
    for i in range(n):
        profit[i] = prices[i] * strategy[i]
        actualProfit += profit[i]

    # keep track of maximum original window profit
    originalWindowProfit = 0

    # keep track of maximum modified window profit
    modifiedWindowProfit = 0

    # keep track of maximum profit for each window
    maxGain = 0

    # using sliding window approach
    i = 0
    j = 0
    while j < n:
        originalWindowProfit += profit[j]

        # step 2 - find modified window profit using second half of window
        if j - i + 1 > k // 2:
            modifiedWindowProfit += prices[j]

        # check if window size exceed `k`
        if j - i + 1 > k:
            # shrink window
            originalWindowProfit -= profit[i]
            if i + k // 2 < n:
                modifiedWindowProfit -= prices[i + k // 2]
            i += 1

        # step 3 - find maximum profit in window of size `k`
        if j - i + 1 == k:
            maxGain = max(maxGain, modifiedWindowProfit - originalWindowProfit)

        # move to next window
        j += 1

    # step 4 - return maximum profit
    return actualProfit + maxGain

# test case 1 
# prices = [4,2,8]
# strategy = [-1,0,1]
# k = 2

# test case - 2
prices = [5,4,3]
strategy = [1,1,0]
k = 2
print(maxProfit(prices, strategy, k))