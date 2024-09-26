
# Problem link : https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

# utility method to count set bits in a binary number
def count_set_bits(num):
    set_bits = 0
    while num > 0:
        set_bits += num & 1
        num = num >> 1
    return set_bits

# utility method to check if an array is sorted or not
def is_sorted(nums):
    for i in range(1, len(nums)):
        if nums[i - 1] > nums[i]:
            return False
    return True

def canSortArray(nums: List[int]) -> bool:
    n = len(nums)
    
    # outer loop for passes
    for i in range(n - 1):
        # inner loop for comparisons in each pass
        for j in range(n - i - 1):
            # if adjacent elements can be swapped and are in wrong order
            if count_set_bits(nums[j]) == count_set_bits(nums[j + 1]) and nums[j] > nums[j + 1]:
                # swap elements
                nums[j], nums[j + 1] = nums[j + 1], nums[j]

    # check if array can be sorted or not
    return is_sorted(nums)

# Test cases
# nums = [8, 4, 2, 30, 15]
# nums = [3, 16, 8, 4, 2]
# nums = [1, 2, 3, 4, 5]
nums = [136, 256, 10]
# nums = [20, 16]

print(canSortArray(nums))  # Output: False
