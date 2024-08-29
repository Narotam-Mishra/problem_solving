
## Problem link : https://leetcode.com/problems/majority-element/?envType=study-plan-v2&envId=top-100-liked

from typing import List

def majorityElement(nums: List[int]) -> int:
    reqNum = nums[0]
    count = 1

    for i in range(1, len(nums)):
        if(nums[i] == reqNum):
            count += 1
        else:
            count -= 1
            if(count == 0):
                reqNum = nums[i]
                count = 1

    return reqNum

arr = [2,2,1,1,1,2,2]
print(majorityElement(arr))