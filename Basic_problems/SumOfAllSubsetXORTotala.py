
# Problem link : https://leetcode.com/problems/sum-of-all-subset-xor-totals/

from typing import List

def subsetXORSum(nums: List[int]) -> int:
    total_sum = 0
    n = len(nums)

    for num in nums:
        total_sum |= num

    return total_sum << (n - 1)

arr = [3, 4, 5, 6, 7, 8]
print(subsetXORSum(arr))