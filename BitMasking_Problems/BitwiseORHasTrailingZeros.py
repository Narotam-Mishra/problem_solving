
# Problem link : https://leetcode.com/problems/check-if-bitwise-or-has-trailing-zeros/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def hasTrailingZeros(nums: List[int]) -> bool:
    count = 0
    for num in nums:
        if (num & 1) != 1:
            count += 1
    return count>= 2

# nums = [1, 2, 3, 4, 5]

nums = [1, 3, 5, 7, 9]
print(hasTrailingZeros(nums))
