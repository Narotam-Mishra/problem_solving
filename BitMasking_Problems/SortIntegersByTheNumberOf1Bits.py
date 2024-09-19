
# Problem link : https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def count_set_bits(num):
    count = 0
    while num > 0:
        count += num & 1
        num = num >> 1
    return count

def sortByBits(arr: List[int]) -> List[int]:
    return sorted(arr, key=lambda num: (count_set_bits(num), num))

nums = [0, 1, 2, 3, 4, 5, 6, 7, 8]
print(sortByBits(nums))