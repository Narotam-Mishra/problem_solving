
# Problem link - https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice/description/?envType=problem-list-v2&envId=bit-manipulation\

from typing import List

def duplicateNumbersXOR(nums: List[int]) -> int:
    # sort the array in non-decreasing order
    nums.sort()

    # initialize the XOR result as 0
    xor_res = 0

    # traverse through the sorted array and check for duplicates
    i = 1
    while i < len(nums):
        # if the current number is the same as the previous one, XOR it with the result
        if nums[i] == nums[i-1]:
            xor_res ^= nums[i]
            # skip the next element as it's already considered a duplicate
            i += 2
        else:
            i += 1
    
    # return xor result 'xor_res'
    return xor_res

nums = [1, 2, 1, 3]
print(duplicateNumbersXOR(nums))