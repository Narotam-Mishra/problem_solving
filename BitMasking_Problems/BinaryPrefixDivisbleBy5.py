
# Problem link : https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=problem-list-v2&envId=bit-manipulation

from typing import List

def prefixesDivBy5(nums: List[int]) -> List[bool]:
    res = []
    num = 0

    for i in range(len(nums)):
        # incrementally build the binary number modulo 5
        num = (num * 2 + nums[i]) % 5

        # check if divisible by 5
        if num == 0:
            res.append(True)
        else:
            res.append(False)

    return res

nums = [0, 1, 1]
print(prefixesDivBy5(nums))