
## Problem link : https://leetcode.com/problems/binary-number-with-alternating-bits/description/?envType=problem-list-v2&envId=bit-manipulation

def hasAlternatingBits(n: int) -> bool:
    # XOR the number with its right-shifted version by 1 bit.
    # this helps to check if adjacent bits are different.
    x = (n >> 1) ^ n

    # check if the result of the XOR operation is a sequence of all 1s.
    # adding 1 to such a sequence would give a number with exactly one 1 bit followed by all 0s.
    # if x & (x + 1) results in 0, then the number had alternating bits.
    ans = (x & (x+1)) == 0
    return ans

# num = 5

num = 7
print(hasAlternatingBits(num))