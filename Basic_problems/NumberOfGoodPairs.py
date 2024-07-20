
## Problem link - https://leetcode.com/problems/number-of-good-pairs/

from typing import List

def numIdenticalPairs(nums: List[int]) -> int:
    count = 0
    freq = {}

    for num in nums:
        if num in freq:
            count += freq[num]
            freq[num] += 1
        else:
            freq[num] = 1
    return count

def numIdenticalPairs1(nums: List[int]) -> int:
    count = 0
    for i in range(len(nums)):
        for j in range(i+1, len(nums)):
            if nums[i] == nums[j]:
                count += 1
    return count

test_nums = [1, 2, 3, 1, 1, 3]
print(f"Number of good pairs: {numIdenticalPairs(test_nums)}")