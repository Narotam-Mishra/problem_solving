
# Problem link : https://leetcode.com/problems/max-consecutive-ones/description/

from typing import List

def findMaxConsecutiveOnes(nums: List[int]) -> int:
    maxOnes = counter = 0

    # iterate each numbers
    for i in range(len(nums)):
        # count ones
        if nums[i] == 1:
            counter += 1
            # find maximum ones
            maxOnes = max(counter, maxOnes)
        else:
            counter = 0
    return maxOnes

test_nums = [1,1,0,1,1,1]
print(f"Maximum Consecutive ones: {findMaxConsecutiveOnes(test_nums)}")