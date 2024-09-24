
# Problem link : https://leetcode.com/problems/single-number-ii/description/

from typing import List
def singleNumber(nums: List[int]) -> int:
    res = 0
    # iterate through each 32-bit positions
    for i in range(32):
        # count will keep track of the count of 1s at the i-th bit position
        count = 0
        # create mask where i-th bit is set
        mask = (1 << i)

        # iterate through all numbers in array
        for num in nums:
            # check if the i-th bit is set in the current number 'num'
            if (num & mask) != 0:
                # increment count
                count += 1

        # after couting, check if the sum is not divisible by 3 
        # it means that the unique number has the i-th bit set       
        if count % 3 != 0:
            # If we are dealing with a negative number and i is the most significant bit (31st bit),
            # we need to handle negative numbers in Python (since Python integers can be arbitrarily large)
            if i == 31:
                res -= mask  # Set the sign bit for negative numbers
            else:
                res |= mask  # Set the i-th bit in the result
    
    return res

nums = [2, 2, 3, 2]
print(singleNumber(nums))