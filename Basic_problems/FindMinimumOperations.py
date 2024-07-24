
## Problem link - https://leetcode.com/problems/find-minimum-operations-to-make-all-elements-divisible-by-three/description/

from typing import List


def minimumOperations(nums: List[int]) -> int:
    count1 = 0
    count2 = 0

    for num in nums:
        remainder = num % 3
        if remainder == 1:
            count1 += 1
        elif remainder == 2:
            count2 += 1
    ans = min(count1, count2) * 2 + abs(count1 - count2)
    return ans

# Example usage:
nums = [1, 2, 3, 4]
print(minimumOperations(nums))