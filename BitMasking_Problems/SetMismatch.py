
# Problem link :- https://leetcode.com/problems/set-mismatch/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def findErrorNums(nums: List[int]) -> List[int]:
    # sort the array to make it easier to spot the duplicate
    nums.sort()

    # initialize with default values
    duplicate_num = -1
    missing_num = -1
    n = len(nums)

    # iterate through the sorted array to find the duplicate number
    for i in range(1, len(nums)):
        if nums[i-1] == nums[i]:
            # find duplicate
            duplicate_num = nums[i]

    # calculate the expected sum of numbers from 1 to n
    exp_sum = n * (n + 1) // 2

    # calculate the actual sum of the array with the duplicate
    act_sum = sum(nums)

    # missing number = expected sum - (actual sum - duplicate number)
    missing_num = exp_sum - (act_sum - duplicate_num)
    
    return [duplicate_num, missing_num]

# Example usage
# nums = [1, 2, 2, 4]

# nums = [1, 1]

nums = [2, 2]
print(findErrorNums(nums))