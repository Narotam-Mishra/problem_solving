
# Problem link :- https://leetcode.com/problems/total-hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def totalHammingDistance(nums: List[int]) -> int:
    thdSum = 0
    n = len(nums)

    # iterate over each bit position (0 to 31)
    for i in range(32):
        ones = 0

        # count how many numbers have a 1 at bit position i
        for num in nums:
            ones += (num >> i) & 1

        # number of zeros at this bit position
        zeroes = n - ones

        # contribution of this bit position to total Hamming distance
        thdSum += (ones * zeroes)
    
    return thdSum

# nums = [4, 14, 2]

nums = [4, 14, 4]
print(totalHammingDistance(nums))

        