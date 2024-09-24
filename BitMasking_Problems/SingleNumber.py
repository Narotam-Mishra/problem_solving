
# Problem link : https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List
def singleNumber(nums: List[int]) -> int:
    res = 0
    for num in nums:
        res ^= num
    return res

# nums = [2, 2, 1]

nums = [4,1,2,1,2]
print(singleNumber(nums))