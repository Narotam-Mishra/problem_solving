
# Problem link : https://leetcode.com/problems/maximum-strong-pair-xor-i/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List
def maximumStrongPairXor(nums: List[int]) -> int:
    # intialize `maxXor` to 0 to store result
    max_xor = 0

    # iterate on each pairs
    for i in range(0,len(nums)):
        for j in range(i+1, len(nums)):
            # check strong pair condition
            if abs(nums[i] - nums[j]) <= min(nums[i], nums[j]):
                # calculate XOR and find maximum XOR value
                max_xor = max(max_xor, nums[i] ^ nums[j])

    # return `maxXor` value
    return max_xor

# nums = [1, 2, 3, 4, 5]

# nums = [10, 100]

nums = [5, 6, 25, 30]
print(maximumStrongPairXor(nums))