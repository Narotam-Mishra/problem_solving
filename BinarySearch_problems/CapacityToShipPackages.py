
## Problem link - https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/

from typing import List

def can_ship_mid_packages_within_d_days(arr: List[int], mid: int, days: int) -> bool:
    dc = 0
    rWSum = 0

    for weight in arr:
        if rWSum + weight > mid:
            dc += 1
            rWSum = 0
        rWSum += weight

    # increment day counter, dc for last running weight sum, rWSum    
    dc += 1
    return dc <= days

def shipWithinDays(weights: List[int], days: int) -> int:
    maxWeight = -1
    totalWeight = 0
    for w in weights:
        maxWeight = max(maxWeight, w)
        totalWeight += w
    
    ## since we may not load more weight than the maximum weight capacity of the ship.
    ## hence search space will be from low = maxweight to high = totalWeight
    low = maxWeight
    high = totalWeight
    ans = -1
    while low <= high:
        mid = low + (high - low)//2
        if(can_ship_mid_packages_within_d_days(weights, mid, days)):
            # found first probable answer, ans
            ans = mid
            # since we have to find least capacity weight
            # hence we discard the right half of search space
            high = mid - 1
        else:
            # otherwise discard left half of search space
            low = mid + 1
        
    return ans

weights = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
days = 5
result = shipWithinDays(weights, days)
print(result)

