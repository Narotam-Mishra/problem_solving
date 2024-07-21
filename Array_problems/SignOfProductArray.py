
## Problem link - https://leetcode.com/problems/sign-of-the-product-of-an-array/

from typing import List

def arraySign(nums: List[int]) -> int:
    countNegatives = 0
    for num in nums:
        if num == 0:
            return 0
        elif num < 0:
            countNegatives += 1
    return 1 if countNegatives % 2 == 0 else -1

nums = [-1, -2, -3, -4, 3, 2, 1]
result = arraySign(nums)
print(f"The sign of the product of {nums} is {result}")

nums = [1, 5, 0, 2, -3]
result = arraySign(nums)
print(f"The sign of the product of {nums} is {result}")

nums = [-1, 2, -3, 4, -5]
result = arraySign(nums)
print(f"The sign of the product of {nums} is {result}")