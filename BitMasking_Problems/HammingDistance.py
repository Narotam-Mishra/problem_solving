
## Problem link : https://leetcode.com/problems/hamming-distance/description/?envType=problem-list-v2&envId=bit-manipulation

def hammingDistance(x: int, y: int) -> int:
    ## XOR the two numbers. The result will have bits set to 1 where x and y have different bits.
    xor = x ^ y
    
    ## initialize a counter to keep track of the number of different bits
    dist = 0

    ## loop through all bits in the XOR result
    while(xor > 0):
        # increment the counter if the least significant bit is 1
        dist += xor & 1

        # right shift the XOR result by 1 to check the next bit
        xor = xor >> 1
    
    return dist

x = 1
y = 4
print(hammingDistance(x, y))