
# Problem link : https://leetcode.com/problems/number-of-even-and-odd-bits/description/?envType=problem-list-v2&envId=bit-manipulation&status=TO_DO&difficulty=EASY

from typing import List
def evenOddBit(n: int) -> List[int]:
    curr_bit = 0
    pos = 0

    # initialize counters for even and odd positions
    even_cnt = 0
    odd_cnt = 0  
    
    # iterate through all bits of n until n becomes zero
    while n > 0:
        # isolate the least significant bit (LSB) by performing bitwise AND with 1
        curr_bit = n & 1
        
        # if the current bit is 1, check its position and update the respective counter
        if curr_bit == 1:
            if pos & 1:
                # if position is odd (pos & 1 equals 1), increment odd_cnt
                odd_cnt += 1
            else:
                # if position is even (pos & 1 equals 0), increment even_cnt
                even_cnt += 1
        
        # right-shift n to process the next bit in the next iteration
        n = n >> 1
        
        # increment the bit position counter
        pos += 1
    
    # return the counts of 1's at even and odd positions
    return [even_cnt, odd_cnt]

# example usage
# n = 11  # Binary: 1011

n = 50
print(evenOddBit(n)) 
