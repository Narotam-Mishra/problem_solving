
## Problem link - https://leetcode.com/problems/range-sum-query-immutable/description/

from typing import List

class NumArray:

    def __init__(self, nums: List[int]):
        self.nums = nums

    def sumRange(self, left: int, right: int) -> int:
        getSum = 0
        for i in range(left, right+1):
            getSum += self.nums[i]
        return getSum
    
# main method
if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5]
    numArray = NumArray(nums)

    # Test the sumRange method
    print(numArray.sumRange(0, 2))  # Output: 6 (1 + 2 + 3)
    print(numArray.sumRange(1, 3))  # Output: 9 (2 + 3 + 4)
    print(numArray.sumRange(2, 4))  # Output: 12 (3 + 4 + 5)
        