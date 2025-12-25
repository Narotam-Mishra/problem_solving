
# Problem link - https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2025-12-25

import heapq
from typing import List

def maximumHappinessSum(happiness: List[int], k: int) -> int:
    # step 1 - max-heap using negative values
    max_heap = [-h for h in happiness]
    heapq.heapify(max_heap)

    # store final result in `res`
    res = 0

    # step 2 - keep track of number of child picked in `count` till now
    count = 0
    for _ in range(k):
        # get maximum happiness value from heap
        hap_val = -heapq.heappop(max_heap)

        # step 3 - calculate maximum possible happiness value
        res += max(0, hap_val - count)
        
        # increment count as we have picked one child
        count += 1

    # step 4 - return the maximum sum of the happiness values from `res`
    return res

# happiness = [1,2,3]
# k = 2

# happiness = [1,1,1,1]
# k = 2

happiness = [2,3,4,5]
k = 1
print(maximumHappinessSum(happiness, k))
