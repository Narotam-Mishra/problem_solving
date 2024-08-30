
## Problem link : https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=top-100-liked

from typing import List

def productExceptSelf(nums: List[int]) -> List[int]:
    size = len(nums)
    ans_arr = [1] * size

    # compute left product
    left_product = 1
    for i in range(size):
        ans_arr[i] = left_product
        left_product *= nums[i]

    # compute right product and combine it with left product
    right_product = 1
    for i in range(size-1, -1, -1):
        ans_arr[i] *= right_product
        right_product *= nums[i]

    return ans_arr

arr = [1, 2, 3, 4]
print(productExceptSelf(arr))