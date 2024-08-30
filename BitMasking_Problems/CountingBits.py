
## Problem link : https://leetcode.com/problems/counting-bits/description/

from typing import List

def countBits(n: int) -> List[int]:
    res = [0] * (n + 1)

    # Loop through all numbers from 0 to n
    for i in range(n+1):
        num = i
        # reset setBits counter for each number
        setBits = 0

        # count the number of 1's in the binary representation of num
        while(num > 0):
            # increment if the least significant bit is 1
            setBits += num & 1
            # right shift num by 1 bit
            num = num >> 1
        
        res[i] = setBits

    return res

num = 5
res = countBits(num)
print(res)