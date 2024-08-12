
## Problem link : https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

from typing import List

def sumOddLengthSubarrays(arr: List[int]) -> int:
    totalSum = 0
    n = len(arr)

    ## iterate on each array's element
    for i in range(n):
        ## the total number of subarrays that include arr[i]
        subarrays_count = (i + 1) * (n - i)

        ## the number of odd-length subarrays that include arr[i]
        odd_length_subarrays_count = (subarrays_count + 1) // 2

        ## add to the total sum the contribution of arr[i]
        totalSum += arr[i] * odd_length_subarrays_count
    
    return totalSum

# Example use
arr = [1, 4, 2, 5, 3]
print(sumOddLengthSubarrays(arr)) 
